#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n,m;
vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
 bool safe(int x, int y, vector<vector<int>>& A){
        if(x>=0 and x<n and y>=0 and y<m)return 1;
        else return 0;
    }
    
    
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T=1;
	//cin>>T;
	 while(T--){
	 	cin>>n>>m;
	 	vector<vector<int>>A(n,vector<int>(m,0));
	 	vector<vector<int>>dist(n,vector<int>(m,inf));
	 
		 for(int i=0;i<n;i++)
	 		for(int j=0;j<m;j++){
			 cin>>A[i][j];
			  }
	 	set<vector<int>>s;
	 	dist[0][0]=A[0][0];
		 s.insert({A[0][0],0,0});
		while(!s.empty()){
		 	auto v=*(s.begin());
		 	s.erase(v);
		 	int x=v[1],y=v[2],w=v[0];
		 	for(int i=0;i<4;i++){
	            int cx=x+dir[i][0];
	            int cy=y+dir[i][1];
	            if(safe(cx, cy, A)){
	            	
					if(dist[cx][cy]>dist[x][y]+A[cx][cy]){
						s.erase({dist[cx][cy],cx,cy});
						dist[cx][cy]=dist[x][y]+A[cx][cy];
						s.insert({dist[cx][cy],cx,cy});
					}
				}
     	   }
		}
	 	cout<< dist[n-1][m-1];
	 }
	
	
return 0;
}
