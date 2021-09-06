#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	 while(t--){
	 	ll int n; cin>>n;
			unordered_map<ll int, int>mp;
			for(int i=0;i<n;i++){
				ll int x;cin>>x;
				mp[x]++;
			}
			ll int half=ceil(1.0*n/2);
			
			
			vector<ll int >nums;
			for(auto i=mp.begin();i!=mp.end();++i){
				nums.push_back(i->second);
			}
	 	sort(nums.begin(),nums.end(), greater<ll int>());
	 	ll int ans=0,i=0;
	 	
		 while(half>0){
		 	half-=nums[i];
			 ans++;
			 i++;
			 
		 }
	 	cout<<ans;
	 }
	
	
return 0;
}
