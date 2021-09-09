//copied from IB
int n,m;
bool safe(int x,int y){
    if(x>=0 and x<n and y>=0 and y<m)return 1;
    else return 0;
}
int Solution::solve(int A, int B, vector<string> &c) {
    n=A,m=B;
    vector<char>ch={'U','R','D','L'};
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
            if(safe(cx,cy)){
                if(dist[cx][cy]>d+(c[x][y]!=ch[i])){
                    s.erase({dist[cx][cy],cx,cy});
                    dist[cx][cy]=d+(c[x][y]!=ch[i]);
                    //cout<<dist[cx][cy]<<" "<<cx<<" "<<cy<<endl;
                    s.insert({dist[cx][cy],cx,cy});
                }
            }
        }
    }
    return dist[n-1][m-1];
}

