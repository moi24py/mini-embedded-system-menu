#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for POSIX API, read()

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

    // Numbers buffer
    int numbers[200];
    // Sentence buffer
    char sentence[200];

    print_menu();

    int chosen_opt = choice();

    // Check if the option is valid
    if ( (chosen_opt < 1) || (chosen_opt > 3)){
        perror("The selected option is invalid. Only is 1, 2 or 3 are legit");
        return 1;
    }

    switch (chosen_opt) {
        // TODO
        case 1:
            printf("Insert number: \n");
            // if (read() == -1){
            //    perror("Cannot read from stdin");
            //    break;
            //}
       
        case 2:
            printf("Insert a sentence: \n");
            fflush(stdout);
            if (fgets(sentence, 200, stdin) != NULL){
                printf("Your sentence:\n%s\n", sentence);
                break;
            }
            else{
                perror("Cannot read from standard input");
                return 1;
            };

        case 3:
            printf("Bye bye\n");
            return 0;
    
        default:
            break;
    }

    return 0;
}