#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int>CalculateZ(string &A){
    int n = A.size();
    vector<int>Z(n, 0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            //outside z box
            l=i; r=i;
            while(r<n and A[r]==A[r-l]){
                r++;
            }
            Z[i]=r-l;
            r--;
        }else{
            //inside z box
           if(i+Z[i-l]<=r){
                Z[i]=Z[i-l];  //copy previously computed value;
           }
           else{
                l=i;    // Shift left boundary of Z-box to i i.e new box is forming
                while(r<n and A[r]==A[r-l]){
                    r++;
                }
                Z[i]=r-l;
                r--;
            }
        }
    }
    return Z;
}
int main(){
    string text ="ABABABABA";
    string pattern="BAB";
    int n = text.size();
    int m = pattern.size();
    string comb = pattern+'&'+text;
    vector<int>Z = CalculateZ(comb);

    for(int i=0;i<Z.size();i++){
        if(Z[i]==m)cout<<"Pattern found at index "<<i-m-1<<endl;
    }
    return 0;
}