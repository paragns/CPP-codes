#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
string S;
	ll int N, gap;
	vector<ll int> sa, pos, tmp, lcp;
bool sufCmp(ll int i, ll int j){
		if (pos[i] != pos[j])return pos[i] < pos[j];
		i += gap; j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}	
void buildSA(){
	for(ll int i=0;i<N;i++) {sa[i] = i; pos[i] = S[i];}
	for (gap = 1;; gap *= 2){
		sort(sa.begin(), sa.end(), sufCmp);
		for(ll int i=0;i<N-1;i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		for(ll int i=0;i<N;i++)pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N - 1) break;
	}
}
void buildLCP(){
	int k = 0;
		for (ll int i = 0; i < N; i++) 
		if (pos[i] != N - 1){
			ll int j = sa[pos[i] + 1];
			while( S[i + k] == S[j + k])k++;
			lcp[pos[i]]= k;
			if(k)k--;
		}
	}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	cin>>S;
	 	N=S.size();
	 	if(N==0){cout<<0;continue;}
	 	sa.resize(N);
	 	pos.resize(N);
	 	tmp.resize(N);
	 	lcp.resize(N);
	   buildSA();
	   buildLCP();
	   //for(ll int i:sa)cout<<i<<" ";
	   //cout<<endl;
	   //for(ll int i:lcp)cout<<i<<" ";
	    ll int rep=0;
	    for(ll int i=0; i < N; i ++){
	       cout<<lcp[i]<<" ";
	       rep+=lcp[i];
	    }
	    cout<<N*(N+1)/2 -rep;
	}
return 0;
}
