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
	 	int r;
	 	cin>>r;
	 	int c; cin>>c;
		vector<vector<int>>A;
	 	vector<vector<int>>mat(r,vector<int>(c));
	 	for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>mat[i][j];
				A.push_back({mat[i][j],j});
			} 
		}
		sort(A.begin(),A.end());
		int i=0,j=0;
		unordered_map<int,int>mp;
int ans=inf;
		while(j<A.size()){
			while(j<A.size() and mp.size()<c){
				mp[A[j][1]]++;
				j++;
			}
			if(mp.size()==c)ans=min(ans,A[j-1][0]-A[i][0]);
			while(mp.size()==c){
				ans=min(ans,A[j-1][0]-A[i][0]);
				mp[A[i][1]]--;
				if(mp[A[i][1]]==0)mp.erase(A[i][1]);
				i++;
			}
		}
		cout<<ans<<"\n";
	}
return 0;
}
