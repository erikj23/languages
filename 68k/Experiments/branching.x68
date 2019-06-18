*------------------------------------------------------------------------------
* Program		:Branching
* Written by	:Erik Maldonado
* Date			:4 March 2018
* Description	:Branching program for experimentation.
*------------------------------------------------------------------------------

START	ORG		$1000

*-------Output
LOOP	LEA 	MESSAGE,A1
		MOVE.B	#14,D0
		TRAP	#15

*-------Input
		MOVE.B	#4,D0			Trap task 4 reads a number from the keyboard 
		TRAP	#15				into  D1.L
		CMP.L	#0,D1			Compares D1 to the number 0
		BEQ		DONE			Branch to DONE if equal
		
		CMP.B	#0,D1			Compares D1 to 0
		BLT		INVALID			BLT branches if D1 is less than 0
		CMP.B	#9,D1			Compares D1 to 1
		BGT		INVALID			BGT branches if D1 is greater than 9
		
*		BRA		LOOP			Branch to LOOP

*-------Compute input

		CMP.B	#1,D1			Compares D1 and 1
		BNE		TWO				BEQ branches if D1 and 1 are not equal
		LEA 	MER,A1		
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP

TWO		CMP.B	#2,D1			Compares D1 and 1
		BNE		THREE			BEQ branches if D1 and 2 are not equal
		LEA 	VEN,A1		
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP
		
THREE 	CMP.B	#3,D1
		BNE		FOUR
		LEA		EAR,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP

FOUR	CMP.B	#4,D1
		BNE		FIVE
		LEA		MAR,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP
		
FIVE	CMP.B	#5,D1
		BNE		SIX
		LEA		JUP,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP
		
SIX		CMP.B	#6,D1
		BNE		SEVEN
		LEA		SAT,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP

SEVEN	CMP.B	#7,D1
		BNE		EIGHT
		LEA		URA,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP
		
EIGHT	CMP.B	#8,D1
		BNE		NINE
		LEA		NEP,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP
		
NINE	CMP.B	#9,D1
		LEA		PLU,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOP
		
INVALID	LEA		INV,A1			~Load effective address of INV into register A1
		MOVE.B	#14,D0			~Move input(#14) into register D0
		TRAP	#15				~Execute data in previous line
		BRA		LOOP
	
DONE	MOVE.B	#9,D0			Do not understand what this does
		TRAP	#15				

CR		EQU		$0D
LF		EQU		$0A
		
MESSAGE	DC.B	'Enter a number between 0 and 9, Enter 0 to exit: ',0
INV		DC.B	'That is not between 1 and 9',CR,LF,0
MER		DC.B	'Hello Mercury',CR,LF,0
VEN		DC.B	'Hello Venus',CR,LF,0
EAR		DC.B	'Hello Earth',CR,LF,0
MAR		DC.B	'Hello Mars',CR,LF,0
JUP		DC.B	'Hello Jupiter',CR,LF,0
SAT		DC.B	'Hello Saturn',CR,LF,0
URA		DC.B	'Hello Uranus',CR,LF,0
NEP		DC.B	'Hello Neptune',CR,LF,0
PLU		DC.B	'Pluto is not a plannet',CR,LF,0

		END		START
