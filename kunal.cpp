 #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    #define inf INT_MAX
    #define minf INT_MIN
    //vector<int>vis(N+1,0);
      ll int dfs(int node,	vector<vector<ll int>> & adj, vector<ll int> &sum ){
    	  	sum[node]=1;
    	  	ll int ans=0;
    	  	for(auto child:adj[node]){
    	  		if(!sum[child]){
    	  			ans+=dfs(child,adj,sum);
    			  }
    		  }
      	 return sum[node]+=ans;
      }
    // Driver code
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	int t=1;
    	//cin>>t;
    	while(t--){	
    		ll int N,e;
    		cin>>N>>e;
    		vector<vector<ll int>>edges(N-1);
    		vector<vector<ll int>>adj(N+1);
    		
    		for(int i=0;i<e;i++){
    			ll int a,b;
    			cin>>a>>b;
    			adj[a].push_back(b);
    			adj[b].push_back(a);
    			edges[i]={a,b};
    		}
    		
            vector<ll int>sum(N+1,0);	
    		ll int p=dfs(1,adj,sum);
    		for(int i:sum)cout<<i<<" ";
    		cout<<endl;
			cout<<p<<endl;
    		ll int ans=INT_MIN;	
    		vector<int>sol={inf,inf};
    		ll int diff =-10;
    		for(int i=0;i<edges.size();i++){
    			ll int u=edges[i][0], v=edges[i][1];
    	        ll int lower_sum = min(sum[u], sum[v]);
    	        ll int remain_sum = p - lower_sum;	
    			ll int diff = abs(lower_sum*remain_sum);
            	if(diff>=ans){
            		ans=diff;
            		if(v<u)swap(u,v);
            		if(sol[0]>u )sol={u,v};
            		else if(sol[0]==u and sol[1]>v)sol={u,v};
    			}
    		
    		}
	
			cout<<sol[0]<<" "<<sol[1];			
    	}
    	
    return 0;
    }
