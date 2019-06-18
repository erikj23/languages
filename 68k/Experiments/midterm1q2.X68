*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------

addr    equ     $8000

start   org     $1000

        lea     addr,a3
        move.w  #$bcdf,-(a3)
        move.l  #$9856,-(a3)
        movea.w a3,a6
        movea.w #$5c7a,a5
        move.w  a5,d5
        move.w  #$11,d7
        rol.l   d7,d5
        move.w  (a3)+,d1
        move.l  (a3)+,d7
        eor.w   d7,d5
        move.w  d5,-(a3)
        move.w  (a3)+,d0

        end     start    
    


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
