#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int s1,s2,s3,n,m,mod,ans;
int a[70][70],f[70][70][70],d[70];
bool b[70];
int dp(int x)
{
    for(int i=1;i<=n;i++)b[i]=0;
    int sum=0,p;
    for(int i=1;i<=n;i++)
       if(!b[i])
       {
           d[++sum]=1;p=i;
           b[p]=1;
           while(!b[a[x][p]])
           {
               d[sum]++;
               b[a[x][p]]=1;
               p=a[x][p];
           }
       }
    for(int i=s1;i>=0;i--)
        for(int j=s2;j>=0;j--)
            for(int k=s3;k>=0;k--)
                f[i][j][k]=0;
    f[0][0][0]=1;
    for(int h=1;h<=sum;h++)
        for(int i=s1;i>=0;i--)
            for(int j=s2;j>=0;j--)
                for(int k=s3;k>=0;k--)
                {
                    if(i>=d[h])f[i][j][k]=(f[i][j][k]+f[i-d[h]][j][k])%mod;
                    if(j>=d[h])f[i][j][k]=(f[i][j][k]+f[i][j-d[h]][k])%mod;
                    if(k>=d[h])f[i][j][k]=(f[i][j][k]+f[i][j][k-d[h]])%mod;
                }
    return f[s1][s2][s3];
}
void exgcd(int a,int b,int &x,int &y)
{
     if(b==0){x=1;y=0;return;}
     exgcd(b,a%b,x,y);
     int t=x;x=y;y=t-a/b*y;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("HZWER.out","w",stdout);
    s1=read(),s2=read(),s3=read(),m=read(),mod=read();
    n=s1+s2+s3;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=read();
    m++;
    for(int i=1;i<=n;i++)a[m][i]=i;
    for(int i=1;i<=m;i++)
        ans=(ans+dp(i))%mod;
    int x,y;
    exgcd(m,mod,x,y);
    while(x<=0)x+=mod,y-=m;
    printf("%d",ans*x%mod);
    return 0;
}
