class Solution {
public:
    
    int check( string & A, int num, int n){
        vector<int>ind;
        for(int i=0;i<=12;i++){
            if(num&(1<<i)){
                ind.push_back(n-1-i);     
                          }
        }
        
        int i=0,j=ind.size()-1;
        while(i<=j){
            if(ind[i]<0 or ind[j]<0)return 0;
            if(A[ind[i]]!=A[ind[j]])return 0;
            i++;j--;
        }
        return 1;
    }
    int maxProduct(string s) {
        int n=s.size();
        if(n<2)return 0;
        int ans=-1;
        vector<int>st;
        for(int num=1;num<(1<<12);num++){ 
            if(check(s,num,n)){
                
                for(int i:st){
                    if(!(num&i)){
                       ans=max(ans, __builtin_popcount(num)*__builtin_popcount(i));   
                    }
                }
                st.push_back(num);
            }
        } 
        return ans;    
    }
};
