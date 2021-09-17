#include <bits/stdc++.h>
using namespace std;
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin>>n;
    vector<vector<int>> v(100005),u(100005);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=0;i<100005;i++)sort(v[i].begin(),v[i].end());
    for(int i=0;i<100005;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=j+1;k<v[i].size();k++){
                if(v[i][k]==v[i][k-1])continue;
                int d=v[i][k]-v[i][j];
                u[v[i][j]].push_back(d);
                // cout<<v[i][j]<<" "<<d<<"\n";
            }
        }
    }
 
for(int i=0;i<100005;i++)sort(u[i].begin(),u[i].end());
    int ans=0;
    for(int i=0;i<100005;i++){
        int t=1;
        if(u[i].size()==0)continue;
        for(int j=1;j<u[i].size();j++){
            if(u[i][j]==u[i][j-1])
                t++;
            else{
                ans=max(ans,t);
                t=1;
            }
        }
        ans=max(ans,t);
    }
    cout<<ans;
 
 
 
	return 0;	
 
}
