#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=100001;
vector<int>primes,spf(N,0);
void sieve(){
	for(int i=2;i<N;i++){
		if(spf[i]!=0){
			continue;
		}
		spf[i]=i; primes.push_back(i);
		for(int j=0;j<primes.size() and i*primes[j]<N;j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
int sumer(int x){
	
	unordered_map<int, int>mp;
	while(x!=1){
		mp[spf[x]]++;
		x=x/(spf[x]);
	}
	int ans=0;
	for(auto i:mp){
		int p=i.first;
		int k=i.second;
		ans+=((ll int)pow(p,k+1)-1)/(p-1);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	vector<int>A(n,0);
	 	int sum=0;
	 	vector<char>pref(n,'e');
	 	for(int i=0;i<n;i++){
			int x; cin>>x;
			if(sumer(x)%2)A[i]=1;
			sum+=A[i];
			if(sum%2)pref[i]='o';
			//cout<<sumer(x)<<" "; 
		}
//		for(int i:A)cout<<i<<" ";
//		cout<<endl;
//		for(char c:pref)cout<<c<<" ";
		unordered_map<char,int>mp1,mp0;
		int ans=0;
		for(int i=0;i<n;i++){
			if(A[i]==1){
				if(pref[i]=='o'){
					mp1['o']++;
					ans+=mp1['o'];
					ans+=mp0['e'];
					
				}
				else{
					mp1['e']++;
					ans+=mp1['e'];
					ans+=mp0['o'];
				} 
			}
			else{
				if(pref[i]=='o'){
					ans+=mp0['e'];
					ans+=mp1['o'];
					mp0['o']++;	
				}
				else{
					ans+=mp0['o'];
					ans+=mp1['e'];
					mp0['e']++;
				}
			}
		//	cout<<ans<<" ";
		}
		cout<<ans;
	}
return 0;
}
