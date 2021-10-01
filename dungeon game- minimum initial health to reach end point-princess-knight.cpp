class Solution {
public:
int solve(int i, int j,vector<vector<int>> &p, int M, int N,vector<vector<int>> &dp)
	{
	    if(i>=M || j>=N) return INT_MAX;
            
        if(i==M-1 && j==N-1)
	    return p[i][j]<=0 ? 1+abs(p[i][j]) : 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
            
	    int right = solve(i,j+1,p,M,N,dp);
        int left  = solve(i+1,j,p,M,N,dp);
        int minEnergy = min(left,right)-p[i][j];
        
        return dp[i][j] = (minEnergy<=0) ? 1: minEnergy;
            
 
	}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M=dungeon.size(),N=dungeon[0].size();
        vector<vector<int>>dp(M,vector<int>(N,-1));
        return solve(0,0,dungeon,M,N,dp);
    }
};
