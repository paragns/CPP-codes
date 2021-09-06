#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
vector<int> LPS(string &pat){
    int n= pat.size();
    vector<int>lps(n,0);
    for(int i=1;i<n;i++){
		int j=lps[i-1];
		
		while(j>0 and pat[j]!=pat[i]){
				j=lps[j-1];
			}
		if(pat[i]==pat[j]){
			j++;
		}
		lps[i]=j;
		
	}
	return lps;
}
  
// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt,  vector<int>&lps)
{
    int M = pat.size();
    int N = txt.size();

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  		else {
  			if(j!=0)j=lps[j-1];
		  	else i++;
		  }
        if (j == M){
            cout<<"Found pattern at index "<<i-j<<endl;
            j = lps[j - 1];
        }
  
       
    }
} 

// Driver program to test above function
int main()
{
    string txt = "abababab";
    
	string pat = "ababab";
    vector<int>lps=LPS(pat);
    for(int i:lps)cout<<i<<" ";
   // KMPSearch(pat, txt,lps);
    return 0;
}
