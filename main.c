#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for POSIX API, read()
#include <ctype.h>

// Prints menu
void print_menu(){
    printf("\n---### MENU ###---\n");
    printf("\nHere are the options: \n");
    printf("1: Read numbers\n");
    printf("2: Read sentences\n");
    printf("3: Exit\n");
    printf("\nPlease, choose an option: ");
}

// Reads and returns user's choice
int choice(){
    // Read from stdin
    char opt[3];
    if ((fgets(opt, sizeof(opt), stdin)) != NULL){
        // Conversion from string to number
        char *endptr;
        long opt_num = strtol(opt, &endptr, 10);
        // Check conversion
        if (endptr == opt) {
            perror("Conversion from string to long failed");
            return -1;
        } else {
            // Return the option chosen by the user
            return opt_num;
        }
    }
    perror("Cannot read from standard input");
    return -1;
}


int main(){

    char buffer[200];
    // for read() returning value
    ssize_t read_bytes;

    print_menu();

    int chosen_opt = choice();

    // Checks if the option is valid
    if ( (chosen_opt < 1) || (chosen_opt > 3)){
        perror("The selected option is invalid. Only is 1, 2 or 3 are legit");
        return 1;
    }

    
    switch (chosen_opt) {
        // Reads and prints numbers from stdin
        case 1:
            printf("Insert number: \n");
            fflush(stdout);
            read_bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
            if (read_bytes < 0){
                perror("Cannot read from standard input");
                return -1;
            }
            buffer[read_bytes] = '\0'; // Adds string terminator
            // Process the input to extract numbers
            printf("You entered: ");
            for (int i = 0; i < read_bytes; i++) {
                // If that char is a digit
                if (isdigit(buffer[i])) {
                    // Print only one digit in stdout
                    putchar(buffer[i]);
                    if (!isdigit(buffer[i+1])){
                        putchar(32);
                    }
                }
            }
            printf("\n");
            return 0;
        
        // Reads and prints chars from stdin
        case 2:
            printf("Insert a sentence: \n");
            fflush(stdout);
            if (fgets(buffer, 200, stdin) != NULL){
                printf("Your sentence:\n%s\n", buffer);
                break;
            }
            else{
                perror("Cannot read from standard input");
                return 1;
            };
        
        // Exits the program
        case 3:
            printf("Bye bye\n");
            return 0;
    
        default:
            break;
    }

    return 0;
}