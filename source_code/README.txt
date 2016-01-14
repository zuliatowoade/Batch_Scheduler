
TITLE: Batch Scheduler

PURPOSE: To accept a string containing the list of programs to schedule from the user and run each sequentially.

SPECIAL CONDITIONS NEEDED
	* None


HIGH LEVEL ENTITIES/DESIGN DECISIONS:
	* The purpose of the block of code indicated as block1 is to take the string the user enters and tokenize it and stores each word in the string
	  (program) in an array. Note that the size of the array containing all the programs to run is dynamically incremented as as the string is tokenized using the delimeter (" \n")
	  A list of all the programs to run is also printed out before they begin to run.
	  
	* The purpose of the block of code indicated as block2 is to loop through all the value (programs) in the array created in block one and run each program sequentially
	  Note that if one of the process is "quit". The program exits and every other program after it does not run since our code is assuming the user intends to exit out of the whole program. 
	  If "quit" comes at the end of the string, the main program exits all the programs runs. An error message is printed out if a certain program could not be executed by a process, and an error
	  printed out if the fork process failed.
	  
USAGE:
	* Run gcc lab1_3.c -o lab1_3 (make sure you have a c compiler)
	* Then run ./lab1_3
	* "batch-shell>" is shown and the user types in the programs to run with space in between them
	* The program then begins and the user can type in the string of programs to run
	* You can type quit to exit the shell when done
	
	
ASSUMPTIONS:
	* This program assumes that the the number of chars in the user input is not greater that 100 because the size of the variable for the user input was set to 100.
	* This program if the user intends to exit the program, the user types in "quit" and nothing else. if something other than "quit" is typed, it is run as a program.
	  and if such program does not exists, the process running it will print out an error message.
	* The execution command used in creating this program does not use the file PATH as a parameter so therefore, this program assumes that if a user wants to run a program .
	   (e.g a user defined program), the program resides in the same directory as our program or the program is written with its full path.
	* This program also assumes that the user known what to do after the program shows the prompt "batch-shell>".
