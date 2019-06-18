
            ORG         $1000
START:          
            move.w      d3,$0000a0000           ;move WORD data from d3 into LONG address
                                                    ;$0000a000
            move.b      $42b7,d2                ;move BYTE data from WORD address into d2
            move.b      $7000,d2                ;test
            movea.w     $7000,a7                ;move WORD address $7000 into a7
            add.w       d7,d0                   ;add WORD data from d7 to d0 and store in d0
            sub.b       d1,d2                   ;subtract BYTE data in d1 from d2
            
            *move.b     $a000,a3
            *add.b      #$1000,d2
            *movea.w    $1234,d0
            *andi.b     #23,#$100
            *subi.b     d3,%1000
            bra.w         lab_q3

    *-------setup for q3
sub_setup1:
            move.l      #$c198f382,d0
            move.l      #$00000001,d1
            rts
            
lab_q3      jsr         sub_setup1            
            asl.b       #3,d0
            
            jsr         sub_setup1
            asl.l       #4,d0
            
            jsr         sub_setup1
            lsr.b       #7,d0
            
            jsr         sub_setup1
            rol.w       #2,d0
            
            jsr         sub_setup1
            ror.l       #7,d0
    
            END         START        
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
