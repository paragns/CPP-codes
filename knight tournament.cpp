#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	int n;cin>>n;
	 	int m;cin>>m;
	 	set<int>s;
	 	for(int i=1;i<=n;i++)s.insert(i);
	 	vector<int >ans(n+1,0);
	 	
	 	for(int i=0;i<m;i++){
			 int x,y,z;
		 	cin>>x>>y>>z;
		 	auto j=s.lower_bound(x);
		 	while(j!=s.end() and *j<=y){
		 		//cout<<*j<<" ";
			 	if(*j!=z)ans[*j]=z;
			 	s.erase(j);
			 	j=s.lower_bound(x);
			 }
		 	s.insert(z);
		 }
		 for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	 }
return 0;
}
