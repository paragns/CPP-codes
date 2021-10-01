class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& t) 
    {
        if(f == 0 || f == 1)
            return f;
        if(e == 1)
            return f;
        
        if(t[e][f] != -1)
            return t[e][f];
        
        int low = 0, high = f, mn = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            int a = solve(e-1, mid-1, t);
            int b = solve(e, f-mid, t);
            int temp = 1 + max(a, b);
            if(a > b) high = mid-1;
            else low =mid+1;
            mn= min(mn, temp);
        }
        return t[e][f] = mn;
    }
    int superEggDrop(int k, int n) {    
        vector<vector<int>> t(k+1,vector<int>(n+1,-1));
        return solve(k, n, t);
    }
};

