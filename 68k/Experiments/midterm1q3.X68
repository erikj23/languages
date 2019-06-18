*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------

start   org     $1000

        lea     $b000,sp
        
        *filler
        movea.l #$00008000,a6
        *filler
        
        bge     loop
        move.b  $ffff9000,d4
        
        *filler
        movea.l #$00008000,a6
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        move.l #$00008000,$00008000
        *filler
        
loop
        move.b  #14,d0
        lea     msg,a1
        bra     loop
*loop        
        *filler
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        movea.w #$7000,a6
*       movea.w a6,a6
        *filler
        
        move.l  #$b2100,d1
        move.w  #$40,d7

        *filler
        move.w  d0,d0
        *filler

        movea.w #$b000,a3
        jsr     test
        
        *filler
        move.l  #$00008000,$7ffe
        *filler

done    stop    #2700

test    movem.w a3/d1/d7,-(sp)
        
        *filler
        move.l  #$00008000,$00008000
        move.l  #$00008000,$00008000
        move.l  #$7fff,d0
        *filler    
        
        movem.w (sp)+,a3/d1/d7
        
        rts
        
msg     dc.l    'word',0
        
        end     start    
    




*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
