#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=2e5+1;
vector<vector<ll int>>fenwicks(2,vector<ll int>(N));
//0-diamonds, 1-coins

void update(ll int r,ll int x,ll int val){
	for(x;x<N;x+=(x&(-x))){
		fenwicks[r][x]=max(fenwicks[r][x],val);
	}	
}

ll int query(int r, int x){
	if(x<=0)return 0;
	ll int sum=0;
	for(x;x>0;x-=(x&(-x))){
		sum=max(sum,fenwicks[r][x]);
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ll int n,c,d; cin>>n>>c>>d;
	 	ll int ans=minf;
	 	for(int i=0;i<n;i++){
	 			int b,m; cin>>b>>m; char s; cin>>s;
	 			if(s=='C'){
	 				if(c>=m){
						ll int l=query(0,d);
						ll int r=query(1,c-m);
						ll int t=max(l,r);
						if(t)ans=max(ans,t+b);
					}
					update(1,m,b);
				}
				else{
					if(d>=m){
						ll int l=query(1,c);
						ll int r=query(0,d-m);
						ll int t=max(l,r);
						if(t)ans=max(ans,t+b);
					}
					update(0,m,b);
				}
		}
		cout<<max((ll int)0,ans);
	}
return 0;
}
