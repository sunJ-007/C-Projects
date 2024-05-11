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
    scanf("%s", security_question);

    printf("\nEnter answer: ");
    scanf("%s", security_answer);

    FILE *SaveFile;
    SaveFile = fopen("User_details.txt", "w");

    if (SaveFile == NULL)
    {
        printf("Error opening file!\n");
        return; // Exit the function if file opening fails
    }

    fprintf(SaveFile, "%s\n", username);
    fprintf(SaveFile, "%s\n", password);

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


    while(fscanf(SaveFile, "%s %s", username, password)!=EOF)
    {
        if (strcmp(username, entered_username) == 0 && strcmp(password, entered_password) == 0)
        {
            return 1;
            fclose(SaveFile); // Credentials match
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
    scanf("%s", entered_password);

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
    char saved_username[50];
    printf("Enter the registered username");
    scanf("%s", username);
    int result=0;


    FILE *SaveFile;
    SaveFile = fopen("User_details.txt", "w");

    if (SaveFile == NULL)
    {
        printf("Error opening file!\n");
        return; // Exit the function if file opening fails
    }

    while(fscanf(SaveFile, "%s\n", saved_username) != EOF)
    {
        if(strcmp(username,saved_username)==0)
        {
            result = 1;
            printf("Enter a new password");
            fclose(SaveFile);
        }
    }

    fclose(SaveFile);


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
