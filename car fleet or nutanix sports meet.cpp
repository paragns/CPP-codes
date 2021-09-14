//car fleet or nutanix sports meet
//from leetcode
class Solution {
public:
     int carFleet(int t, vector<int>& A, vector<int>& S) {
        if(A.size()==1)return 1;
        vector<vector<int>>p;
        for(int i=0;i<A.size();i++){
             p.push_back({A[i],S[i]});
        }
         
        sort(p.begin(),p.end(),greater<vector<int>>());
        int i=0,ans=1;
         double ul=(1.0*(t-p[i][0]))/(1.0*p[i][1]);
        //cout<<ul<<endl;
         for(i=1;i<A.size();i++){
            double temp=(1.0*(t-p[i][0]))/(1.0*p[i][1]);
             //cout<<ul<<" "<<temp<<endl;
            if(temp>ul){ans++; ul=temp;}
        }
        return ans;
        
    }
};
