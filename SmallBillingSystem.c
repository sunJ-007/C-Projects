#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void formateDesgin(char name[50], char date[40] )
{
    printf("\n\n");
    printf("\t    GREAT OBSERVER RESTURENT CLUB   ");
    printf("\n\t--------------------------------------");
    printf("\nDate: %s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("Items\t\t\t");
    printf("Qty\t\t\t");
    printf("Total\t\t\t");
    printf("\n------------------------------------------------------");
    printf("\n\n");
}
void printBill(char item[20],int qty,float price)
{
    printf("%s\t\t",item);
    printf("\t%d\t\t",qty);
    printf("\t%0.2f\t\t",qty*price);
    printf("\n\n");
}
void generateBill(float total)
{
    printf("\n");
    float discount = 0.1 * total;
    float netTotal = total - discount;
    printf("--------------------------------------------------------\n");
    printf("Discount offer 10%:\t\t %0.2f:",total - netTotal);
    printf("\n-------------------------------------------------------\n");
    printf("Total Amount:\t\t\t %0.2f",netTotal);
}
struct resturent
{
    char name[40];
    char item[50];
    int noOfItem;
    int uintchargeofitem;
    int qty;
    float price;
};
int main()
{
    float total;
    int m;
    struct resturent r1[40];
    printf("\n\t\t WELCOME TO THE ** GREAT OBSERBER RESTURENT CLUB *******\n");
    printf("\t\t\t=========================================\n");
    printf("\nEnter the Customer Name: ");
    scanf("%s",&r1-> name);
    printf("\nEnter the number of order as request of customer: ");
    scanf("%d",&m);

    for(int i=0; i<m; i++)
    {
        printf("\nEnter %d item: \t",i+1);
        scanf("%s",r1[i].item);
        printf("Enter Quantity of item:\t");
        scanf("%d",&r1[i].noOfItem);
        printf("Enter the per unit charge of item:\t");
        scanf("%d",&r1[i].uintchargeofitem);
        total += r1[i].noOfItem * r1[i].uintchargeofitem;
    }
    formateDesgin(r1->name,"19/10/2022");
    for(int i=0; i<r1->noOfItem; i++)
    {
        printBill(r1[i].item, r1[i].noOfItem, r1[i].uintchargeofitem);
    }
    generateBill(total);
    printf("\n\n");
    return 0;
}
