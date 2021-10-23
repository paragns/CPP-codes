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
	cin>>T;
	 while(T--){
	 	unordered_map<int, vector<vector<int>>>adj;
		int n,m;
	 	cin>>n>>m;
	 	vector<int>from(m),to(m);
	 	for(int i=0;i<m;i++){
			cin>>from[i];
		}
		for(int i=0;i<m;i++){
			cin>>to[i];
		}
		from(int i=0;i<m;i++){
			int x;
			cin>>x;
			mp[form[i]].push_back({to[i],x});
			mp[form[i]].push_back({to[i],x});
		}
	}
return 0;
}
