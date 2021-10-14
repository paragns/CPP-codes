   #include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int maxdepth;
 void dfs(int x,vector<vector<int>>& graph,vector<vector<pair<int,int>>>&Q,vector<vector<int>>& tree,vector<int>& ans){
        for(int d=0;d<=maxdepth;d++)tree[d][x>>d]++;
        
        for(auto a:Q[x]){
            int e=a.first;
            int index=a.second;
            
            int val=0;
            for(int d=maxdepth-1;d>=0;d--){
                int val2=val+(1<<d);
                if(tree[d][(e^val2)>>d]>0)val=val2;
            }
            ans[index]=val;
        }
        
        for(int y:graph[x])
            dfs(y,graph,Q,tree,ans);

        for(int d=0;d<=maxdepth;d++)tree[d][x>>d]--;
    }   
vector<int>xorQuery(vector<int> B,vector<int> D,vector<int> E){
        int n=B.size()+1;
        vector<vector<int>>graph(n+1);
        for(int i=0;i<n-1;i++)
            graph[B[i]].push_back(i+2);
        
        int num_query=D.size();
        vector<vector<pair<int,int>>>Q(n+1);
        for(int i=0;i<num_query;i++)
            Q[D[i]].push_back({E[i],i});
        
        vector<int>ans(num_query);

        int p2=2;
        maxdepth=1;
        while(p2<=n){p2*=2;maxdepth++;}
        
        vector<vector<int>>tree(maxdepth+1);
        for(int d=0;d<=maxdepth;d++)tree[d]=vector<int>((p2>>d)+1,0);

        dfs(1,graph,Q,tree,ans);
        
        return ans;
    }

int main(void){
    
    auto a=xorQuery({1,1,2,2,3,3,1},{2,3,5,6,8},{1,1,5,4,10});
    
    for(int x:a)cout<<x<<' ';cout<<endl;
    
    return 0;
}
