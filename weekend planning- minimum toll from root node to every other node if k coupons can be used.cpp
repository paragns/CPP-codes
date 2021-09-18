    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    	int n, m, k;
    	cin>>n>>m>>k;
     
    	int from, to, toll;
    	vector<vector<pair<int, int>>> adj(n+1);
    	for(int i=0;i<m;i++)
    	{
    		cin>>from>>to>>toll;
    		adj[from].push_back({to, toll});
    		adj[to].push_back({from, toll});
    	}
     
    	int dist[n+1][k+1];
    	for(int i=0;i<=n;i++)
    		for(int j=0;j<=k;j++)
    			dist[i][j] = INT_MAX;
     
    	for(int i=0;i<=k;i++)
    		dist[1][i]	= 0;
     
    	set<pair<int, pair<int, int>>> st;
    	st.insert({0, {1, 0}});
     
    	while(!st.empty())
    	{
    		auto ele=*(st.begin());
    		from=ele.second.first;
    		
    		int coup = ele.second.second;
    		st.erase(st.begin());
    		for(auto x:adj[from]){
    			to = x.first;
    			toll =x.second;
    			if(dist[to][coup] > dist[from][coup] + toll){
    				st.erase({dist[to][coup], {to, coup} });
    				dist[to][coup] = dist[from][coup] + toll;
    				st.insert({dist[to][coup], {to, coup} });
    			}
    			if(coup!=k && dist[to][coup+1] > dist[from][coup])
    			{
    				st.erase({dist[to][coup+1], {to, coup+1} });
    				dist[to][coup+1] = dist[from][coup];
    				st.insert({dist[to][coup+1], {to, coup+1} });
    			}
    		}
     
    	}
     
    	for(int i=1;i<=n;i++) 
    	{
    		int ans = INT_MAX;
    		for(int j=0;j<=k;j++) 
    		{
    			ans = min(ans,dist[i][j]);
    		}
    		cout<<ans<<" ";
    	}
    	cout<<endl;
     
    	return 0;
    }
