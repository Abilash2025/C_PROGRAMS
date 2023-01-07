#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Weight_of_knapsack;
    printf("capacity of knapsack : ");
    scanf("%f",&Weight_of_knapsack);

    int n;
    printf("No of objects : ");
    scanf("%d",&n);

    float weights[n];
    float profits[n];

    for (int i = 0 ; i < n ; i++)
    {
        printf("weight of object %d : ",i+1);
        scanf("%f",&weights[i]);

        printf("profit of object %d : ",i+1);
        scanf("%f",&profits[i]);
    }

    float storage_used = 0;

    float ratio[n];

    for (int i = 0 ; i < n ; i++)
    {
        ratio[i] = profits[i]/weights[i];

    }
    int flag = 1;

    float x[n];

    while (flag != 0)
    {
        int max = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (ratio[max] <= ratio[i])
            {
                max = i;
            }
        }
        ratio[max] = 0;

        if(weights[max] + storage_used <= Weight_of_knapsack)
        {
            x[max] = 1;
            storage_used = storage_used + weights[max];
        }
        else
        {
            float remaining_storage = Weight_of_knapsack - storage_used;
            x[max] = ((remaining_storage) / weights[max]);
            flag = 0;
        }
    }

    printf("X : ");
    for (int i = 0 ; i < n ; i++)
    {
        printf("%.2f ",x[i]);
    }
    printf("\n");

    float total_profit = 0;

    for (int i = 0 ; i < n ; i++)
    {
        total_profit += (x[i]*profits[i]);
    }

    printf("Total profit : %.2f",total_profit);

    return 0;
}
