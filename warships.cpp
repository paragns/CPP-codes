    #include <bits/stdc++.h>
    using namespace std;
     
    /* ### READ-ONLY PART ### */
    int warShips(int input1, int input2)
    /* ### READ-ONLY PART ### */
    {
    	int max_layers = input1;
    	int mod = input2;
     
    	/* dp[v][layer] is the size of subtree rooted at 'v' in layer 'layer' */
    	vector<vector<int>> dp(mod + 2, vector<int>(max_layers + 2));
     
    	for(int layer = max_layers; layer > 0; layer--)
    	{
    		for(int v = 0; v < mod; v++)
    		{
    			int upper = (v*v + 1)%mod;
    			if(upper == 0)
    			{
    				dp[v][layer] = 1;
    				continue;
    			}
     
    			dp[v][layer] = (1 + dp[upper - 1][layer + 1])%mod;
    		}
     
    		if(layer == 1)
    			break;
     
    		for(int v = 1; v < mod; v++)
    			dp[v][layer] = (dp[v][layer] + dp[v - 1][layer])%mod;
    	}
     
    	return dp[2][1];
    }
     
    int main()
    {
    	int input1, input2;
    	cin >> input1 >> input2;
     
    	cout << warShips(input1, input2);
    	cout << endl;
    	return 0;
    }
