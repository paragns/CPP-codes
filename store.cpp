#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	string A;
	cin>>A;
	unordered_map<char, int>mp;
	for(int i=0;i<A.size();i++){
		mp[A[i]]++;
	}
	
	int n; cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		char t; cin>>t;
		ans+=(mp[t]*t);	
	}
	cout<<ans;
	
return 0;
}
