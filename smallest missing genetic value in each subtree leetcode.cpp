class Solution {
public:
    unordered_set<int>s;
    map<int, int>mp;
    vector<vector<int>>adj;
    void dfs(int node,vector<int> &nums){
        mp.erase(nums[node]);
        for(int i:adj[node]){
            if(s.find(i)!=s.end()) continue;
            dfs(i,nums);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int node=-1,mode,n=nums.size();
        adj.resize(n);
        for(int i=0;i<nums.size();i++){
            if(i!=0)adj[parents[i]].push_back(i);
            if(nums[i]==1)node=i;
        }
       if(node==-1){
           vector<int>ans(nums.size(),1);
           return ans;
       }
        for(int i=1;i<=nums.size()+1;i++)mp[i]++;
        vector<int>ans(nums.size(), INT_MAX);
        
        while(node!=-1){
            s.insert(node);
            dfs(node,nums);
            ans[node]=(mp.lower_bound(1))->first;
            node=parents[node];
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(i)==s.end())ans[i]=1;
        }
        return ans;
    }
};
