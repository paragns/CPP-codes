// code taken from IB;

vector<string>ans;
void func(int in, string &A, int cnt, string t){
    //cout<<in<<" "<<cnt<<endl;
    int n=A.size();
    if(in==n and cnt==4){t.pop_back(); ans.push_back(t);return; }
    if(in>=n )return;
    if(cnt>4)return;
    
    int num=0;
    for(int i=in;i<min(in+3,n);i++){
        num=(num*10 +(A[i]-'0'));
      //  cout<<num<<" ";
        if(num==0){
            t+=A[i];
            t+='.';
            func(i+1,A,cnt+1,t);
            return;
        }
        else{
            t+=A[i];
            t+='.';
            if(num>0 and num<=255){func(i+1,A,cnt+1,t);t.pop_back();}
            else return;
        }
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    ans.clear();
    string t="";
    func(0,A,0,t);
    return ans;
}

