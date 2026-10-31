#include <stdio.h>

int main()
{
    int n, W, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weights of items:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits of items:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i - 1] <= w)
            {
                int include = profit[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];

                if(include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum Profit = %d\n", dp[n][W]);
 
    return 0;
}
