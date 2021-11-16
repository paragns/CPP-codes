#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int n,m;
vector<string>A;
bool safe(int x, int y, char t){
	if(x>=0 and x<n and y>=0 and y<m and (A[x][y]==t or A[x][y]=='.'))return 1;
	else return 0;
}
vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
int dijkstra(auto &dist, char c){
	set<vector<int>>s;
	s.insert({0,0,0});
	dist[0][0]=0;
	while(!s.empty()){
		auto t=*(s.begin());
		s.erase(s.begin());
		int x=t[1],y=t[2],w=t[0];
		for(int i=0;i<4;i++){
			int cx=x+dir[i][0],cy=y+dir[i][1];
			if(safe(cx,cy,c)){
				if(dist[cx][cy]>w+1){
					dist[cx][cy]=w+1;
					s.insert({dist[cx][cy],cx,cy});
				}
			}
		}
	}
	if(dist[n-1][m-1]==INT_MAX/2)return -1;
	return dist[n-1][m-1];
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	
	cin>>n>>m;
	A.resize(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	vector<vector<int>>dist1(n+1,vector<int>(m+1,INT_MAX/2));
	auto dist2=dist1;
	cout<<dijkstra(dist1,'*');
	cout<<dijkstra(dist2,'#');
return 0;
}
