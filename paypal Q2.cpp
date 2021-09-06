//This is a simple brute force soln that passed all test cases.

#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

int minDist(int w, int h, vector<pi> arr){

    int res = 0;

    // for(auto it: arr) cout<<it.first<<" "<<it.second<<endl;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int k1 = 10000;
            for(auto it: arr){
                int k = abs(i - it.first) + abs(j - it.second);
                k1 = min(k1, k);
            }
            res = max(k1, res);
        }
    }

    return res;
}


int findMinDistance(int w, int h, int n) {

    vector<pi> points;

    int ans = INT_MAX;
    int tot = w*h;

    for(int i = 0; i < tot; i++){
        int xi = i/w, yi = i%w;
        points.push_back({xi, yi});
        if(n == 1) ans = min(ans, minDist(w, h, points));
        if(n > 1){
            for(int j = i+1; j < tot; j++){
                int xj = j/w, yj = j%w;
                points.push_back({xj, yj});
                if(n == 2) ans = min(ans, minDist(w, h, points));
                if(n > 2){
                    for(int k = j+1; k < tot; k++){
                        int xk = k/w, yk = k%w;
                        points.push_back({xk, yk});
                        if(n == 3) ans = min(ans, minDist(w, h, points));
                        if(n > 3){
                            for(int l = k+1; l < tot; l++){
                                int xl = l/w, yl = l%w;
                                points.push_back({xl, yl});
                                if(n == 4) ans = min(ans, minDist(w, h, points));
                                if(n > 4){
                                    for(int m = l+1; m < tot; m++){
                                        int xm = m/w, ym = m%w;
                                        points.push_back({xm, ym});
                                        ans = min(ans, minDist(w, h, points));
                                        points.pop_back();
                                    }
                                }
                                points.pop_back();
                            }
                        }
                        points.pop_back();
                    }
                }
                points.pop_back();
            }
        }
        points.pop_back();
    }


    return ans;
}
#include <bits/stdc++.h>
using namespace std;

  
// Driver code
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k,l;
	cin>>n>>k>>l;
	cout<< findMinDistance(n,k,l);
	
return 0;
}
