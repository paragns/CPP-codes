#include <bits/stdc++.h>
using namespace std;
# define ll long long

vector<ll int>X,Y;
bool comp1(int i, int j){
	if(X[i]<X[j])return 1;
	else return 0;
}

bool comp2(int i, int j){
	if(Y[i]<Y[j])return 1;
	else return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll int n,tot=0;
	cin>>n;
	vector<ll int>A(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
		tot+=A[i];
	}
	
	cin>>n;
	X.resize(n);
	for(int i=0;i<n;i++){
		cin>>X[i];
	}
	
	cin>>n;
	Y.resize(n);
	for(int i=0;i<n;i++){
		cin>>Y[i];
	}
	
	ll int med_x=0,med_y=0;
	vector<int>order(n);
	iota(order.begin(),order.end(),0);
	
	sort(order.begin(),order.end(),comp1);
	
	ll int a=0,b=0;
	
	for(int i:order){
		if(a+A[i]>=tot/2 +1){med_x=X[i]; break;}
		a+=A[i];
	}
	
	sort(order.begin(),order.end(),comp2);
	for(int i:order){
		if(b+A[i]>=tot/2 +1){med_y=Y[i]; break;}
		b+=A[i];
	}
	
	ll int ans=0;
    for(int i=0;i<n;i++){
        ans+=(abs(X[i]-med_x)+abs(Y[i]-med_y))*A[i];
    }
 
    cout<<ans<<endl;
 
	
	
return 0;
}


