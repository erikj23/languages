*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------

*-----------equates-----------------;comments-------------------
stack       equ     $a000               
example     equ     %1101111001100001
shift       equ     12              ;shift 12 bits

*-----------program
            ORG     $1000
START:      lea     stack,sp        ;load the stack pointer
            lea     jmp_table,a0    ;index into table
            clr.l   d0              ;zero it
            move.w  #example,d0     ;we will play here
            move.b  #shift,d1       ;shift 12 bits to the right
            lsr.w   d1,d0           ;move the bits
            *why do we multiply the next index by 6?
            mulu    #6,d0           ;form offset
            jsr     0(a0,d0)        ;jump indirect with index
        
jmp_table   jmp     code0000
            jmp     code0001
            jmp     code0011
            jmp     code0100
            jmp     code0101
            jmp     code0110
            jmp     code0111
            jmp     code1000
            jmp     code1001
            jmp     code1010
            jmp     code1011
            jmp     code1100
            jmp     code1101
            jmp     code1110
            jmp     code1111

*-------variables
code0000    stop    #$2700
code0001    stop    #$2700
code0010    stop    #$2700
code0011    stop    #$2700
code0100    stop    #$2700
code0101    stop    #$2700
code0110    stop    #$2700
code0111    stop    #$2700
code1000    stop    #$2700
code1001    stop    #$2700
code1010    stop    #$2700
code1011    stop    #$2700
code1100    stop    #$2700
code1101    stop    #$2700
code1110    stop    #$2700
code1111    stop    #$2700


    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
