#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n,m;
bool safe(int x,int y, auto A){
    if(x>=0 and x<n and y>=0 and y<m and A[x][y]=='.')return 1;
    else return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	  cin>>n>>m;
	  vector<vector<char>>A(n,vector<char>(m));
	  for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)cin>>A[i][j];
	  
	  int k;cin>>k;
    vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[0][0]=0;
    set<vector<int>>s;
    s.insert({dist[0][0],0,0});
    while(!s.empty()){
        auto v=*(s.begin());
        s.erase(s.begin());
        int d=v[0],x=v[1],y=v[2];
        for(int i=0;i<4;i++){
            int cx=x+dir[i][0];
            int cy=y+dir[i][1];
            if(safe(cx,cy,A)){
                if(dist[cx][cy]>d+1){
                    s.erase({dist[cx][cy],cx,cy});
                    dist[cx][cy]=d+1;
                    //cout<<dist[cx][cy]<<" "<<cx<<" "<<cy<<endl;
                    s.insert({dist[cx][cy],cx,cy});
                }
            }
        }
    }
    if(dist[n-1][m-1]<=k)cout<<"Yes";
    else cout<<"No";
	}
return 0;
}
