#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1e5+1; 
vector<vector<ll int>>fen;
void update(int r, int x, int val){
	for(x;x<N;x+=(x&(-x))){
		fen[r][x]+=val;
	}
}
ll int query(int r, int x){
	ll int sum=0;
	for(x;x>0;x-=(x&(-x))){
		sum+=fen[r][x];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fen.resize(101,vector<ll int>(N,0));
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n,k,q;
	 	cin>>n>>k>>q;
	 	vector<int>A(n);
	 	for(int i=0;i<n;i++){
			cin>>A[i];
			update(A[i],i+1,1);
		}
		unordered_map<int, int>mp;
		for(int i=1;i<101;i++){
			ll int t=query(i,n);
			mp[i]=t;
		}
//		for(auto i:mp){
//		 cout<<i.first<<" "<<i.second<<endl;
//		}
		for(int j=0;j<q;j++){
			auto sp=mp;
			ll int l,r;
			cin>>l>>r;
			l--;
			int m=r/n;
			r=r%n;
			for(int i=1;i<=100;i++){
				sp[i]=mp[i]*m;
				sp[i]+=query(i,r);
			}
			m=l/n;
			l=l%n;
		
			for(int i=1;i<=100;i++){
				sp[i]-=mp[i]*m;
				sp[i]-=query(i,l);
			}
//			for(auto i:sp){
//		 cout<<i.first<<" "<<i.second<<endl;
//		}
			ll int maxe=-1,ans;
			for(int i=1;i<=100;i++){
				if(sp[i]>=maxe){
					maxe=sp[i];
					ans=i;
				}
			}
			cout<<ans<<'\n';
		}
		
	}
return 0;
}
