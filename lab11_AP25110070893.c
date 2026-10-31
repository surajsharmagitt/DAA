#include <stdio.h>
#include <limits.h>

int main()
{
    int matrixCount;

    printf("Enter number of matrices: ");
    scanf("%d", &matrixCount);

    int dimensions[matrixCount + 1];

    printf("Enter dimensions: ");
    for(int i = 0; i <= matrixCount; i++)
        scanf("%d", &dimensions[i]);

    long long dp[matrixCount + 1][matrixCount + 1];

    for(int i = 1; i <= matrixCount; i++)
        dp[i][i] = 0;

    for(int length = 2; length <= matrixCount; length++)
    {
        for(int start = 1; start <= matrixCount - length + 1; start++)
        {
            int end = start + length - 1;

            dp[start][end] = LLONG_MAX;

            for(int split = start; split < end; split++)
            {
                long long cost = dp[start][split] +
                                 dp[split + 1][end] +
                                 (long long)dimensions[start - 1] *
                                 dimensions[split] *
                                 dimensions[end];

                if(cost < dp[start][end])
                    dp[start][end] = cost;
            }
        }
    }

    printf("Minimum number of multiplications = %lld",
           dp[1][matrixCount]);

    return 0;
}
