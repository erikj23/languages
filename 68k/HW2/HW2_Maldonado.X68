*-----------------------------------------------------------
* Title      :Homework 2
* Written by :Erik Maldonado
* Date       :4/20/18
* Description:Program does what the professor asked.
*-----------------------------------------------------------
            org     $1000           ;program starts at $1000

cr          equ     $0d
lf          equ     $0a

start:                      
*-----------setup
*test        lea     Prompt,a1
*            move.b  #14,d0
*            trap    #15
*            
*            move.b  #4,d0
*            trap    #15
*            move.l  d1,d4
            
            
            movea.l #$a000,a0       ;move LONG address $0000 a000 into register a0
            move.w  #$beef,(a0)     ;move WORD data $#beef into the memory location 
                                    ;a0 is storing register                               
            movea.l #$6000,a1       ;move LONG address $0000 6000 into register a1
            movea.l #$8000,a2       ;move LONG address $0000 8000 into register a2
            jsr     sub_read
            jsr     sub_add
            jmp     print
        
sub_read:   *read 6000-8000 
loop_read   cmpa.l  a1,a2          ;compare LONG data in register a1 to register a2
            beq.s   exit_read1          ;branch to e_read1 if equal
            move.b  (a1)+,d0       ;move BYTE data into register d0 and increment
*-----------compare bytes               ;register a1 by 1 byte
            cmp.b   (a0),d0        ;compare BYTE data in at memory location stored
*-----------if not equal                ;in register a0 to register d0
            bne.s   loop_read      ;branch back to r_read if not equal to repeat the
*-----------if equals                   ;process
            move.l  a1,Addr1       ;move LONG data from register a1 into Addr1
            bra.s   exit_read2          ;short branch to e_read2
exit_read1  movea.l #$6000,a1      ;move LONG address $0000 6000 into a1
            move.l  a1,Addr1       ;move LONG data fom a1 into Addr1
exit_read2  rts

sub_add:    *add 256 bytes to d1
            clr     d0              
            clr     d1
            clr     d2
            clr     CarryBit
            for d0 = #1 to #256 do.s    ;loop 256 times
                move.b  (a1)+,d2    ;move BYTE data into d2
                add.w   d2,d1       ;add WORD data into d1 and increment a1
                bcs     add_bit     ;branch if the c flag is set
            endf
            move.w  d1,Addsum
exit_add    rts
            
add_bit     move.b  #1,CarryBit     ;add BYTE data to CarryBit
            bra.s   exit_add        ;branch to lab_back1
    
print       lea     Addr_msg,a1
            move.b  #14,d0
            trap    #15

            clr     d1
            move.l  Addr1,d1        ;
            move.b  #16,d2
            move.b  #15,d0
            trap    #15            

            lea     Adds_msg,a1
            move.b  #14,d0
            trap    #15

            clr     d1
            move.w  Addsum,d1
            move.b  #16,d2
            move.b  #15,d0
            trap    #15
            
            lea     Bits_msg,a1
            move.b  #14,d0
            trap    #15
            
            clr     d1
            move.b  CarryBit,d1
            move.b  #16,d2
            move.b  #15,d0
            trap    #15
           
Addr1       ds.l    1
Addsum      ds.w    1
CarryBit    ds.b    1

Prompt      dc.b    'Enter a number of bytes to add :',0
Addr_msg    dc.w    'Address    :',0
Adds_msg    dc.b    cr,lf,'Add sum    :',0
Bits_msg    dc.b    cr,lf,'Carry      :',0

            end start






*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
