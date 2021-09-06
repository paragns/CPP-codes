#include <bits/stdc++.h>
using namespace std;
	int sol=1;
	int n;
	vector<int>A;
	int k;
	unordered_map<int,int>mp;
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n;
	cin>>k;
	cin>>n;
	A.resize(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	int ans=-1;
	for(int i=0;i<n;i++){
			if(mp.find(A[i]^k)!=mp.end())mp[A[i]]=mp[A[i]^k]+1;
  			else mp[A[i]]=1;
		  	ans=max(ans,mp[A[i]]);
		}
	
	cout<<ans;
		
return 0;
}
//2 5 1 3 2

