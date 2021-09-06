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
	 	vector<ll int>pos(n);

	 	unordered_map<ll int ,ll int>walls;
	 	for(int i=0;i<n;i++){
		 	cin>>pos[i];
		 }
		 	
		 cin>>n;
		for(int i=0;i<n;i++){
		 	int x;
			 cin>>x;
			 walls[pos[i]]=x;
		 }
		 sort(pos.begin(),pos.end());
		 ll int ans=0;
		for(int i=0;i<n-1;i++){
			int ind1=pos[i];
			int ind2=pos[i+1];
			if(ind2-ind1==1)continue;
			ll int x=ind2-ind1-1;
			ll int mine=min(walls[ind1],walls[ind2]);
			ll int maxe=max(walls[ind1],walls[ind2]);
			
			maxe=min(maxe,mine+x);
			ll int val=(maxe+1-mine+x)/2;		
			ans=max(ans,mine+val);
			
		} 
	 	cout<<ans;
	 	
	 }
	
	
return 0;
}
