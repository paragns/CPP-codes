class Solution {
public:
    #define inf 1000000
    #define ll  long long
    vector<vector<ll int>>dp;
    ll int f(int s, int e, int k,vector<int>&A){
        int l=e-s;
        if(dp[s][e]!=inf)return dp[s][e];
        if(l<k or s>e)return 0;
        ll int sum=0;
        for(int i=s;i<e;i++)sum+=A[i];
        if(l==k)return dp[s][e]=sum;
        
        if((l-1)%(k-1)!=0){
            sum=0;
        }
        ll int res=inf;
        for(int i=s+1;i<e;i+=k-1){
            res=min(res, f(s,i,k,A)+f(i,e,k,A));
        }
        cout<<res<<" ";
     //   if(res==inf)
        return dp[s][e]=sum+res;
    }
    int mergeStones(vector<int>& A, int k) {
        int l=A.size();
        if((l-1)%(k-1)!=0)return -1;
        dp.resize(31,vector<ll int>(31,inf));
         return f(0,l,k,A);   
    }
};
