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
	 	string A,B;
	 	cin>>A>>B;
	 	unordered_map<char, int>mp;
	 	int cnt=0;
		 for(auto i:A){mp[i]++;cnt++;}
	 	for(auto i:B){
		 if(mp[i])cnt--;
		 else continue;
		 mp[i]--;
		}
	 	cout<< (cnt==0);
	}
return 0;
}
