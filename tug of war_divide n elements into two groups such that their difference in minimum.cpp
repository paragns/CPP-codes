/*
    Time Complexity : O(2^N)
    Space Complexity : O(N)
    
    Where 'N' is the number of students.
*/

#include <climits>

int tugOfWarHelper(int i, int subsetSum, int cnt, int totalSum, vector<int> &arr, int n)
{
    // base case
    if (i == n || cnt >= (n / 2))
    {
        if (cnt == (n / 2))
        {
            return abs(totalSum - 2 * subsetSum);
        }
        return INT_MAX;
    }
    int ans = INT_MAX;

    // don't take ith student
    ans = min(ans, tugOfWarHelper(i + 1, subsetSum, cnt, totalSum, arr, n));

    // take ith student
    ans = min(ans, tugOfWarHelper(i + 1, subsetSum + arr[i], cnt + 1, totalSum, arr, n));

    return ans;
}

int tugOfWar(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    // call the recursive function
    int ans = tugOfWarHelper(0, 0, 0, totalSum, arr, n);

    return ans;
}
