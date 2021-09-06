#include <bits/stdc++.h>
using namespace std; 
int n;
int dp[50001];

vector<int>start;
vector<int>endr;
vector<int>prof;

  struct x {
        int s;  /* start time */
        int e;    /* end time */
      
    };
    
    /* Sort by end time */
    static int sfn(x m, x n) {
        return m.e < n.e;
    }


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 memset(dp,-1,sizeof(dp));  
	cin>>n;
	start.resize(n);
	endr.resize(n);
	prof.resize(n);
	for(int i=0;i<n;i++)
	cin>>start[i];
	int m;
	cin>>m;
	
	for(int i=0;i<n;i++){
		cin>> endr[i];
		endr[i]+=start[i];
}
 
  vector<x> y(n);
	
        /* Sort objects by end time */
        for(int i = 0; i < n; i++) { 
		y[i].s = start[i]; y[i].e = endr[i]; 
		}
		
	    sort(y.begin(), y.end(), sfn);
        
        for (int i = 0; i < n; i++) {
            if (!i) { dp[i] = 1; continue; }
            
            int f = 0;  /* find last non-overlapping job that ends before start of this current job and record max profit up to j, dp[j] */
            for (int j = i - 1; j >= 0; j--) 
				if (y[j].e <= y[i].s) { f = dp[j]; break; }		
		    dp[i] = max(dp[i-1],f + 1);
	    }        
	    cout<< dp[n - 1];
return 0;
}
