#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1e5+1;
vector<int>primes,spf(N,0);

void sieve(){
	spf[0]=spf[1]=1;
		for(int i=2;i<N;i++){
			if(!spf[i]){
				spf[i]=i;
				primes.push_back(i);
			}
			for(int j=0;j<primes.size() and i*primes[j]<N; j++){
				spf[primes[j]*i]=primes[j];
			}
		}
}
int func(int a,int m){
	int cnt=0;
	while(a!=1){
		int r=spf[a];
		if(r>m)return -1;
		else a=a/r;
		cnt++;
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	sieve();
	 	int a,b,m;
	 	cin>>a>>b>>m;
	 	int g=__gcd(a,b);
	 	a=a/g;
	 	b=b/g;
	 	int l=func(a,m),r=func(b,m);
	 	if(l==-1 or r==-1)cout<<"-1";
	 	else cout<<l+r;
	}
return 0;
}
