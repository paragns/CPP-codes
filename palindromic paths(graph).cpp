    #include <bits/stdc++.h>
    using namespace std;
    # define ll long long
    #define mod 1000000007
    vector<vector<pair<int,int>>>adj;
    vector<int>vis;
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	int n;
    	cin>>n;
    	adj.resize(n+1);
    	vis.resize(n+1,0);
    	for(int i=0;i<n-1;i++){
    		int x,y;
    		char c;
    		cin>>x>>y>>c;
    		adj[x].push_back({y,c});
    		adj[y].push_back({x,c});
    	}
    	
    	queue<int>q;
    	q.push(1);
    	vector<int>check(n+1,0);
    	check[1]=0;
    	
    	//"0000000000000000000100"
    	
     while(!q.empty()){
     	int top=q.front();
     	vis[top]=1;
     	q.pop();
     	for(auto j:adj[top]){
    		if(vis[j.first])continue;
    		q.push(j.first);
    		int k=j.second-'a';
    		check[j.first]=check[top]^(1<<k);
    	 }
     }
     ll int ans=0;
     unordered_map<int, int>mp;
     for(int i=1;i<=n;i++){
     	ans+=mp[check[i]];
     	for(int j=0;j<26;j++){
    	 	ans+=mp[check[i]^(1<<j)];
    	 }
    	 mp[check[i]]++;
     }	
    cout<<ans;
    return 0;
    }
