#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
int n,a,k;
ifstream fi ("TEST.INP");
ofstream fo ("TEST.out");
int B[10001];
long long int dp[32][32][2][2];
long long int rr(int idx,bool x,int sl,int trc){
    if (idx==0){
        if (sl==k && trc>0){return 1;}
        else return 0;
    }
    if (dp[idx][sl][trc][x]!=-1) return dp[idx][sl][trc][x];
    long long res=0,t,limit;
    if (x==0) limit=1;
    else limit=B[idx];
    for (int i=0;i<=limit;i++){
        if (i<B[idx]) t=0;
        else t=x;
        if (i==1)  {res+=rr(idx-1,t,sl,1);if (res==-1) cout <<"1: "<<idx<<" "<<x<<" "<<sl,system("pause");}
        if (i==0 && trc==1)  {res+=rr(idx-1,t,sl+1,1);if (res==-1) cout <<"2: "<<idx<<" "<<x<<" "<<sl,system("pause");}
        if (i==0 && trc==0) {
            if (idx!=1)  res+=rr(idx-1,t,sl,0);
            else res+=rr(idx-1,t,sl+1,1);
        }
    }
    dp[idx][sl][trc][x]=res;
    //if (res==-1) cout <<idx<<" "<<sl<<" "<<trc<<" "<<x,system("pause");
    return res;
}
int main()
{
    int i;
    long long x;
    int test=100;
    while (cin >>n>>k){
    if (n==0)
    {
        if (k==1) cout <<1<<endl;
        else cout <<0<<endl;
        continue;
    }
    a=n;
    i=0;

    memset(dp,-1,sizeof(dp));
    while (a>0){
        i++;
        B[i]=a%2;
        a/=2;
    }
    n=i;
    //cout <<n;
    //for (i=n;i>0;i--) cout <<B[i];
    x=rr(n,1,0,0);
    cout <<x<<endl;}
    return 0;
}
