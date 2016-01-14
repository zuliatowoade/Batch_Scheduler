DESIGN DOCUMENT FOR LAB 1

QUESTION 1: Process Creator

PURPOSE: To show how a number of children forked from a parent can be used.

SPECIAL CONDITIONS NEEDED
	* None

HIGH LEVEL ENTITIES/DESIGN DECISIONS:
	* The purpose of the block of code indicated as block1 is to fork the child and then the grandchild. Two pid_t values are used, one for the child and one for the grandchild. The fork for the grandchild
	  is done inside of the child's process. The grandchild then waits for 10 seconds and then prints. After this, the child waits for the grandchild to finish before it prints.
	  
	* The purpose of the block of code indicated as block2 is to have the parent wait for its child to finish before printing. It follows the same procedure that the child did when it waits for its child to finish. 
	  
	  
USAGE:
	* Run gcc lab1_1.c -o lab1_1 (make sure you have a c compiler)
	* Then run ./lab1_1
	* The program then runs according to the specification
	
ASSUMPTIONS:
	* None

	
	
	
QUESTION 2: Process Terminator

PURPOSE: To act as a process kill function, where an entered process ID is killed if the user has the correct privileges and if it exists.

SPECIAL CONDITIONS NEEDED
	* None

HIGH LEVEL ENTITIES/DESIGN DECISIONS:
	* The purpose of the block of code indicated as block1 is to prompt the user for an integer value. This value is then stored into an int called pid. The system call kill is then called with this value passed.
	  Depending on what happens with this call either Killing is printed or the corresponding error message is printed. The program then ends, returning the value that kill is equal to.
	  
	  
USAGE:
	* Run gcc lab1_2.c -o lab1_2 (make sure you have a c compiler)
	* Then run ./lab1_2
	* The program promts the user to enter the ID of a process to terminate
	* The program then either prints a success message or an error message
	
ASSUMPTIONS:
	* The user is expected to enter an integer value that represents the ID of a process.

	
	
	
QUESTION 3: Batch Scheduler

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