#include<stdio.h>


struct customer_details
{
    char name[50];
    int acc_no;
    float Current_Balance;
    float deposits[100];
    float withdrawals[100];
    float transfers[100];
    int num_of_deposits;
    int num_of_withdrawal;
    int num_of_transfers;
};


main()
{
    FILE *SaveDetails;
    struct customer_details customer;
    int choice;
    char confirm = 'y';


    while(confirm == 'y' || confirm == 'Y')
    {

        printf("\n\nWelcome to Modi Bank\n\n");
        printf("==================Main Menu=================");
        printf("\n\n1.Create Account");
        printf("\n2.Account Details");
        printf("\n3.Deposit Money");
        printf("\n4.Withdraw Money");
        printf("\n5.Transfer Money");
        printf("\n6.Transaction Details");
        printf("\n7.Exit\n\n");


        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
        {

            printf("Enter Customer name: ");
            scanf("%s", customer.name);


            printf("Choose a number of your choice: ");
            scanf("%d", &customer.acc_no);

            customer.Current_Balance = 10000;


            SaveDetails = fopen("CustomerDetails.txt", "a+");
            if(SaveDetails == NULL)
            {
                printf("Error Opening File!\n");
                return 1;
            }

            fwrite(&customer, sizeof(struct customer_details), 1, SaveDetails);

            fclose(SaveDetails);
            break;

        }

        case 2:
        {
            int searchAccNo;
            int found = 0;
            //struct customer_details customer;

            printf("Enter account number: ");
            scanf("%d", &searchAccNo);

            SaveDetails = fopen("CustomerDetails.txt", "rb");
            if(SaveDetails == NULL)
            {
                printf("Error Opening File!\n");
                return 1;
            }

            while(fread(&customer, sizeof(struct customer_details),1,SaveDetails)==1)
            {
                if(customer.acc_no == searchAccNo)
                {
                    printf("\nCustomer Name: %s", customer.name);
                    printf("\nAccount number: %d", customer.acc_no);
                    printf("\nCurrent Balance: %.2f\n\n", customer.Current_Balance);
                    found = 1;
                    break;
                }
            }

            if(found==0)
            {
                printf("Account number not found");
            }
            break;

        }


        case 3:
        {
            int searchAccNo;
            int found = 0;
            customer.num_of_deposits = 0;

            // struct customer_details customer;

            printf("Enter account number: ");
            scanf("%d", &searchAccNo);

            float deposit_amount;

            printf("Enter the amount to deposit: ");
            scanf("%f", &deposit_amount);

            SaveDetails = fopen("CustomerDetails.txt", "rb+");
            if(SaveDetails == NULL)
            {
                printf("Error Opening File!\n");
                return 1;
            }

            while(fread(&customer, sizeof(struct customer_details),1,SaveDetails)==1)
            {
                if(customer.acc_no == searchAccNo)
                {

                    printf("Current Balance before deposit: %.2f\n", customer.Current_Balance);

                    customer.Current_Balance += deposit_amount;
                    customer.deposits[customer.num_of_deposits] = deposit_amount;
                    customer.num_of_deposits++;

                    fseek(SaveDetails, -sizeof(struct customer_details), SEEK_CUR);

                    fwrite(&customer, sizeof(struct customer_details),1,SaveDetails);

                    printf("Current Balance after deposit: %.2f\n", customer.Current_Balance);


                    found = 1;
                    break;
                }
            }

            if(found==0)
            {
                printf("Account number not found\n");
            }
            else
            {
                printf("Deposit Successful!\n\n");
            }

            fclose(SaveDetails);
            break;

        }
        case 4:
        {
            int searchAccNo;
            int found = 0;
            customer.num_of_withdrawal = 0;

            // struct customer_details customer;

            printf("Enter account number: ");
            scanf("%d", &searchAccNo);

            float withdrawl_amount;

            printf("Enter the amount to withdraw: ");
            scanf("%f", &withdrawl_amount);

            SaveDetails = fopen("CustomerDetails.txt", "rb+");
            if(SaveDetails == NULL)
            {
                printf("Error Opening File!\n");
                return 1;
            }

            while(fread(&customer, sizeof(struct customer_details),1,SaveDetails)==1)
            {
                if(customer.acc_no == searchAccNo)
                {

                    printf("Current Balance before withdrawal: %.2f\n", customer.Current_Balance);

                    customer.Current_Balance -= withdrawl_amount;
                    customer.withdrawals[customer.num_of_withdrawal] = withdrawl_amount;
                    customer.num_of_withdrawal++;

                    fseek(SaveDetails, -sizeof(struct customer_details), SEEK_CUR);

                    fwrite(&customer, sizeof(struct customer_details),1,SaveDetails);

                    printf("Current Balance after withdrawal: %.2f\n", customer.Current_Balance);


                    found = 1;
                    break;
                }
            }

            if(found==0)
            {
                printf("Account number not found\n");
            }
            else
            {
                printf("Withdrawal Successful!\n\n");
            }

            fclose(SaveDetails);
            break;
        }
        case 5:
        {
            int searchAccNo;
            int found = 0;
            customer.num_of_transfers = 0;

            // struct customer_details customer;

            printf("Enter account number: ");
            scanf("%d", &searchAccNo);

            float transfer_amount;

            printf("Enter the amount to transfer: ");
            scanf("%f", &transfer_amount);

            SaveDetails = fopen("CustomerDetails.txt", "rb+");
            if(SaveDetails == NULL)
            {
                printf("Error Opening File!\n");
                return 1;
            }

            while(fread(&customer, sizeof(struct customer_details),1,SaveDetails)==1)
            {
                if(customer.acc_no == searchAccNo)
                {

                    printf("Current Balance before transfer: %.2f\n", customer.Current_Balance);

                    customer.Current_Balance = customer.Current_Balance - transfer_amount;
                    customer.transfers[customer.num_of_transfers] = transfer_amount;
                    customer.num_of_transfers++;

                    fseek(SaveDetails, -sizeof(struct customer_details), SEEK_CUR);

                    fwrite(&customer, sizeof(struct customer_details),1,SaveDetails);

                    printf("Current Balance after trasnfer: %.2f\n", customer.Current_Balance);


                    found = 1;
                    break;
                }
            }

            if(found==0)
            {
                printf("Account number not found\n");
            }
            else
            {
                printf("Transfer Successful!\n\n");
            }

            fclose(SaveDetails);
            break;
        }

        case 6:
        {
            int searchAccNo;
            int found = 0;

            printf("Enter account number: ");
            scanf("%d", &searchAccNo);

            SaveDetails = fopen("CustomerDetails.txt", "rb+");
            if(SaveDetails == NULL)
            {
                printf("Error Opening File!\n");
                return 1;
            }


            while(fread(&customer, sizeof(struct customer_details),1,SaveDetails)==1)
            {
                if(customer.acc_no == searchAccNo)
                {
                    for(int i=0; i<customer.num_of_deposits; i++)
                    {
                        printf("Deposits:\n%.2f\n", customer.deposits[i]);
                    }
                    for(int i=0; i<customer.num_of_withdrawal; i++)
                    {
                        printf("Withdrawals:\n%.2f\n", customer.withdrawals[i]);
                    }
                    for(int i=0; i<customer.num_of_transfers; i++)
                    {
                        printf("Transfers:\n%.2f\n", customer.transfers[i]);
                    }
                    found = 1;
                    break;
                }
            }

            if(found==0)
            {
                printf("Account number not found");
            }
            break;
        }

        case 7:
        {
            printf("Thank you!");
            exit(0);
        }

        }
        printf("\n\nDo you want to continue? Enter Y or N: ");
        scanf(" %c", &confirm);

        if(confirm == 'n' || confirm == 'N')
        {
            printf("Thank You!");
            break;
        }
    }

}
