#include <iostream>
#include <cstring>
using namespace std;
long long int dp[10][46][46][2];
long long int rr(int idx,bool x,int chan,int le,int X[]){
    if (idx==0)
    {
        if (chan-le==1) return 1;
        else return 0;
    }
    if (dp[idx][le][chan][x]!=-1) return dp[idx][le][chan][x];
    long long int res=0,i;
    int limit,t;
    if (x==0) limit=9;
    else limit=X[idx];
    for (i=0;i<=limit;i++){
        if (i<X[idx]) t=0;
        else t=x;
        if (idx%2==0) res+=rr(idx-1,t,chan+i,le,X);
        else res+=rr(idx-1,t,chan,le+i,X);
    }
    dp[idx][le][chan][x]=res;
    return res;
}
int main()
{
    char a[10],b[10];
    int A[10],B[10];
    int n,m,i,c,l1,c1,l,TEST;
    long long x;
    cin >>TEST;
    while (TEST--){
    cin >>a>>b;
    m=strlen(a);
    n=strlen(b);
    for (i=1;i<=n;i++) B[n-i+1]=b[i-1]-48;
    for (i=1;i<=m;i++) A[m-i+1]=a[i-1]-48;
    memset(dp,255,sizeof(dp));
    x=rr(n,1,0,0,B);
    memset(dp,255,sizeof(dp));
    x=x-rr(m,1,0,0,A);
    l1=l=0,c1=c=0;
    for (i=1;i<=m;i++)
        if (i%2==0) c1+=A[i],l+=A[i];
        else l1+=A[i],c+=A[i];
    if (l-c==1 || c1-l1==1) x++;
    cout <<x<<endl;
    }
    return 0;
}
