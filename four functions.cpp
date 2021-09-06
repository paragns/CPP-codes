    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    const int N=1e6+5;
    vector<int> primes;
    int spf[N+1];
    void linear_sieve(){
        for(int i=2;i<=N;i++){
            if(spf[i]==0){
                spf[i]=i;
                primes.push_back(i);
            }
            for(int j=0;j<primes.size() and i*primes[j]<=N;j++)
                spf[i * primes[j]] = primes[j];
        }
    }
    
int D[N],C[N];
    void precompute(){
        C[1]=D[1]=0;
        for(int i=2;i<N;i++){
            C[i]=1+C[i/spf[i]];
            D[i]=D[i-1]+C[i];
        }
    }
    void solve(){
        int n;
        cin>>n;
        cout<<D[n]<<'\n';
        
     
    }
 int main()
  {    
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        linear_sieve();
        precompute();
        int t=1;
        cin>>t;
        while(t--){
        	solve();
        	}
        return 0;
       }
