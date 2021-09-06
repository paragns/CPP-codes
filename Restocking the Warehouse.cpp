#include <bits/stdc++.h>
using namespace std;
#define ll long long
  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	ll int sum=0;
	vector<int>A(n);
	for(int i=0;i<n;i++){
		
		cin>>A[i];
		sum+=A[i];
	}
	
	ll int target;
	cin>>target;
	int i=0;
	ll int sum1=0;
	while(i<n and sum1<target){
		sum1+=A[i];
		i++;
	}
	cout<< abs(target-sum1);
return 0;
}
/*
input
6
9
1 1 4
1 2 3 
1 3 4
2 5 6
3 2 4
3 1 2
4 3 6
5 3 5
6 4 5
*/
