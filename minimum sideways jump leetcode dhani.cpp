class Solution {
public:
    vector<vector<int>> dp;
    int M(int lane, int i, vector<int> &A){
        if(i==A.size()-1) return 0;
        if(dp[i][lane]!=-1) return dp[i][lane];
        //if(A[i]-1==lane) return INT_MAX/2;
        if((A[i+1]-1)==lane){
            int x=INT_MAX;
            if(A[i]-1!=(lane+1)%3) x = 1+M((lane+1)%3,i+1,A);
            if(A[i]-1!=(lane+2)%3) x = min(x,1+M((lane+2)%3,i+1,A));
            return dp[i][lane]=x;
        }
        else return dp[i][lane]= M(lane,i+1,A);
    }
    int minSideJumps(vector<int>& A) {
        int n=A.size();
        dp.resize(n+1,vector<int>(4,-1));
        return M(1,0,A);
    }
};
