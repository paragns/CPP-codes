//copied from IB
int n,m;
bool safe(int x,int y){
    if(x>=0 and x<n and y>=0 and y<m)return 1;
    else return 0;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    n=A;m=B;
    if(C==E and F==D)return 0;
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    E--;F--;
    C--;D--;
    dist[C][D]=0;
  int dx[]={-2,-2,-1,1,2,2,1,-1};
  int dy[]={-1,1,2,2,1,-1,-2,-2};
    set<vector<int>>s;
    s.insert({dist[C][D],C,D});//{cost[x][y], x,y}{2,1,1},{1,1,1}
    while(!s.empty()){
        auto v=*(s.begin());
        s.erase(s.begin());
        int d=v[0],x=v[1],y=v[2];
    //    cout<<d<<" "<<x<<" "<<y<<endl;
        if(d>=dist[E][F])continue;
        for(int i=0;i<8;i++){
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(safe(cx,cy)){
                 //cout<<dist[cx][cy]<<" "<<cx<<" "<<cy<<endl;
                if(dist[cx][cy]>d+1){
                    s.erase({dist[cx][cy],cx,cy});
                    dist[cx][cy]=d+1;
                    //cout<<dist[cx][cy]<<" "<<cx<<" "<<cy<<endl;
                    s.insert({dist[cx][cy],cx,cy});
                }
            }
        }
    }
    if(dist[E][F]==INT_MAX)return -1;
    return dist[E][F];
}
