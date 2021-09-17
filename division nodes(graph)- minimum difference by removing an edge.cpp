    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    #define inf INT_MAX
    #define minf INT_MIN
    //vector<int>vis(N+1,0);
      ll int dfs(int node,	vector<vector<ll int>> & adj, vector<ll int> &sum ,vector<ll int> &A){
    	  	sum[node]=1;
    	  	ll int ans=0;
    	  	for(auto child:adj[node]){
    	  		if(!sum[child]){
    	  			ans+=dfs(child,adj,sum, A);
    			  }
    		  }
      	 return sum[node]=A[node]+ans;
      }
    // Driver code
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	int t;
    	cin>>t;
    	while(t--){	
    		ll int N;
    		cin>>N;
    			
    		vector<vector<ll int>>edges(N-1);
    		int k=N-1;
    		vector<vector<ll int>>adj(N+1);
    		
    		for(int i=0;i<N-1;i++){
    			ll int a,b;
    			cin>> a>>b;
    			adj[a].push_back(b);
    			adj[b].push_back(a);
    			edges[i]={a,b};
    		}
    		
    		vector<ll int>A(N+1,0);
    		for(int i=1;i<=N;i++)
    			cin>>A[i];
    		
            vector<ll int>sum(N+1,0);	
    		ll int p=dfs(1,adj,sum,A);
    		
    		ll int ans=pow(10,10);	//ise acchese yaad rakhna maze maze mein ans=inf set kardega lekin t0tal sum 10^5*10^5 tak jaa sakti hai inf se zyada toh upperbound bada set karna padega isiliye 10^10 kiya hai;
    		ll int sol=0;
    		ll int diff =-10;
    		for(int i=0;i<edges.size();i++){
    			ll int u=edges[i][0], v=edges[i][1];
    	        ll int lower_sum = min(sum[u], sum[v]);
    	        ll int remain_sum = p - lower_sum;	
    			ll int diff = abs(lower_sum - remain_sum);
            	if(diff<ans){
            		ans=diff;
            		sol=i+1;
    			}
    			if(sol==0)cout<<diff<<'\n';
    		}
			//for(int i:sum)cout<<i<<" ";
			if(sol==0)cout<<edges.size()<<'\n';	
            else cout <<sol<<'\n';			
    	}
    	
    return 0;
    }
