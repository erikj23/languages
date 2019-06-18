*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
*---problem1
    move.l  #$025c30f7,d0
    move.b  #$90,d0
    move.b  #$f7,d0
    move.w  #$90,d0
    
*---reset
*---problem2
    move.w  #$30f7,d0
    moveq   #$12,d0
    moveq   #$82,d0
    
*---reset
*---problem3
    move.w  #$2012,$1234
    move.b  $1235,d1
*---error
*---move.w  $1235,d1

*---reset
*---problem4
    move.w  #$ab10,$1234
    move.l  #$025c30f7,d0
    movea.l #$12345678,a1
    
    movea.w #$1234,a1
    move.w  (a1),d0
    
    movea.w $1234,a1
    move.w  (a1),d0

    movea.w #$1235,a1
*---error
*---move.w (a1),d0
    
*---error
*---movea.w $1235,a1
    move.w  (a1),d0

* Put variables and constants here

    END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
