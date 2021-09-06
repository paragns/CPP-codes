#include <bits/stdc++.h>
using namespace std;

// Function that returns the cost of making all elements equal to current element
int costCalculation(int current, int arr[], int n, int pref[], int a, int r, int minimum){
	// Compute the lower bound of current element
	int index= lower_bound(arr, arr + n, current)- arr;

	// Calculate the requirement of add operation
	int left = index * current - pref[index];

	// Calculate the requirement of subtract operation
	int right= pref[n] - pref[index]- (n - index)*current;

	// Compute minimum of left and right
	int res = min(left, right);
	left -= res;
	right -= res;

	// Computing the total cost of add and subtract operations
	int total = res * minimum;
	total += left * a;
	total += right * r;

	return total;
}
// Function that prints minimum cost of making all elements equal
void solve(int arr[], int n, int a, int r, int m){
	// Sort the given array
	sort(arr, arr + n);

	// Calculate minimum from a + r and m
	int minimum = min(a + r, m);
	int pref[n + 1] = { 0 };

	// Compute prefix sum
	for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + arr[i];
	int ans = 10000;
	// Find the minimum cost from the given elements
	for (int i = 0; i < n; i++) ans= min(ans,costCalculation(arr[i], arr, n,pref, a, r, minimum));

	// Finding the minimum cost from the other cases where minimum cost can occur
	ans= min(ans,costCalculation( pref[n] / n, arr,n, pref, a, r, minimum));
	ans= min(ans,costCalculation(pref[n] / n + 1,arr, n, pref, a, r, minimum));

  // Printing the minimum cost of making all elements equal
	cout << ans << "\n";
}

// Driver Code
int main()
{
	int arr[] = { 5, 5, 3, 6, 5 };
	int A = 1, R = 2, M = 4;
	int size = sizeof(arr) / sizeof(arr[0]);
	// Function Call
	solve(arr, size, A, R, M);

	return 0;
}

