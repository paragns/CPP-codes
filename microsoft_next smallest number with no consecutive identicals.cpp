#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define mod 1000000007
#define inf INT_MAX
#define minf INT_MIN
int func(int num){
	string A=to_string(num);
	for(int i=1;i<A.size();i++){
		if(A[i-1]==A[i])return 0;
	}
	 return 1;
}
void free(string &A, int n, int t){

	while(A.size()!=n){
		A.push_back((char)('0'+t));
		t^=1;
	}
	return;
}
string numb(string &A){
	int num=0;
	for(int i=0;i<A.size();i++){
		num*=10;
		num+=(A[i]-'0');
	}
	num++;
	return to_string(num);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int T=1;
	//cin>>T;
	 while(T--){
	 	int n;
	 	cin>>n;
	 	n++;
	 	int num=n;
	 	while(func(n)==0){
			n++; 
		}
		cout<<n<<endl;
		string A=to_string(num);
		for(int i=0;i<A.size();i++){
			if(A[i]==A[i-1]){
				int t=0;
				if(A[i]=='9') t=1;
				string temp=A.substr(0,i+1);
				temp=numb(temp);
				int sz=A.size();
				free(temp,sz,t);
				A=temp;
				break;
			}	
		}
		cout<<A;
	}
return 0;
}
