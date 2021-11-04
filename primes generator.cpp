#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100004;
vector<int>primes,spf(N,0);
void sieve(){
	for(int i=2;i<N;i++){
		if(spf[i]==0){
			spf[i]=i;
			primes.push_back(i);
		}
		for(int j=0;j<primes.size() and i*primes[j]<N;j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
int main(){
	int T;
	cin>>T;
	sieve();
	while(T--){
		
		ll int l,r;
		cin>>l>>r;
		map<int,int>mp;
		for(int i=0;i<primes.size();i++){
			int n1=l/primes[i];
			if(n1*primes[i]!=l)n1++;
			if(n1==1)n1++;
			for(int j=n1*primes[i];j<=r;j+=primes[i]){
				mp[j]++;
			}
		}
		for(int i=l;i<=r;i++){
			if(mp[i] or i<2)continue;
			cout<<i<<'\n';
		}
		cout<<'\n';
	}
}

