#define ll long long
#define mod 1000000007 
vector<int> Solution::solve(string A, vector<string> &B) {
vector<ll int>hashes={130651,169627,95789,197101,104803,176509,113909,172597,6221,86269,188999,166867,4271,177787,172709,79151,155153,40897,156781,26459,176087,86243,164309,40597,181397,39791};
    ll int m = B.size(),n=A.size();
    vector<ll int> sum(m,0);
    vector<int> ans(m,0);
    
    unordered_map <ll int,vector<ll int>> mp;
    
    vector<ll int>pref(n);
    if(n==0)return ans;
    pref[0]=hashes[A[0]-'a'];
    for(int i=1;i<n;i++){
        pref[i]=(pref[i-1]+hashes[A[i]-'a']);
    }
    
    for(int i=0;i<m;i++){
        int s = B[i].size();
        if(s>A.size()) ans[i] = 0;
        else{
            for(int j=0;j<s;j++){
                sum[i] = (sum[i]+ hashes[B[i][j]-'a']);
            }
            mp[s].push_back(i);
        }
    }
    
    for(auto j:mp){
       // cout<<"*";
        int sz = j.first;
        
        vector<ll int>v=j.second;
       
        unordered_map<ll int,ll int>sp;
        for(auto p:v) sp[sum[p]]=0;
         if(sp.find(pref[sz-1])!=sp.end())sp[pref[sz-1]]++;
        for(int i = sz; i < n; i++){
             ll int temp=pref[i]-pref[i-sz];
             if(sp.find(temp)!=sp.end())sp[temp]++;
        }
        for(auto p:v)
        ans[p] = sp[sum[p]];
         //cout<<"&"<<endl;
    }
    return ans;
}
