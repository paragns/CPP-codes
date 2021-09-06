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
	 	int n; cin>>n;
	 	unordered_map<int,int>mp;
	 	for(int i=0;i<n;i++){
			int x;cin>>x;
		 	mp[x]++;
		}
	 	vector<vector<int>>A(mp.size());
	 	int j=0;
		for(auto i:mp){
			A[j++]={i.second,i.first}; 	
		}
		sort(A.begin(),A.end());
		int m; cin>>m;
		int i=0,cnt=0;
		while(m and i<A.size()){
			if(m-A[i][0]>=0)m-=A[i][0], cnt++;
		i++;
		}
//		for(int i=0;i<A.size();i++){
//		for(int j:A[i])cout<<j<<" ";
//		cout<<endl;
//		}

		cout<<A.size()-cnt;
	 	
	 	
	 }
	
	
return 0;
}
