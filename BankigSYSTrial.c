#include<stdio.h>

int main()
{
    float a[100];
    int count = 0;

    float dp;

    // Read deposit amounts until the array is full or the user stops input
    while (count < 3)
    {
        printf("Enter the deposit amount (or enter a negative number to stop): ");
        scanf("%f", &dp);

        // Check if the input is negative, indicating the user wants to stop
        if (dp < 0)
        {
            break;
        }

        // Store the deposit amount in the array and increment the count
        a[count] = dp;
        count++;
    }

    // Print the deposited amounts
    printf("Deposited amounts:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%f\n", a[i]);
    }

    return 0;
}
