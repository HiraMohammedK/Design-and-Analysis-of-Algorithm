#include <bits/stdc++.h>
using namespace std;


int knapsack(int weight[],int value[],int N,int W)
{int dp[N+1][W+1];
    // Initialize the dp matrix
    memset(dp, 0, sizeof dp);

    // Iterate through each item
    for (int i = 1; i <= N; i++)
    {
        // Iterate through each weight capacity
        for (int j = 0; j <= W; j++)
        {
            // If the item does not fit in the knapsack, copy the value from the previous item
            if (weight[i-1] > j)
                dp[i][j] = dp[i-1][j];

            // Otherwise, take the maximum of the value from the previous item or the value of this item plus the value obtained from the remaining weight
            else
                dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-weight[i-1]]);
        }
    }

    // Return the maximum value that can be obtained
    return dp[N][W];
}

int main()
{
    // Number of items
int N;

// Weight and value of each item
int weight[N], value[N];

// Knapsack capacity
int W;

// Matrix to store the optimal solution


    cout << "Enter the number of items: ";
    cin >> N;

    cout << "Enter the weight and value of each item: " << endl;
    for (int i = 0; i < N; i++)
        cin >> weight[i] >> value[i];

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    cout << "Maximum value: " << knapsack(weight,value,N,W) << endl;

    return 0;
}
