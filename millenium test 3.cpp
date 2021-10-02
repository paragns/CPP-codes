#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool check(string A, vector<unordered_map<int, int>>&mp ){
	unordered_map<int, int>sp;
	int k=A.size(),i=0;
	while(k--){
		sp[(A[i]-'0')]++;
		i++;
	}
	for(int i=0;i<mp.size();i++){
		int flag=1;
		for(auto j:mp[i]){
			if(sp[j.first]<j.second)flag=0;
		}
		if(flag)return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	vector<unordered_map<int,int>>f;
	 	for(int i=8;i<=1000;i+=8){
			 unordered_map<int,int>t;
			 int k=i;
			 while(k){
			 	t[k%10]++;
			 	k=k/10;
			 }
			 f.push_back(t);
		}
		int n; cin>>n;
		vector<string>A(n),ans(n);
		for(int i=0;i<n;i++){
			cin>>A[i];
			if(check(A[i],f))ans[i]=("YES");
			else ans[i]="NO";
		}
		for(auto i:ans)cout<<i<<" ";
	}
return 0;
}
