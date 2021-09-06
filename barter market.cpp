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
	 	int com,coins,need,off;
	 	cin>>com>>coins>>need>>off;
	 	int ans=0;
	 	while(1){
			if(coins-need>=0 and com-1>=0){
				coins-=need; com--;
				ans++;	
			} 	
			else break;
		}
		//cout<<com<<" "<<coins<<endl;
		if(com==0)cout<<ans;
		else{
			while(com){
				//cout<<com<<" "<<coins<<" "<<ans<<endl;
				com--; coins+=off;
			while(1){
			if(coins-need>=0 and com-1>=0){
				coins-=need; com--;
				ans++;	
			} 	
			else break;
		}
			}
			cout<<ans;
		}
	 	
	 }
	
	
return 0;
}
