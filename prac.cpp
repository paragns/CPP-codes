#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=200001;
vector<int>primes,spf(N,0);
void sieve(){
	for(int i=2;i<N;i++){
		if(spf[i]==0){primes.push_back(i); spf[i]=i;}
		for(int j=0;j<primes.size() and primes[j]*i<N; j++){
			spf[primes[j]*i]=primes[j];
		}
	}
}
unordered_map<int, int>mp;
void func(int A){
	while(A!=1){
		mp[spf[A]]^=1;
		int x=spf[A];
		while(spf[A]==x){
			A=A/spf[A];
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
		 int n;
	 	cin>>n;
	 	vector<int>st(n);
	 	for(int i=0;i<n;i++)cin>>st[i];
	 	int m;
		cin>>m;
		 vector<int>A(m);
		 for(int i=0;i<m;i++){cin>>A[i];
		 	func(A[i]);
		 }
		 for(auto i:mp){
		 	if(i.second==0)continue;
			 int x=i.first;
			// cout<<x<<" ";
		 	for(int j=x-1; j<n;j+=x){
				st[j]^=1; 
			}
		 }
		 for(int i:st)cout<<i<<'\n';
	}
return 0;
}
