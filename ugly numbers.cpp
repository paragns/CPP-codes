class Solution {
public:
    int nthUglyNumber(int n) {
     int p2=0,p3=0,p5=0;
        vector<long long int>dp;
        dp.push_back(1);
        while(dp.size()<n){
            int next=min({2*dp[p2],3*dp[p3],5*dp[p5]});
            if(next==2*dp[p2])p2++;
             if(next==3*dp[p3])p3++;
                if(next==5*dp[p5])p5++;
            dp.push_back(next);
        }
        return dp[n-1];
    }
};//{1 2 3 4 5 6}
