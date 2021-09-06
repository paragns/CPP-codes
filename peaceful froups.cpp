    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int i, n;
    	cin>>n;
    	unordered_map<int, int> last;
    	vector<int> line(n);
    	unordered_map<int, int> freq;
    	
    	int start=0, end=0, maxocc=0;
    	
    	for(i=0;i<n;i++){
    		cin>>line[i];
    		freq[line[i]]++;
    	}
    	
    	for(i=0;i<n;i++)
    		last[line[i]]=i;
    	
    	
    	i=0;
    	 int ans=0; 
    	while(start<n){
    		if(last[line[i]]>end) end=last[line[i]];
    		if(freq[line[i]]>maxocc) maxocc=freq[line[i]];
    		if(i==end){
    			ans+=end-start+1-maxocc;
    			maxocc=0;
    			start=end+1;
    		}
    		i++ ;
    	}
    	cout<<ans;
    	return 0;
    }
