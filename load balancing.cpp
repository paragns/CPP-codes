#include <bits/stdc++.h>
using namespace std;
#define ll long long 
# define  inf 1000000000

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int k;
	cin>>k;
	int n;
	cin>>n;
	set<int>s1;
	set<pair<int, int>>s2;
	for(int i=1;i<=k;i++)s1.insert(i);
	
	vector<vector<int>>arr,ans(k+1);
	for(int i=1;i<=k;i++)ans[i]={0,i};
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back({x});
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[i].push_back(arr[i][0]+x);
	}
	sort(arr.begin(),arr.end());
	ll int prev=-1;
	
	for(int i=0;i<n;i++){
		while(!s2.empty() and s2.begin()->first<=arr[i][0]){
			auto x=*(s2.begin());
			s1.insert(x.second);
			s2.erase(s2.begin());
		}
		auto itr=s1.upper_bound(prev);
		
		if(itr==s1.end())itr=s1.upper_bound(-1);
		if(itr==s1.end())continue;
		s2.insert({arr[i][1],*(itr)});
		s1.erase(itr);
		//cout<<arr[i][1]<<"**"<<*(itr)<<endl;
		prev=*(itr);
		ans[prev][0]+=(arr[i][1]-arr[i][0]);
		if(prev==k)prev=-1;	
	}
	sort(ans.begin()+1,ans.end(),greater<vector<int>>());

	int maxe=ans[1][0];
	int i=1;
	vector<int>bhakk;
	while(i<=k and ans[i][0]==maxe){bhakk.push_back(ans[i][1]); i++;}
	sort(bhakk.begin(),bhakk.end());
	for(int i:bhakk)cout<<i<<'\n';
return 0;
}
