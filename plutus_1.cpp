#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=10000000;
vector<int>primes,spf(N,0);
void sieve(ll int &ans, ll int A){
	ans=1;
	for(int i=2;i<N;i++){
		if(spf[i]==0){
			primes.push_back(i);
			if(A%i==0)ans*=i;
			spf[i]=i;
		}
		for(int j=0;j<primes.size() and i*primes[j]<N;j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
long long power(long long x, long long y){
    long long res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = (y >> 1) % mod;
        x = (x * x) % mod;
    }
    return res;
}

ll int final(ll int A){
	unordered_map<ll int , ll int>mp;
	while(A!=1){
		ll int n=A/spf[A];
		mp[spf[A]]++;
		A=A/spf[A];
	}
	ll int ans=1;
	for(auto i:mp){
		ans=ans*(i.second+1);
	}
	return ans;
}
ll int countFactors(int n){
    int count = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            if (n / i == i)count++;
            else count += 2;
        }
    }
    return count;
}
 
long long multiplyFactors(int n){
    int numFactor = countFactors(n);
    long long product = power(n, numFactor / 2);
    if (numFactor & 1) product = (product * (int)sqrt(n)) % mod;
    return product;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	ll int A; cin>>A;
	 	ll int ans;
	 	sieve(ans,A);
	 	ll int B=ans;
	 	ll int C=multiplyFactors(B);
	 	ll int D=final(C);
	 	cout<<A<<" "<<B<<" "<<C<<endl;
		 cout<<D;
	}
return 0;
}
