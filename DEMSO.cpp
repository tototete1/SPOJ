#include <bits/stdc++.h>
using namespace std;
int d,r;
long long int dp[17][11][20][2][2];
long long int rr(int n,int idx,bool x,int sl,int trc,bool w,int X[])
{
    if (idx==0)
    {
        if (sl<=d && w>0)
            return 1;
        else
            return 0;
    }
    if (dp[idx][trc][sl][x][w]!=-1)
        return dp[idx][trc][sl][x][w];
    int limit,t,i;
    long long int res=0;
    if (x==0)
        limit=9;
    else
        limit=X[idx];
    //if (idx==2) cout <<limit;
    if (idx==n)
    {
        for (i=0; i<=X[idx]; i++)
            res+=rr(n,idx-1,0+(i==X[idx]),0,i,w+(i!=0),X);
    }
    else
    {
        for (i=0; i<=limit; i++)
        {
            if (i<X[idx])
                t=0;
            else
                t=x;
            if (w==0){
                if (i==0 && idx!=1) res+=rr(n,idx-1,t,sl,i,0,X);
                if (idx==1 && i==0) {res+=rr(n,idx-1,t,sl,i,0,X);}
                if (idx==1 && i!=0){res+=rr(n,idx-1,t,sl,i,1,X);}
                if (idx>1 && i!=0)
                {
                    res+=rr(n,idx-1,t,sl,i,1,X);
                }
            }
            else{
                if (abs(i-trc)<=r) res+=rr(n,idx-1,t,sl+1,i,1,X);
                else res+=rr(n,idx-1,t,sl,i,1,X);
            }
        }
    }
    dp[idx][trc][sl][x][w]=res;
    return res;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    char a[17],b[17];
    int A[17],B[17];
    int n,m,i;
    long long int x;
    cin >>a>>b>>r>>d;
    n=strlen(b);
    for (i=1; i<=n; i++)
        B[n-i+1]=b[i-1]-48;

    x=rr(n,n,1,0,0,0,B);
    memset(dp,-1,sizeof(dp));
    m=strlen(a);
    for (i=1; i<=m; i++)
        A[m-i+1]=a[i-1]-48;
    x=x-rr(m,m,1,0,0,0,A);
    int res=0;
    if (m==1){
        x++;
    }
    else
    {
        for (i=2; i<=m; i++)
        {
            if (abs(A[i-1]-A[i])<=r)
                res++;
        }
        if (res<=d)
            x++;
    }
    cout <<x;
}
