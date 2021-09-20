#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
	 while(t--){
	 	int n;cin>>n;
        vector<int>A(9);
        int mine=inf;
	 	for(int i=0;i<9;i++){cin>>A[i]; mine=min(mine,A[i]);}
		int lim=n/mine;
		string ans="";
		for(int i=8;i>=0;i--){
			if(n-A[i]>0 and (n-A[i])/mine==lim-1){n-=A[i];ans+=('0'+(i+1));i++;lim--;}
			// cout<<n<<" "<<ans;
	    }
		if(ans.size()==0)cout<<"-1"<<'\n';
		 else cout<<ans<<'\n';
	 }
return 0;
}
