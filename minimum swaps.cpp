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
	 	int n; cin>>n;
	 	vector<int>A(n);
	 	unordered_map<int,int>mp;
		 for(int i=0;i<n;i++){cin>>A[i]; mp[A[i]]=i;}
		sort(A.begin(),A.end(),greater<int>());
		int ans=0;
		for(auto i=mp.begin();i!=mp.end();++i){
			while(A[i->second]!=i->first){
				int x=i->second;
				i->second=mp[A[x]];
				mp[A[x]]=x;
				ans++;
			}
		}	 
		cout<<ans;	 	
	 }
	
	
return 0;
}
