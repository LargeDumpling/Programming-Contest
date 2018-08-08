#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;
 
const int N=100005;
 
int f[2][10][10][10],pos[2][10][10][10],n,m,l,r,T[N][10],G[N][10];
char s[N];
 
void Update(int a,int b,int c,int d,int e,int g)
{
    if(f[a][b][c][d]<e)
        f[a][b][c][d]=e,pos[a][b][c][d]=g;
}
 
void solve()
{
    scanf("%d %s",&n,s+1);
    m=0;l=r=1;
    for(int i=1;i<=n;i++)
        s[i]-='0';
    for(int i=0;i<=9;i++)
        T[n+1][i]=0;
    for(int i=n;i;i--)
        for(int j=9;j>=0;j--)
            T[i][j]=max(T[i+1][j]+(s[i]==j),j==9?0:T[i][j+1]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=9;j++)
            G[i][j]=max(G[i-1][j]+(s[i]==j),j==0?0:G[i][j-1]);//,cout<<i<<" "<<j<<" "<<G[i][j]<<endl;
    memset(f,-1,sizeof f);memset(pos,0,sizeof pos);
    for(int i=1;i<=n;i++)
    {
        int Now=i&1,Pre=Now^1;
        memset(f[Now],-1,sizeof(f[Now]));
        memset(pos[Now],0,sizeof(pos[Now]));
        for(int a=0;a<=9;a++)
            for(int b=0;b<=9;b++)
                for(int c=b;c>=a;c--)
                {
                    Update(Now,a,b,c,f[Pre][a][b][c]+(s[i]==c),pos[Pre][a][b][c]);
                    if(c!=b)
                        Update(Now,a,b,c,f[Now][a][b][c+1],pos[Now][a][b][c+1]);
                    Update(Now,a,b,c,G[i-1][a]+(s[i]==c),i);
                }
        for(int a=0;a<=9;a++)
            for(int b=0;b<=9;b++)
                for(int c=b;c>=a;c--)
                {
                    int k=f[Now][a][b][c]+T[i+1][b];
                    if(k>m)
                        m=k,l=pos[Now][a][b][c],r=i; 
                }
    }
    if(l==0)
        l=r=1;
    cout<<m<<" "<<l<<" "<<r<<endl;
}
 
int main()
{
	freopen("H.in","r",stdin);
	freopen("H_other.out","w",stdout);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}
