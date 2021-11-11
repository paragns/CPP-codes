#include<bits/stdc++.h>
using namespace std;
bool safe(int x, int y){
	if(x>=0 and x<8 and y>=0 and y<8)return 1;
	return 0;
}
vector<vector<int>>dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1}};
int main(){
	int T;
	cin>>T;
	while(T--){
		string A,B;
		cin>>A>>B;
		int sx,sy,ex,ey;
		sx=A[0]-'a';
		sy=A[1]-'1';
		ex=B[0]-'a';
		ey=B[1]-'1';
		//cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
		vector<vector<int>>chess(8,vector<int>(8,0));
		queue<vector<int>>q,q2;
		q.push({sx,sy});
		chess[sx][sy]=1;
		int ans=0;
		while(!q.empty()){
			int sz=q.size();
			ans++;
			while(sz--){
				auto t=q.front();
				int x=t[0],y=t[1];
				q.pop();
				if(x==ex and y==ey){q=q2;break;}
				for(int i=0;i<8;i++){
					int cx=x+dir[i][0],cy=y+dir[i][1];
					if(safe(cx,cy) and chess[cx][cy]==0){
						q.push({cx,cy});
						chess[cx][cy]=1;
					}
				}
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;	
}
