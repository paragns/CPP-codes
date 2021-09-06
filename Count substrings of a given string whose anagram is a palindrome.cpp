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
	 	string s; cin>>s;
	 	int mask=0,ans=0;
        unordered_map<int,int>mp;
        mp[mask]++;
        for(int i=0;i<s.size();i++){
            mask^=(1<<(s[i]-'a'));
            ans+=mp[mask];
            
            for(int j=0;j<26;j++){
                ans+=mp[mask^1<<j];
            }
            mp[mask]++;
        }
	 	cout<<ans;
	 }
	
	
return 0;
}
