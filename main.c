#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prints menu
void print_menu(){
    printf("### MENU ###\n");
    printf("1: Read numbers\n");
    printf("2: Read sentences\n");
    printf("3: Exit\n");
    printf("Choose an option: ");
}

// Reads user's choice
int choice(){
    char opt;
    scanf("%c", &opt);
    int int_opt = atoi(&opt);
    printf("You choose %d\n", int_opt);
    // Clean buffer
    while (getchar() != '\n');
    return int_opt;
}

int main(){
    char sentence[200];

    print_menu();
    int chosen_opt = choice();
    if ( (chosen_opt < 1) || (chosen_opt > 3)){
        perror("Only numbers between 1 and 3 are legit");
        return 1;
    }

    switch (chosen_opt)
    {
    case 2:
        printf("Insert a sentence: \n");
        fgets(sentence, 200, stdin);
        printf("%s\n", sentence);
        break;
    
    default:
        break;
    }


    return 0;
}

