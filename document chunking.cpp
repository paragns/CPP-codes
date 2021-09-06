#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll int tot; cin>>tot;
 	ll int n; cin >>n;
	int m;cin>>m;
	vector<vector<ll int>>upload(n);
	
	for(int i=0;i<n;i++){
	ll int x,y;
	cin>>x>>y;
	upload[i]={x,y};
	}
	vector<ll int>gaps;
	ll int prev=0;
	for(int i=0;i<n;i++){
	gaps.push_back(upload[i][0]-prev-1);
	prev=upload[i][1];
	}
	gaps.push_back(tot-prev);
    ll int ans=0;
	for(int i=0;i<gaps.size();i++){
		ans+=__builtin_popcountll(gaps[i]);
	}
	cout<<ans;
return 0;
}
