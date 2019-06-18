*------------------------------------------------------------------------------
* Program		:Hello World
* Written by	:Erik Maldonado
* Date			:4 March 2018
* Description	:Hello world program.
*------------------------------------------------------------------------------
START	ORG		$1000					START AT THIS ADRESS
	
*-------CODE FOR OUTPUT--------
		LEA		MESSAGE,A1				LOADS MESSAGE INTO ADDRESS REGISTER A1 
		MOVE.B	#14,D0					MOVES THE NUMBER 14 INTO DATA REGISTER 
		TRAP	#15						D0 DISPLAYS MESSAGE

		MOVE.B	#9,D0
		TRAP	#15						HALT SIMULATOR

CR		EQU		$0D						ASCII CODE FOR CARRIAGE RETURN
LF		EQU		$0A						ASCII CODE FOR LINE FEED

MESSAGE	DC.B	'Hello, My '			PLACE ASCII STRING IN MEMORY AT MESSAGE
		DC.B	'Name is Erik Maldonado',CR,LF,CR,LF
		DC.B	'This program took me a little longer than an hour.',CR,LF,CR,LF
		DC.B	'The readings are difficult to keep up with, there is a '
		DC.B	'lot of reading to do.',CR,LF
		DC.B	'I can do it if I work hard.',CR,LF,CR,LF
		DC.B	'Thank you for listening',0
		
		END 	START
