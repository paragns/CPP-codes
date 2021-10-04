class Solution {
public:
    int dp[101];
    vector<int>A;
    int n;
    int maxmoney(int indx){
        if(dp[indx]!=-1)return dp[indx];
        if(indx==n-2)return dp[indx]=max(A[indx],A[indx+1]);
        if(indx==n-1)return dp[indx]=A[indx];
        return dp[indx]=max(maxmoney(indx+1),A[indx]+maxmoney(indx+2));
    }
    int rob(vector<int>& nums) {
        A=nums;
        n=A.size();
        memset(dp,-1,sizeof(dp));
        return maxmoney(0);
        
    }
};
