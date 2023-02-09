#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
//Defining simple text colour for Making colorful console
#define RED "\e[0;91m"
#define GREEN "\e[0;92m"
#define YELLOW "\e[0;93m"
#define BLUE "\e[0;94m"
#define PURPLE "\e[0;95m"
#define CYAN "\e[0;96m"
#define WHITE "\e[0;97m"
//Defining Bold text colour for Making Bold colorful console text
#define BOLD_RED "\e[1;31m"
#define BOLD_GREEN "\e[1;32m"
#define BOLD_YELLOW "\e[1;33m"
#define BOLD_BLUE "\e[1;34m"
#define BOLD_PURPLE "\e[1;35m"
#define BOLD_CYAN "\e[1;36m"
#define BOLD_WHITE "\e[1;37m"
//defining to reset the console text colour
#define reset "\e[0m"
//Function for the Rule of the Game
void game_rule();
//Function to generate the Random number matrix
void random_matrix(int []);
//Function to display matrix
void display_matrix(int []);
//The Playground for the user where game takes place
void game_play(char str[]);
//This is main function
int main()
{
    system("cls");
    char name[20];
    printf(YELLOW"Hello user, Please enter your name:-  "reset);
    scanf("%s",name);
    system("cls");
    
    printf(BOLD_YELLOW"--------------------------------------------Welcome To Shuduko, \"%s\" --------------------------------------------",name);
    printf(reset);
    game_rule();
    printf("Enter any digit to continue:- ");
    getch();
    system("cls");   
    game_play(name);
    printf("\n\n\n");
    printf("Enter any key to Confirm \"Exit\"");
    getch();
    return 0;
}
//The Playground for the user where game takes place
void game_play(char name[])
{
    int attempt = 1000, i, j, swap; 
    printf(BOLD_YELLOW"Welcome To the Game - "reset);
    printf(BOLD_PURPLE"%s\n\n",name);
    printf(reset);
    printf(RED"\n                   You have "reset);
    printf(BOLD_PURPLE"%d",attempt);
    printf(RED" attempt Left.... \n"reset);  
    int matrix[16];
    random_matrix(matrix);
    display_matrix(matrix);
    while(attempt>0)
    {
        char move = getch();
        system("cls");
        if(move=='e'||move=='E'||move=='C'||move=='c')
        {
            attempt=0;
        }
        //For LEFT Key
        else if(move==75)
        {
            for(i=1; i<16; i++)
            {
                if(matrix[i]=='\0' && i%4!=0)
                {
                    swap = matrix[i];
                    matrix[i] = matrix[i-1];
                    matrix[i-1] = swap;
                    attempt--;
                    break;
                }
            }
        }
        //For UP Key
        else if(move==72)
        {
            for(i=4; i<16; i++)
            {
                if(matrix[i]=='\0')
                {
                    swap = matrix[i];
                    matrix[i] = matrix[i-4];
                    matrix[i-4] = swap;
                    attempt--;
                    break;
                }
            }
        }
        //For RIGHT Key
        else if(move==77)
        {
            for(i=0; i<16; i++)
            {
                if(matrix[i]=='\0' && (i+1)%4!=0)
                {
                    swap = matrix[i];
                    matrix[i] = matrix[i+1];
                    matrix[i+1] = swap;
                    attempt--;
                    break;
                }
            }
        }
        //For DOWN Key
        else if(move==80)
        {
            for(i=0; i<(16-4); i++)
            {
                if(matrix[i]=='\0')
                {
                    swap = matrix[i];
                    matrix[i] = matrix[i+4];
                    matrix[i+4] = swap;
                    attempt--;
                    break;
                }
            }
        }
        printf(BOLD_YELLOW"Welcome To the Game - "reset);
        printf(BOLD_PURPLE"%s\n\n",name);
        printf(reset);
        printf(RED"\n                   You have "reset);
        printf(BOLD_PURPLE"%d",attempt);
        printf(RED" attempt Left.... \n"reset);
        display_matrix(matrix);
        printf(BOLD_CYAN"\n\n\n             NOTE- \nif You you have completed the game enter 'c' or 'C'"reset);
    } 
    char matrix2[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,'\0'};
    for(i=0; i<16; i++)
    {
        if(matrix[i]!=matrix2[i])
        {
            break;;
        }
    }
    system("cls");
    if(i==16)
    {
        printf(BOLD_YELLOW"                                 YOU WIN!"reset);
    }  
    else
    {
        printf(BOLD_YELLOW"                                      YOU LOSE! \n                                Better Luck Next Time"reset);        
    }
}
//Function for the Rule of the Game
void game_rule()
{
    printf("\n");
    printf(BOLD_WHITE"        GIVEN MATRIX      \n"reset);
    int matrix[16];
    random_matrix(matrix);
    printf(RED);
    display_matrix(matrix);
    printf(reset);
    printf(BOLD_WHITE"     WINNING CONDITION       \n"reset);
    int arr_matrix[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,'\0'};
    printf(RED);
    display_matrix(arr_matrix);
    printf(reset);
    printf(BOLD_WHITE"------------------------------RULE OF THE GAME------------------------------\n"reset);
    printf(RED);
    printf("1. You can move only 1 step at a time with the arrow key.\n");
    printf("    Move UP     : by Up arrow key\n");
    printf("    Move DOWN   : by Down arrow key\n");
    printf("    Move LEFT   : by Left arrow key\n");
    printf("    Move RIGHT  : by Right arrow key\n");
    printf("2. You can move numbers at an empty position only.\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n");
    printf("4. You can exit the Game at any time by Entering 'E' or 'e'\n");
    printf("\n\n");
}
//Function to generate the Random number matrix
void random_matrix(int arr[16])
{
    int i, j, temp;
    srand(time(NULL));
    for(i=0; i<16; i++)
    {
        if(i==15)
        {
            arr[i]='\0';
        }
        else
        {
            temp = rand()%15+1;
            for(j=0; j<i; j++)
            {
                if(temp==arr[j])
                {
                    break;
                }
            }
            if(j==i)
            {
                arr[i]=temp;
            }
            else
            {
                i--;
            }
        }
    }
}
//Function to display matrix
void display_matrix(int arr[16])
{
    int i, count=0;
    printf("------------------------\n");
    for(i=0; i<16; i++)
    {       
        if(arr[i]=='\0')
        {
            printf("|    |");
            count++;
        }
        else
        {
            if(arr[i]<10)
                printf("| %d  |",arr[i]);
            else
                printf("| %d |",arr[i]);
            count++;
        }
        if(count%4==0)
        {
            printf("\n");
            printf("------------------------\n");
        }
    }
    printf("------------------------\n");
}