#include<stdio.h>
#include<stdlib.h>
#include <time.h>


main()
{
    srand(time(NULL));

    printf("========Let's Play Rock Paper Scissor========\n\n");

    printf("Select:\n\n");
    printf("1.Rock\n");
    printf("2.Paper\n");
    printf("3.Scissor\n");

    int player_choice;

    printf("\n\nEnter a choice: ");
    scanf("%d", &player_choice);

    int computer_choice = rand()%3 + 1;
    printf("\n\Computer choice: %d", computer_choice);

    if(player_choice == computer_choice)
    {
        printf("\nTie!");
    }
    if((player_choice == 1 && computer_choice == 2) || (player_choice == 2 && computer_choice == 3) || (player_choice == 3 && computer_choice == 1))
    {
        printf("\nComputer wins!\n");
    }
    else
    {
        printf("\nPlayer wins!\n");
    }

}
