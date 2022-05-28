#include <bits/stdc++.h>
using namespace std;



int main()
{
	
	int n;
	cin>>n;
	
	string arr[n];
	map<char,int> m;
	
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<arr[i].length();j++){
			m[arr[i][j]]++;
		}
	}
	int flag = 1;
	for(auto x:m){
		if(x.second%n != 0){
			cout<<"Not Possbile";
			flag=0;
			break;
		}
	}
	
	if(flag){
		cout<<"Possible";
	}
	
	
return 0;
}

