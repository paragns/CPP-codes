#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
bool safe(int x, int y){
	if(x>=0 and x<8 and y>=0 and y<8)return 1;
	else return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>>dir={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	vector<vector<int>>chess(8,vector<int>(8,0));
	 	int x1,y1;
	 	cin>>x1>>y1;//1,2
		int p=6;//no. of pawns
		chess[2][4]=1;
		chess[3][2]=1;
		chess[3][6]=1;
		chess[4][4]=1;
		chess[5][6]=1;
		chess[6][4]=1;
		int t=1;
		//numbering the pawns
		for(int i=0;i<8; i++)
			for(int j=0;j<8;j++){
				if(chess[i][j])chess[i][j]=t++;
			}
				
		//int mask=0;//no. of pawns dead
		vector<vector<vector<int>>>dp(8,vector<vector<int>>(8,vector<int>((1<<p),inf)));
	 	//vector<vector<vector<int>>>vis(8,vector<vector<int>>(8,vector<int>((1<<p),0)));
		
		queue<vector<int>>q;
		// this code assumes that there is no pawn at x1,y1 else we push{x1,y1, 1<<(chess[x1][y1])}
		q.push({x1,y1,0});
	 	dp[x1][y1][0]=0;
	 	int ans=inf;
	 	while(!q.empty()){
			auto v=q.front();
			q.pop();
			int x=v[0],y=v[1],bit=v[2];
			//cout<<x<<" "<<y<<" "<<bit<<" "<<dp[x][y][bit]<<endl;
			if(bit==((1<<p)-1)){ans=min(ans,dp[x][y][bit]); continue;}
			for(int i=0;i<8;i++){
				int cx=x+dir[i][0];
				int cy=y+dir[i][1];
				if(safe(cx,cy) and dp[cx][cy][bit]==inf ){
					int t=chess[cx][cy];
					int check=bit&(1<<(t-1));
					if(check!=0){continue;}
					if(t!=0){
						q.push({cx,cy,(bit|(1<<(t-1)))});
						//vis[cx][cy][(bit|(1<<(t-1)))]=1;
						//vis[cx][cy][bit]=1;
							if(cx==3 and cy==6 and bit ==1)cout<<cx<<" "<<cy<<" "<<(bit|(1<<(t-1)))<<endl;
						dp[cx][cy][(bit|(1<<(t-1)))]=min(dp[cx][cy][(bit|(1<<(t-1)))],1+dp[x][y][bit]);
						dp[cx][cy][bit]=min(dp[cx][cy][bit],1+dp[x][y][bit]);
					}
					else {
						q.push({cx,cy,bit});
						//vis[cx][cy][bit]=1;
						dp[cx][cy][bit]=min(dp[cx][cy][bit],1+dp[x][y][bit]);
					}
				}
			} 
		}
		cout<<ans;
	}
return 0;
}
/*
01234567
00000000
00000000
00001000
00100010
00001000
00000010
00001000
00000000
*/
