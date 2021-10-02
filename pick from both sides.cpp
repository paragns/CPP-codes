int helper(vector<int>&A,int i,int j,int B ,vector<vector<int>>&dp){
    if(B==0)return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i>=A.size()or j<0)return 0;
    return dp[i][j]=max(A[i]+ helper(A,i+1,j,B-1,dp),A[j]+helper(A,i,j-1,B-1,dp));
}
int Solution::solve(vector<int> &A, int B) {
    vector<vector<int>>dp(A.size(),vector<int>(A.size(),-1));
    int sum=0;
    if(B>=A.size()){
        for(int i=0;i<A.size();i++)sum+=A[i];
        return sum;
        
    }
    
    return helper(A,0,A.size()-1,B,dp);
}
// A = [5, -2, 3 , 1, 2]
