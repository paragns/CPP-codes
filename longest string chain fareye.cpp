class Solution {
public:
    static bool comp(string A, string B){
        return(A.size()<B.size());
        
    }
    bool help(string &A, string &B){
        if(B.size()-A.size()!=1)return 0;
        int j=0,cnt=0;
        for(int i=0;i<B.size();i++){
            if(j<A.size() and A[j]==B[i]){cnt++;j++;}
        }
        if(B.size()-cnt==1)return 1;
        else return 0;
    }
    int func(int in, vector<int> &dp,vector<string> &A){
        if(dp[in]!=-1)return dp[in];
        if(in>=A.size())return 0;
        int ans=1;
        for(int i=in+1;i<A.size();i++){
            if(help(A[in],A[i])){ans=max(ans,1+func(i,dp,A));}
            
        }
        return dp[in]=ans;
    }
    int longestStrChain(vector<string>& A) {
        sort(A.begin(),A.end(),comp);
        vector<int>dp(A.size(),-1);
        for(int i=0;i<A.size();i++)func(i,dp,A);
        // for(string i:A)cout<<i<<" ";
        //cout<<endl;
            for(int i:dp)cout<<i<<" ";
        cout<<endl;
        return *(max_element(dp.begin(),dp.end()));
    }
};
