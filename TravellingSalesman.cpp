#include <bits/stdc++.h>
using namespace std;

int n = 4;
// adj matrix
vector<vector<int>> graph = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

// if all cities have been visited
int VISITED_ALL = (1 << n) - 1;

// dp array which stores all possible combination ans city position pairs
vector<vector<int>> dp((1 << n), (vector<int>(n, -1)));

// mask --> set of cities
int tsp(int mask, int pos)
{

    if (mask == VISITED_ALL)
    {
        return graph[pos][0];
    }

    // memotization
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // try to go to unvisited city
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = graph[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    // Intially we start with first city whose mask=0001 and pos=0
    cout << tsp(1, 0) << endl;
    return 0;
}