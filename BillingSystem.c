#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer_name[50];
    char date[50];
    int no_of_items;
    struct items itm[50];

};

void Bill_header(char name[50], char date[30])
{
    printf("        SSRestaurant\n");
    printf("       --------------\n\n");
    printf("Date: %s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}

void Bill_body(char item[], float price, int qty)
{
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f",qty * price);
    printf("\n");
}


//void Bill_footer(float total)
//{

//}

main()
{
    int n;
    float total=0;
    char saveBill = 'y',contFlag = 'y';

    FILE *fp;

    struct orders ord;
    struct orders order[100];

    printf("=================SSRestaurant==================");


    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit\n");

    int choice;
    printf("\nYour choice: ");
    scanf("%d", &choice);
    fgetc(stdin);
    ord.no_of_items = n;



    switch(choice)
    {
    case 1:
        printf("\nEnter the customer name: ");
        fgets(ord.customer_name,50,stdin);
        ord.customer_name[strlen(ord.customer_name)-1] = 0;
        strcpy(ord.date,__DATE__);
        printf("\nEnter number of items: ");
        scanf("%d", &n);


        for(int i=1; i<=n; i++)
        {
            fgetc(stdin);
            printf("\n\nPlease enter the item %d: ", i);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1] = 0;
            printf("\nEnter the unit price: ");
            scanf("%f", &ord.itm[i].price);
            printf("\nEnter the quantity: ");
            scanf("%d", &ord.itm[i].qty);
            printf("\n");
            total = total + ord.itm[i].price * ord.itm[i].qty;

        }

        Bill_header(ord.customer_name,ord.date);

        for(int i=1; i<=n; i++)
        {
            Bill_body(ord.itm[i].item, ord.itm[i].price, ord.itm[i].qty);
        }

        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s",&saveBill);

        if(saveBill == 'y')
        {
            fp = fopen("RestaurantBill.txt","w");
            fwrite(&ord, sizeof(struct orders),1,fp);
            if(fwrite != 0)
                printf("\nSuccessfully saved");
            else
                printf("\nError saving");
            fclose(fp);

        }
        break;
    }

}

