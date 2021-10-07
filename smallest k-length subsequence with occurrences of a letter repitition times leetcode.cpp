class Solution {
public:
    int check(int curr, char t, vector<deque<int>> &index){
        if(index[t-'a'].size())return index[t-'a'][0];
        return -1;
    }
    void clean(vector<deque<int>> &index, int curr){
        for(int i=0;i<26;i++){
            while(index[i].size() and index[i].front()<=curr)index[i].pop_front();
        }
    }
    string smallestSubsequence(string A, int k, char let, int rep) {
        string ans="";
        int n=A.size(),cnt=0;
        vector<int>pre(n);
        
        vector<deque<int>>index(26);
        for(int i=0;i<n;i++){
            if(A[i]==let)cnt++;
            pre[i]=cnt;
            index[A[i]-'a'].push_back(i);
        }
        int curr=-1;
        for(int i=0;i<k;i++){
            for(int j=0;j<26;j++){
                char c='a'+j;
                int ind=check(curr,c, index);
                if(ind==-1)continue;
               // cout<<c<<" "<<ind<<endl;
                int rem=k-ans.size()-1;
                if(cnt-pre[ind]>=rep-(c==let) and rem>=rep-(c==let) and rem<=n-ind-1){
                    ans+=c;
                    rep=rep-(c==let);
                    curr=ind;
                    clean(index,curr);
                    break;
                }
            }
        }
        return ans;
    }
};
