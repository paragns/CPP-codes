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
		int k; cin>>k;
		string A;
		cin>>A;
		int n=A.size();
		unordered_map<int,int>mp;
		int sum=0,ans=0;
		for(int i=0;i<n;i++){
			sum+=(A[i]-'a'+1);
			if(sum==k)ans++;
			ans+=mp[sum-k];
			mp[sum]++;
		}
		cout<<ans<<"\n";
	}
return 0;
}
