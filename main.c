#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "library.h"
#include <signal.h>
#include "pipe_networking.h"

static void sighandler(int signo) { // prevents ctrl + c from exiting entire program. Allows usage of ctrl c to skip song.
    if (signo == SIGINT) {
        printf(" To exit client, type exit.\n");
        remove(WKP);
    }
        
}

int main() { 

	signal(SIGINT, sighandler);
	int to_client;
	int from_client;
	char clientmsg[BUFFERSIZE];


	struct song_node *a;
	struct song_node *b;

    struct song_node ** library = allocate();

    library = add_song(library, "dna", "kendrick lamar"); // base songs
    library = add_song(library, "alright", "kendrick lamar");
    library = add_song(library, "excuse me", "asap rocky");
    library = add_song(library, "dont look back in anger", "oasis");
    library = add_song(library, "marvins room", "drake");
    library = add_song(library, "cigarette daydreams", "cage the elephant");
    library = add_song(library, "everyday", "ariana grande");
    library = add_song(library, "a lot", "21 savage");
    
    int i;
    char input[BUFFERSIZE];
    char input2[BUFFERSIZE];
    char *song;
    char *artist;
    DIR* directory;
    
    printf("\n\nInstructions: Type command followed by enter. Case-insensitive. \nCommands:\n - Add Song\n - Remove Song\n - Clear Library\n - Print Library\n - Save Library\n - Load Library\n - Play Song \n - Allow Connections \n - Exit\n - Help");
    while (1) { // constantly prompts user
    	printf("\n\n > ");

    	fgets(input, BUFFERSIZE, stdin); // reads from stdin

    	for (i = 0; i < BUFFERSIZE; i++) // allows for case insensitivity
    		input[i] = tolower(input[i]);
    	

        if (!strcmp(input,"print library\n"))
            print_library(library);


    	else if (!strcmp(input,"add song\n")) {
    		printf("Input format: Song Name-Artist\n\n > ");
            fgets(input2, BUFFERSIZE, stdin);
            input2[strlen(input2)-1] = 0; //get rid of newline
            for (i = 0; i < BUFFERSIZE; i++) // allows for case insensitivity
    		input2[i] = tolower(input2[i]);


            artist = input2; 
            song = strsep(&artist, "-"); // split string to add to library
            library = add_song(library, song, artist);
            printf("Success! Added %s by %s to library.\n", song, artist);
        }
        
        
        else if (!strcmp(input,"remove song\n")) { // similar to add song
    		printf("Input format: Song Name-Artist\n\n > ");
            fgets(input2, BUFFERSIZE, stdin);
            input2[strlen(input2)-1] = 0; 
            for (i = 0; i < BUFFERSIZE; i++)
    		input2[i] = tolower(input2[i]);
    		

            artist = input2;
            song = strsep(&artist, "-");
         
            library = delete_song(library, song, artist);
        }
        

    	else if (!strcmp(input,"clear library\n"))
    		clear_all(library);
        
        
        else if (!strcmp(input, "save library\n"))
            save_library(library);


        else if (!strcmp(input, "load library\n")) {

            printf("Binary file name? Leave blank for the default library.bin \n\n > "); 
            fgets(input2, BUFFERSIZE, stdin);
            if ( *input2 == '\n') { // for default
            	load_library("library.bin", library);     	
            }
            else {
            input2[strlen(input2)-1] = 0;
            load_library(input2, library);
            }
        }


        else if (!strcmp(input,"play song\n")) {
        
        	directory = opendir(".");
        	struct dirent *entry;
        	printf("Available Songs:");
        	while (entry = readdir( directory )) { // prints available files that can be played (mp3 and wav files)
        		char* c = entry->d_name;
        		if (!strcmp(&entry->d_name[strlen(c)-3],"mp3") || !strcmp(&entry->d_name[strlen(c)-3],"wav"))
        			printf("\n%s", c);
        	}
        	
       	
        	printf("\n > "); // looks for user input
                fgets(input2, BUFFERSIZE, stdin);
                input2[strlen(input2)-1] = 0;
                
             	int j = fork();
             	
                if (j == 0) { // forks and execs basic music player, requires forking as exec replaces entire process
                	char* argument_array[3] = {"play", input2, NULL};
                	execvp("play", argument_array);
                	return 0;         
                	}     
                	
                if (j != 0) {
                	int status;
                	wait(&status);               	        		
                }                      
        }
        
        else if (!strcmp(input,"allow connections\n")) { // this allows for clients to connect to the library and add their songs
        	save_library(library); 
        	while (1) {
        		printf("Exit? Yes or No. Answer before each connection.\n > ");
        		fgets(input2, BUFFERSIZE, stdin); // due to signal handling, can't exit with ctrl c so this prompt will allow for exiting.
        		if (!strcmp(input2,"Yes\n") || !strcmp(input2, "yes\n")) {
        		       load_library("library.bin",library);
        			break;
        		}
        		
    			from_client = server_setup();
    			printf("[server]: Creating subserver\n");
    			int b = fork();
   
    			if (b == 0) {
      				to_client = server_connect(from_client); // subservers wait for clients to connect

      				while (1) {
        				read(from_client, clientmsg, BUFFER_SIZE); // read in song request from client
        				printf("Processing.\n");
        				clientmsg[strlen(clientmsg)-1] = 0; 
            				for (i = 0; i < BUFFERSIZE; i++) 
    						clientmsg[i] = tolower(clientmsg[i]);

            				artist = clientmsg;
            				song = strsep(&artist, "-"); // split string and song
            				library = add_song(library, song, artist); // add song to the library of the child process
            				printf("Successfully added %s by %s to library.\n", song, artist);
        				write(to_client, "Thank you! Song successfully added.", BUFFER_SIZE);      
        				save_library(library); // instead of using pipes to communicate between parent and forked child process (lots of blocking confusion) , wrote to the bin file instead
      			}
      			
      			return 0;
    			}		
  		}
  		remove(WKP);
  		}

        


	else if (!strcmp(input,"exit\n")) { // since ctrl c doesn't exit
		exit(0);
		remove(WKP); 
	}
	
	else if (!strcmp(input, "help\n")) 
	{printf("\n\nInstructions: Type command followed by enter. Case-insensitive. \nCommands:\n - Add Song\n - Remove Song\n - Clear Library\n - Print Library\n - Save Library\n - Load Library\n - Play Song \n - Allow Connections \n - Exit\n - Help");
	
	}
        else printf("Error: Invalid input, read list of commands and try again.");
            
        }

}