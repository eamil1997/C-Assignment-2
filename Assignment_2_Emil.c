/* Assignment: 2
Campus: Beer Sheva
Author: Emil ***********, ID: *********
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check_input();
void prototypeMenu();
void MagicLetters();
void GuessGame();
void PatternPrint();
int PrimeNum();
int PalindromeNum();
void PrimePalindromeScavangerHunter();



void prototypeMenu(){      // This is the MENU.
    printf("\nMenu:\n");
    printf("Please choose an option:\n");
    printf("1 - Magic letters\n");
    printf("2 - The guessing game\n");
    printf("3 - Pattern print\n");
    printf("4 - Prime Palindrome scavenger hunt\n");
    printf("5 - Exit\n\n");


}

int check_input() {      // Checks if the input is valid in the menu.
    int num;
    scanf("%d", &num);
    while(!(num >0 && num <=5)){
        printf("Please enter a valid choice!\n");
        scanf("%d", &num);
    }
    return num;
}

void MagicLetters(){      //The magic letters game - you choose 2 different alphabetical letters and it will make a descending pyramide, try and see.
    char option1, option2, temp;
    int i, middle;
    getchar();
    printf("Please enter two alphabetical characters:\n");
    scanf("%c %c",&option1, &option2);

    while(((option1<'a' || option1>'z') && (option1<'A' || option1>'Z')) && ((option2<'a' || option2>'z') && (option2<'A'||option2>'Z'))){ // A check for a valid characters.
        printf("Please enter a valid character.\n");
        scanf("%c %c",&option1, &option2);
    }
    if (option1 >= 'A' && option1 <='Z'){ // Swaps between the bigger letters to the smaller letters. if the input is A and Z so the letters will become a and z.
        option1 +=32;
    }
    if (option2 >= 'A' && option2 <='Z'){
        option2 +=32;
    }
    if(option1 >option2){           // Checks who is bigger and swaps them in the correct order.
        temp = option1;
        option1 = option2;
        option2 = temp;
    }
    middle = (int)(option2-option1); //The loop prints letters from the smaller letter(1st) to the last letter(2nd) and it will print all letter between those two letters in ascending order.
    for(i = 0; i<= middle; i++){
        for(char i = option1; i<= option2; i++) {
            printf("%c%c ", option1, i);
        }
        printf("\n");
        option1++;
    }

}

void GuessGame(){
    char option;
    int num1,num2,try, guess;
    getchar();
    printf("Would you like to start a new game? (Y/N)\n");
    scanf("%c", &option);
    while((option != 'Y' && option != 'y') && (option != 'N' && option != 'n')){
        getchar();
        printf("Would you like to start a new game? (Y/N)\n");
        scanf("%c", &option);
    }
    if (option == 'N'|| option == 'n'){
        printf("Sorry to see you go!\n");
        return;
    }
    printf("Enter a number\n");
    scanf("%d", &num1);
    printf("Enter a number\n");
    scanf("%d", &num2);
    if(num1 >num2){           //checks who is bigger
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    do{
        printf("Enter the number of guesses you would like to make [2-10] : \n");
        scanf("%d",&try );
    }while(try >10 || try <2);

    int value = (rand() % (num2 - num1 + 1)) + num1;
    printf("Enter your guess (you have %d guesses left) : \n", try);
    scanf("%d", &guess);

    while(try>1){
        if(guess<num1||guess>num2){
            printf("Invalid guess – not in the required range [%d-%d]\n", num1, num2);
            try--;
            printf("Enter your guess (you have %d guesses left) : \n", try);
            scanf("%d", &guess);
        }
        else if(guess<value){
            try--;
            printf("Enter a higher number (you have %d guesses left) : \n", try);
            scanf("%d", &guess);
        }
        else if(guess>value){
            try--;
            printf("Enter a lower number (you have %d guesses left) : \n", try);
            scanf("%d", &guess);
        }
        if(guess==value){
            printf("Congratulations – you have won !\n\n");
            return;
        }

    }
    printf("Game is over , unsuccessful attempts !\n\n");

}

void PatternPrint(){
int number;
    printf("Please choose a number between [1-60]: \n");
    scanf("%d", &number);
while(!(number > 0 && number <= 60)){
    printf("Please enter a valid choice! [1-60]: \n");
    scanf("%d", &number);

}
    printf("+");
            for(int i=0;i<=number;i++)
                printf("-", i);

    printf("+\n");

        for(int row=0; row<number; row++) {     //
            printf(":");
            for (int col = 0; col < number - row; col++) {
                printf("X");
            }

            printf(" ");
            for (int o = 0; o < row; o++) {

                printf("0");
            }




            printf(":\n");


}
    printf("+");
    for(int i=0;i<=number;i++)
        printf("-", i);
    printf("+");

    printf("\n\n");
}

int PrimeNum(int prime){
    for(int i = 2; i < prime; i++){

        if(prime%i==0)
            return 0;
    }

    return 1;

}

int PalindromeNum(int palindrome){
    int temp = 0, sum = palindrome;

        while(sum>0){

            temp = temp * 10;
            temp = (sum % 10) + temp;
            sum = sum / 10;
        }
        if(temp == palindrome)
            return 1;
        return 0;

    }

void PrimePalindromeScavangerHunter(){
    int num1, num2;
    printf("Please enter a range between two positive integer numbers to find all Palindrome Prime numbers.\n");
    printf("(Tip: Take big numbers):\n");
    scanf("%d%d", &num1, &num2);

    if(num1>num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    for(int i = num1; i <= num2; i++)
        if (PrimeNum(i) && PalindromeNum(i))
             printf("%d \n", i);

    printf("\n");

    }


int main(){
    int choice;
    srand((unsigned int) time(NULL)); // Initialization of random
    do{
        prototypeMenu();            //func to print menu
        choice = check_input();         //func that deals with input
        switch (choice) {
            case 1:
                MagicLetters();
                break;
            case 2:
                GuessGame();
                break;
            case 3:
                PatternPrint();
                break;
            case 4:
                PrimePalindromeScavangerHunter();
                break;
            case 5:
                printf("Have a great day & see you soon!\n");
                break;

        }
    }        while(choice !=5);
    return 0;
}
