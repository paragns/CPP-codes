#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

void DFS(vector<vector<int>> &Graph, vector<bool> &Visited, int i, int &count){
	Visited[i]=true;
    count++;
    for(auto x:Graph[i]){
        if(!Visited[x]){
            DFS(Graph,Visited,x,count);
        }
    }
}

int main(){
	fast_io;
	
	int tests;
	cin>>tests;

	while(tests--){
        ll N,R,c,r;
        cin>>N>>R>>c>>r;

        vector<vector<int>> Graph(N+1);
        for(int i=0;i<R;i++){
            int x,y;
            cin>>x>>y;
            Graph[x].push_back(y);
            Graph[y].push_back(x);
        }
        ll ans=0;
        if(c<=r){
            ans=c*N;
            cout<<ans<<endl;
            continue;
        }
        vector<bool> Visited(N+1);
        for(int i=1;i<=N;i++){
            if(!Visited[i]){
                int count=0;
                DFS(Graph,Visited,i,count);
                ll roads=count-1;
                ans+=c+(roads*r);
            }
        }
        cout<<ans<<endl;
    }
	
	return 0;
}
