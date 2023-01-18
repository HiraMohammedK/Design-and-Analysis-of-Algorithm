#include <bits/stdc++.h>
using namespace std;

// Number of cities
const int N = 4;

// Matrix to store the distances between cities
int dist[N][N];

// Matrix to store the optimal solution
int dp[1<<N][N];

int TSP(int mask, int pos)
{
    // If all cities have been visited, return distance to starting city
    if (mask == (1<<N)-1)
        return dist[pos][0];

    // If solution has already been computed, return it
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    // Initialize minimum distance to a large value
    int min_dist = INT_MAX;

    // Try visiting all cities that have not been visited yet
    for (int city = 0; city < N; city++)
    {
        // Skip city if it has already been visited
        if (mask & (1<<city))
            continue;

        // Calculate distance to this city and the shortest distance to visit all other cities
        int d = dist[pos][city] + TSP(mask | (1<<city), city);

        // Update minimum distance if necessary
        min_dist = min(min_dist, d);
    }

    // Store and return the minimum distance
    return dp[mask][pos] = min_dist;
}

int main()
{
    // Initialize dp array to -1
    memset(dp, -1, sizeof dp);

    // Read in the distance between cities
    cout<<"The distance between cities:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    // Calculate and print the minimum distance
    cout << "The minimum distance between the cities is:"<<TSP(1, 0) << endl;

    return 0;
}