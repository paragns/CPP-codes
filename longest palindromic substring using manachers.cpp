class Solution {
public:
    string longestPalindrome(string A) {
        int n=A.size();
	 	vector<int>odd(n);
	 	// for odd length palindrome
		 int l=0,r=-1;
	 	for(int i=0;i<n;i++){
			 int k= (i>r)? 1:min(odd[l+r-i],r-i+1);
			 while(i-k>=0 and i+k<n and A[i-k]==A[i+k]){
			 	k++;
			 }
			 odd[i]=k--;
			 if(i+k>r){
			 	l=i-k; 
			 	r=i+k;
			 }
		}
		// cout<<"odd length pali: ";
		// for(int i:odd)cout<<i<<" ";
		// cout<<endl;
		//for even length palindrome
		
        l=0,r=-1;
		vector<int>even(n);
	 	for(int i=0;i<n;i++){
			 int k= (i>r)? 0:min(even[l+r-i+1],r-i+1);
			 while(i-k-1>=0 and i+k<n and A[i-k-1]==A[i+k]){
			 	k++;
			 }
			 
			 even[i]=k--;
			 if(i+k>r){
			 	l=i-k-1; 
			 	r=i+k;
			 }	 
		}
        int maxe=-1;
        vector<vector<int>>ans(2);
        for(int i=0;i<n;i++){
            if(odd[i]>maxe){ans[0]={i-odd[i]+1,2*odd[i]-1};maxe=odd[i];}
        }
        maxe=-1;
        for(int i=0;i<n;i++){
            if(even[i]>maxe){ans[1]={i-even[i],2*even[i]};maxe=even[i];}
        }
        string a=A.substr(ans[0][0],ans[0][1]);
        string b=A.substr(ans[1][0],ans[1][1]);
        
        if(a.size()>b.size())return a;
        else if(b.size()>a.size())return b;
        else if(ans[0][0]<ans[1][0])return a;
        else return b;
    }
};
