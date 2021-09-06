    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    int N=1000001;
    ll int BIT[1000001];
     
    void update(ll int x,ll int delta){     
    	for(x; x <= N; x += x&-x){
    		BIT[x] += delta;
    	}
    }
     
    ll int query( ll int x){
    	ll int sum = 0;
    	for(x; x > 0; x -= x&-x)
    	sum += BIT[x];
    	return sum;
    }
      
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<bool>sieve(N,false);
    	sieve[0]=true; sieve[1]=true;
    	for(int i=0;i*i<N;i++){
    		if(sieve[i])continue;
    		int t=i*i;
    		for(int j=t;j<N;j+=i){
    			sieve[j]=true;
    		}
        }
        unordered_map<int ,int>mp;
        for(int i=1;i*i*i*i<N;i++){
    		for(int j=1;(i*i*i*i +j*j)<N;j++)
    		if(!sieve[i*i*i*i +j*j] and mp.find(i*i*i*i +j*j)==mp.end()){
    			//cout<<i*i*i*i +j*j<<"*"<<i<<"&"<<j<<" ";
    		update(i*i*i*i +j*j,1);
    		mp[i*i*i*i +j*j]++;
    		}
    	}
    	
        
    	int t;
    	cin>>t;
    	while(t--){
    	ll int n;
    	cin>>n;
    	cout<<query(n)<<endl;
    }
    return 0;
    }
