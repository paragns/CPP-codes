#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;cin>>n;
	 	vector<string>A(n+1);
		vector<vector<int>>prefix(n+1,vector<int>(26,0));
		 for(int i =1;i<=n;i++){
			cin>>A[i];
			prefix[i]=prefix[i-1];
			for(int j=0;j<A[i].size();j++){
				prefix[i][A[i][j]-'a']++;
			}
		}
		int q; cin>>q;
		for(int i=0;i<q;i++){
			int x,y,k;
			cin>>x>>y>>k;
			int cnt=0;
			for(int j=0;j<26;j++){
				cnt+=(prefix[y][j]-prefix[x-1][j]);
				char ans=('a'+j);
				if(cnt>=k){cout<<ans<< '\n';break;}
			}
		}
	}
return 0;
}
