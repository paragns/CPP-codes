    #include <bits/stdc++.h>
    using namespace std;
    int dp[51][51][51];
    vector<vector<int>>A;
    int n;
      bool safe(int x1,int y1){
      	if(x1>=0 and y1>=0 and x1<n and y1<n and A[x1][y1]!=-1)return 1;
      	else return 0;
      }
      
      int func(int x1,int y1,int x2,int y2){
    	if(dp[x1][y1][x2]!=-1)return dp[x1][y1][x2];
    	 int ans=0;
    	 if(A[x1][y1]==1)ans++;
    	 if(x1!=x2 or y1!=y2 ){
    	 	if(A[x2][y2]==1)ans++;
    	 }
    	 if(x1==n-1 and x2==n-1 and y1==n-1)return dp[x1][y1][x2]=ans; 
    	 
    	 int l=INT_MIN;
    	 if(safe(x1,y1+1) and safe(x2,y2+1)){
    	 		l=max(l,func(x1,y1+1,x2,y2+1));
    	 }
    	 if(safe(x1,y1+1) and safe(x2+1,y2)){
    	 	l=max(l,func(x1,y1+1,x2+1,y2));
    	 }
    	 if(safe(x1+1,y1) and safe(x2+1,y2)){
    	 	l=max(l,func(x1+1,y1,x2+1,y2));
    	 }
    	 if(safe(x1+1,y1) and safe(x2,y2+1)){
    	 	l=max(l,func(x1+1,y1,x2,y2+1));
    	 }
    	 if(l==INT_MIN)return dp[x1][y1][x2]= INT_MIN;
    	 else return dp[x1][y1][x2]=ans+l;
    	}
    	
      
    // Driver code
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	memset(dp,-1,sizeof(dp));
    	cin>>n;
    	A.resize(n,vector<int>(n,0));
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			cin>>A[i][j];
    			
    	cout<<max(0,func(0,0,0,0));
     
    return 0;
    }
