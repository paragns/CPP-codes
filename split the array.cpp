#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
const int N=1000001;
vector<int>primes;
int spf[N];

void sieve(){
	spf[0]=spf[1]=1;
	for(int i=2;i<N;i++){
		if(!spf[i])spf[i]=i, primes.push_back(i);
		for(int j=0;j<primes.size() and i*primes[j]<N;j++){
			spf[i*primes[j]]=primes[j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	while(T--){ 	
	sieve();
	int n; cin>>n;
	
	vector<int>A(n),mine(N,inf),prev(n);
	for(auto &i:A)cin>>i;
	int temp=0; 	
	 	for(int i=0;i<n;i++){
			prev[i]=temp;
			int k=A[i];
			while(k!=1){
				int l=spf[k];
				mine[l]=min(mine[l],temp);
				prev[i]=min(prev[i],mine[l]);
				while(k%l==0){
					k/=l;
				}
			}
			temp=prev[i]+1;
		}
		//for(int i:prev)cout<<i<<" ";
		cout<<prev[n-1]+1;
	}
return 0;
}
/* explaination:
 consider 3 2 6;
 we find all the factos of a no. and find the min prev value this factor can take us
    initially 3 has mine[3]=inf  so we update it to 0 as prev value for A[0]=0;
    similarly for 2 mine[2]=1;
    now for factors of 6 we get 2and 3 so in prev array we fill the min value that
	these factors can take us to;
	firstly prev value of 6 is what 2(prev index) had +1 then it is udated to mine[2]
	since 2 is factor so prev value of 6 becomes prev value of 2 that is they can be paired.
	i.r prev value of 6 is now 1; but then 3 is also factor so prev value of 6 becomes 
	prev value of 3 i.e 0 so 3-6 can be paired 
	the variable temp is to track the value of previous index in prev array;
    
*/
