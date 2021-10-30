#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
#define N 100005
vector<int>primes,spf(N,0);
void sieve(){
	spf[0]=spf[1]=1;
	for(int i=2;i<N;i++){
		if(spf[i]==0){
			primes.push_back(i);
			spf[i]=i;
		}
		for(int j=0;j<primes.size() and i*primes[j]<N;j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	sieve();
	}
return 0;
}
