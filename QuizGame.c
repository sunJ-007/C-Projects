#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


main()
{

    char questions_data[200];
    char questions[50][200];
    char answers[50][200];
    char *token;
    int count = 0;

    FILE *Quiz = fopen("Q&A.txt","r");

    while(fgets(questions_data,sizeof(questions_data), Quiz)!= NULL)
    {
        token = strtok(questions_data,":");
        if(token !=NULL)
        {
            strcpy(questions[count],token);
            token = strtok(NULL, ":");
            if(token!=NULL)
            {
                strcpy(answers[count],token);
                //printf("Questions: %s\n", questions);
                //printf("Answers: %s\n", answers);
                count++;
            }
        }

    }

    fclose(Quiz);

    printf("Welcome To Quiz India!\n\n");
    int score = 0;
    char user_answer[50];


    for(int i=0; i<count; i++)
    {
        printf("\n%d.%s\n\n",i+1,questions[i]);

        printf("Enter your answer: ");
        fgets(user_answer,sizeof(user_answer),stdin);
        user_answer[strcspn(user_answer, "\n")] = '\0';

        //printf("Before conversion: %s\n", user_answer);
        for(int j=0; user_answer[j] != '\0'; j++)
        {
            user_answer[j] = toupper(user_answer[j]);
        }
        //printf("After conversion: %s\n", user_answer);

        for(int j=0; answers[i][j] != '\0'; j++)
        {
            answers[i][j] = toupper(answers[i][j]);
        }

        //user_answer[strcspn(user_answer, "\n")] = '\0'; // Remove newline character from user_answer
        answers[i][strcspn(answers[i], "\n")] = '\0';


        if(strcmp(user_answer, answers[i]) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect, the correct answer is: %s\n", answers[i]);
        }

    }

    printf("Your total score is: %d", score);


}
