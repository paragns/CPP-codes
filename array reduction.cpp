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
    vector<ll int>A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	sort(A.begin(), A.end());
	vector<ll int>pre=A;
	for(int i=1;i<n;i++)
	   pre[i]+=pre[i-1];
	   
	   int cnt=1;
	for(int i=n-2;i>=0;i--){
		if(2*pre[i]>=A[i+1])cnt++;
		else break;
	}   
	cout<<cnt;
return 0;
}
