#include<stdio.h>
#include<string.h>


int menu()
{
    printf("Menu\n");
    printf("1.SignUp");
    printf("\n2.Login");
    printf("\n3.Forgot Password");
    printf("\n4.Delete account\n");



    int user_choice;
    printf("Make a choice: ");
    scanf("%d", &user_choice);

    return user_choice;

}


void SignUp()
{
    char username[50];
    char password[50];
    char security_question[200];
    char security_answer[50];

    printf("\n\nEnter username: ");
    scanf("%s", username);

    printf("\nEnter password: ");
    scanf("%s", password);

    printf("\nEnter a question: ");
    scanf(" %s", security_question);

    printf("\nEnter answer: ");
    scanf(" %s", security_answer);

    FILE *SaveFile;
    SaveFile = fopen("User_details.txt", "w");

    if (SaveFile == NULL)
    {
        printf("Error opening file!\n");
        return; // Exit the function if file opening fails
    }

    fprintf(SaveFile, "%s\n", username);
    fprintf(SaveFile, "%s\n", password);
    fprintf(SaveFile, "%s\n", security_question);
    fprintf(SaveFile, "%s\n", security_answer);


    fclose(SaveFile);
}

compare_credentials(char entered_username[], char entered_password[])
{
    char username[50];
    char password[50];

    FILE *SaveFile;
    SaveFile = fopen("User_details.txt", "r");

    if (SaveFile == NULL)
    {
        printf("Error opening file!\n");
        return; // Exit the function if file opening fails
    }


    //fscanf(SaveFile, "%s\n", password);


    while(fscanf(SaveFile, "%s\n %s\n", username, password)!=EOF)
    {
        if (strcmp(username, entered_username) == 0 && strcmp(password, entered_password) == 0)
        {
            return 1;
            //fclose(SaveFile); // Credentials match
        }
    }

    fclose(SaveFile);
    return 0;


}

Login()
{
    char entered_username[50];
    char entered_password[50];

    printf("Enter Username: ");
    scanf("%s", entered_username);

    printf("\nEnter password: ");
    scanf("%s",  entered_password);

    int result = compare_credentials(entered_username, entered_password);

    if (result)
    {
        printf("Login Successful\n");
    }
    else
    {
        printf("Incorrect username or password!\n");
    }
}

void Forgot()
{
    char username[50];
    //char password[50];
    char saved_username[50];
    char saved_password[50];
    char security_question[200];
    char saved_answer[50];
    char entered_answer[50];

    printf("Enter the registered username: ");
    scanf("%s", username);
    int result=0;


    FILE *SaveFile;
    SaveFile = fopen("User_details.txt", "r");

    if (SaveFile == NULL)
    {
        printf("Error opening file!\n");
        return; // Exit the function if file opening fails
    }

    while(fscanf(SaveFile, "%s\n %s\n %s\n %s\n", saved_username, saved_password, security_question, saved_answer) != EOF)
    {
        if(strcmp(username,saved_username)==0)
        {
            result = 1;
            printf("\nSecurity question: %s", security_question);
            printf("\nEnter answer: ");
            scanf(" %s", entered_answer);

            if(strcmp(saved_answer,entered_answer) == 0)
            {
                char new_password[50];
                printf("\nEnter new password: ");
                scanf(" %s", new_password);

                fclose(SaveFile);

                SaveFile = fopen("User_details.txt", "r");


                FILE *tempfile;

                tempfile = fopen("temp.txt", "w");

                if(tempfile == NULL)
                {
                    printf("\nError creating file");
                    fclose(SaveFile);
                    return;
                }

                while(fscanf(SaveFile, "%s\n %s\n %s\n %s\n", saved_username, saved_password, security_question, saved_answer) != EOF)
                {
                    if(strcmp(username, saved_username)==0)
                    {
                        fprintf(tempfile, "%s\n", saved_username);
                        fprintf(tempfile, "%s\n", new_password);
                        fprintf(tempfile, "%s\n", security_question);
                        fprintf(tempfile, "%s\n", saved_answer);
                    }
                }

                fclose(SaveFile);
                fclose(tempfile);

                remove("User_details.txt");
                rename("temp.txt", "User_details.txt");

                printf("\nPassword updated successfully.\n");
                return;

            }

            else
            {
                printf("\nIncorrect answer to security question.\n");
                fclose(SaveFile);
                return;
            }
        }
    }

    fclose(SaveFile);

    if(!result)
    {
        printf("\nUsername not found.\n");
    }

}


int main()
{
    switch (menu())
    {
    case 1:
        SignUp();
        break;
    case 2:
        Login();
        break;
    case 3:
        Forgot();
        break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}

