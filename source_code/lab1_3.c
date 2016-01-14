#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h>


int main(int argc, char **argv) {

  while(1){
    printf("\n");
    printf("batch-shell> ");


    char program_string[100];   //initializing the size of the string to get from user
    if (strcmp((fgets(program_string,sizeof program_string,stdin)), "quit\n") == 0)     //stores user input in the variable program_string
      exit(0);
    
    
	//Block1-----Tokenize the user input (string of programs to run)
	char ** array= NULL;     //initializing that array that would hold values when program_string is tokenized
    int count = 0;
    char *s = " \n";   //this delimiter that would be used to tokenize (split and added to an array) the user input
	char *program = strtok(program_string, s);
	
    while (program) {
      array = realloc (array, ++count * sizeof (char));    //incrementing the size of the array by counter++. since we do not know the number of programs
                                                          //blindly assigning array a size would be waste of memory space so we increment the size of array by one anytime we 
                                                         //need to add another program to array
      if( program != NULL){      
        array[count-1] = program;      //placing program at array-size minus 1
        printf("program: %s\n", array[count-1]);
      }
      program = strtok(NULL, s);      //trying to get the next token 
    }



    //Block2------- looping through the list of programs to run. Each child process is
    //created while the parents waits for the children to run 
    int i;
    for(i =0 ; i<= count ; i++){
      if(array[i] != NULL){
      	if (strcmp(array[i], "quit") == 0){
      		exit(0);
      	}
      	else{
        	printf("\n");            //an extra line for formatting purpose
        	printf("Running %s .......\n", array[i]);
        	pid_t pid = fork();
        	if(pid == 0){      //child process
	  			printf("Process ID %d\n", getpid());     //prints the process number and Id
	  			execlp(array[i], array[i], (char*)0);         //runs the process using the exec function
	  			printf ("Sorry, there was an error the program %s could not run\n\n", array[i]);    //this line is only reached if there was an error running the process
	  		exit(0);       //child exits
        	}
  			else if (pid < 0){        //an error occur during the fork process
	  			perror("fork error");    //prints fork error 
        	}
        
			else{      //parent process waits for all processes
	  			wait(NULL);
			}
      }
    }


  }
  }}