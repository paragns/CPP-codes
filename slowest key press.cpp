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
	int T=1;
	//cin>>T;
	 while(T--){
	 	unordered_map<char, int>mp;
	 	int n,m; cin>>n>>m;
	 	int prev=0;
	 	for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			mp['a'+x]=max(mp['a'+x],y-prev);
			prev=y; 
		}
		int maxe=-1;
		char a;
	 	for(auto i:mp){
			 if(i.second>maxe)maxe=i.second, a=i.first;
			 //cout<<i.first<<" "<<i.second<<endl;
		}
		cout<<a;
	 }
	
	
return 0;
}
