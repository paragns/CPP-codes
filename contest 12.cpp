#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	
	int m;
	cin>>n>>m;
	vector<int >par(n+1);
	
	for(int i=0;i<=n;i++)par[i]=i;
	
//	for(auto i:par) cout<<i<<" ";
	
	for(int i=0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		for(int j=l;j<=r;j++){
			if(par[j]==j and j!=x)par[j]=x;
		}
		
	}
	int i=1;
	for(i=1;i<n;i++){
	if(par[i]==i)par[i]=0;
	cout<< par[i]<<" ";
}
if(par[i]==i)par[i]=0;
	cout<<par[i];

return 0;
}
