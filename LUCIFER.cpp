#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool check(long long int x){
    if (x<=1) return false;
    for (int i=2;i<=sqrt(x);i++){
        if (x%i==0) return false;
    }
    return true;
}
long long int dp[11][46][46][2];
long long int rr(int idx,bool x,int chan,int le,int X[]){
    if (idx==0)
    {
        if (check(chan-le)) return 1;
        else return 0;
    }
    if (dp[idx][chan][le][x]!=-1) return dp[idx][chan][le][x];
    long long int res=0;
    int limit,t,i;
    if (x==0) limit=9;
    else limit=X[idx];
    for (i=0;i<=limit;i++){
        if (i<X[idx]) t=0;
        else t=x;
        if (idx%2==0) res+=rr(idx-1,t,chan+i,le,X);
        else res+=rr(idx-1,t,chan,le+i,X);
    }
    dp[idx][chan][le][x]=res;
    return res;
}
int main()
{
    char a[11],b[11];
    int i,n,m,l1,l,c,c1;
    long long x,TEST;
    int A[11],B[11];
    cin >>TEST;
    while (TEST--){
    cin >>a>>b;
    n=strlen(b);
    m=strlen(a);
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
    if (check(l-c)==1 || check(c1-l1)==1) x++;
    cout <<x<<endl;
    }
    return 0;
}
