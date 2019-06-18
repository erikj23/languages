*-----------------------------------------------------------
* Title      :Q4
* Written by :CSS422
* Date       :6 April 2018
* Description:Analyzing memory.
*-----------------------------------------------------------

*-------equates
addr1   equ $4000
addr2   equ $4001
data2   equ $a7ff
data3   equ $5555
data4   equ $0000           isn't this unreadable memory?
data5   equ 4678
data6   equ %01001111
data7   equ %00010111

*-------begining
    org    $400
start   move.w  #data2,d0   load 16 bits of immediate data from data2 into register d0
        move.b  #data6,d1   load 8 bits of immediate data from data6 into register d1
        move.b  #data7,d2   load 8 bits of immediate data from data7 into register d2
        move.w  #data3,d3   load 16 bits of immediate date from data3 into register d3
        movea.w #addr1,a0   load 16 bits of immediate data from addr1 into register a0
        
        *transfers byte into memory?
        move.b  d1,(a0)+    load 8 bits from d1 into ?
        *transfers another byte into a0?
        move.b  d2,(a0)+    load 8 bits from d2 into ?
        
        movea.w #addr1,a1   load 16 bits of immediate data from addr1 into register a1
        *logical and
        and.w   d3,(a1)     does () mean 'value of'?
        
        jmp     start
        
        end    $400
        

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
