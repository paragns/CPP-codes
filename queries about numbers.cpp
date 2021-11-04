#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
vector< int>primes,spf(N,0);
void sieve(){
	for(int i=2;i<N;i++){
		if(spf[i]==0)spf[i]=i;
		primes.push_back(i);
	
		for(int j=0;j<primes.size() and i*primes[j]<N;j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
unordered_map<int,int> func(int n){
	unordered_map< int,int>mp;
	for( int i=0;i<primes.size();i++){
		while(n%primes[i]==0){
			mp[primes[i]]++;
			n/=primes[i];
		}
		if(n==1)break;
	}
	return mp;	
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	sieve();
	int n,q;
	cin>>n>>q;
	auto mp=func(n);
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		auto sp=func(b);
		if(a==1){
			int ans=1;
			for(auto i:mp){
				int fac=i.first;
				ans*=(min(mp[fac],sp[fac])+1);
			}
			cout<<ans<<endl;
		}
		else if(a==2 or a==3){
			int ans=1;
			int ndiv=1;
			for(auto i:mp){
				int fac=i.first;
				ans*=(mp[fac]-sp[fac]+1);
				ndiv*=(mp[fac]+1);
			}
			for(auto i:sp){
				int fac=i.first;
				if(mp[fac]-sp[fac]<0){ans=0;break;}
			}
			if(a==2)cout<<ans<<endl;
			if(a==3)cout<<(ndiv-ans)<<endl;
		}
	}
	return 0;
}
