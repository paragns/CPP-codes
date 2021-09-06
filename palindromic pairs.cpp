        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        string xoring(string &A,string &B){
    		string par=A;
    		for(int i=0;i<26;i++){
    			par[i]='0'+(A[i]^B[i]);	
    		}
    		return par;
    	} 
int main(){
        	ios_base::sync_with_stdio(false);
        	cin.tie(NULL);
        	int i, j, k, n;
        	cin>>n;
        	vector<string> arr(n);
        	for(i=0;i<n;i++){
        		cin>>arr[i];
        	}
        	
        	string mask="abcdefghijklmnopqrstuvwxyz";
        	string s="";
        	vector<string> ans;
        	unordered_map<string,ll int> freq;
        	for(i=0;i<n;i++){
        		unordered_map<char, int> mp;
        		for(j=0;j<arr[i].size();j++){
        			mp[arr[i][j]]++;
        		}
        		for(j=0;j<26;j++){
        			if(mp[mask[j]]%2==0) s+="0";
        			else s+="1";
        		}
        		//s=0000000010
        		freq[s]++;
        		ans.push_back(s);
        		s="";
        	}
            ll count=0;
    		for(auto i=freq.begin();i!=freq.end();++i){
        		for(int k=0;k<26;k++){
        				string temp="00000000000000000000000000";
    					temp[k]='1';
        				string par=i->first;
    					par=xoring(temp,par);
        				if(freq.find(par)!=freq.end()){
    						count+=freq[par]*i->second;
    					}
        			}	
        	}
        	count/=2;
        		for(auto i=freq.begin();i!=freq.end();++i){
        			ll int temp=i->second;
        		    count+=(temp*(temp-1))/2; 
        		}
        		cout<<count;
     
        	return 0;
        }
