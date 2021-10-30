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

ll int func(ll int A){
	unordered_set<ll int>s;
	while(A!=1){
		s.insert(spf[A]);
		A=A/spf[A];
	}
	ll int B=1;
	for(int i:s)B=B*i;
	return B;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	sieve();
	 	ll int A; cin>>A;
	 	ll int B=func(A);
	 	ll int C=multiplyFactors(B);
	 	ll int D=final(C);
	 	cout<<A<<" "<<B<<" "<<C<<endl;
		 cout<<D;
	}
return 0;
}
