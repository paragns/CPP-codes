#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &a, vector<vector<int>> &dp, int i, int j)
{
    if (i == a.size() - 1 && j == a.size() - 1)
    {
        dp[i][j] = a[i][j];
        return dp[i][j];
    }
    if (i >= a.size() || j >= a.size())
        return INT_MIN;
    if (a[i][j] != -1)
    {
        if (dp[i][j] != -1)
        {
            a[i][j] = 0;
            return dp[i][j];
        }
        else
        {
            dp[i][j] = max(helper(a, dp, i + 1, j), helper(a, dp, i, j + 1)) + a[i][j];
            return dp[i][j];
        }
    }
    return 0;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dp1(n, vector<int>(n, -1));
    //vector<vector<int>> dp2(n,vector<int>(n,-1));
    dp1[0][0] = helper(grid, dp1, 0, 0);
    // dp2[0][0] = helper2(grid,dp2,0,0);
    // return dp1[0][0]+dp2[0][0];
    if (dp1[0][0] < 0)
        return 0;

    grid[0][0] = 0;
    int i{}, j{};
    while (i < n || j < n)
    {
        if (j == n - 1 || i < n - 1 && dp1[i + 1][j] >= dp1[i][j + 1])
        {
            i++;
            grid[i][j] = 0;
        }
        else
        {
            j++;
            grid[i][j] = 0;
        }
    }
    vector<vector<int>> dp2(n, vector<int>(n, -1));
    dp2[0][0] = helper(grid, dp2, 0, 0);
    return dp1[0][0] + dp2[0][0];
}
int main()
{   

    int n;
    cin>>n;
	vector<vector<int>> grid(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int c = cherryPickup(grid);
    cout << c << endl;
    return 0;
}
