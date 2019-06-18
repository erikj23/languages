*------------------------------------------------------------------------------
* Program		:Branching
* Written by	:Erik Maldonado
* Date			:4 March 2018
* Description	:Branching program for experimentation.
*------------------------------------------------------------------------------

START	ORG		$1000

*-------Defined
CR		EQU		$0D
LF		EQU		$0A
	
*-------Functions
LOOPMSG	LEA		MESSAGE,A1
		MOVE.B	#14,D0
		TRAP	#15

INPUT	MOVE.B	#4,D0
		TRAP	#15
		CMP.L	#1422384,D1
		BEQ		DONE
		
		CMP.B	#20,D1
		BLT		INVALID
		CMP.B	#25,D1
		BGT		INVALID
		
F20		CMP.B	#20,D1
		BNE		F21
		LEA		N20,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG
		
F21		CMP.B	#21,D1
		BNE		F22
		LEA		N21,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG

F22		CMP.B	#22,D1
		BNE		F23
		LEA		N22,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG

F23		CMP.B	#23,D1
		BNE		F24
		LEA		N23,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG
		
F24		CMP.B	#24,D1
		BNE		F25
		LEA		N24,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG
		
F25		CMP.B	#25,D1
		LEA		N25,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG
		
INVALID	LEA		OOB,A1
		MOVE.B	#14,D0
		TRAP	#15
		BRA		LOOPMSG

DONE	MOVE.B	#9,D0
		TRAP	#15

	
*-------Messages
MESSAGE	DC.B	'Enter a number 20 <= x <= 25',CR,LF,'>',0
OOB		DC.B	'Out of bounds',CR,LF,0
N20		DC.B	'Twenty inch rims',CR,LF,0
N21		DC.B	'Legal drinking age',CR,LF,0
N22		DC.B	'My age',CR,LF,0
N23		DC.B	'Famous shoe',CR,LF,0
N24		DC.B	'KOBE!',CR,LF,0
N25		DC.B	'!?EH-',CR,LF,0

		END 	START