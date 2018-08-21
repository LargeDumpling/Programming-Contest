/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
    2018-08-20    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=81;
int T_T;
long long K,f[MAXN][MAXN][MAXN*MAXN],fac[MAXN*MAXN],n,m;
void pre_calc()
{
    fac[0]=1;
    for(int i=1;i<=n*m;i++)
        fac[i]=fac[i-1]*i%K;
    return;
}
long long calc(long long i,long long j,long long k)
{
	/*if(i>j)
	{
		swap(i,j);
		swap(n,m);
	}*/
    if(f[i][j][k]!=-1) return f[i][j][k];
	if(f[j][i][k]!=-1) return f[i][j][k]=f[j][i][k];
    if((!i)||(!j)) return f[i][j][k]=fac[k];
    f[i][j][k]=0;
    f[i][j][k]=(f[i][j][k]+calc(i,j-1,k-1)*j%K*(n-i)%K)%K;
    f[i][j][k]=(f[i][j][k]+calc(i-1,j,k-1)*i%K*(m-j)%K)%K;
    if((n-i)*(m-j)>n*m-k)
        f[i][j][k]=(f[i][j][k]+calc(i,j,k-1)*((k+i*j%K-i*m%K+K-j*n%K+K)%K)%K)%K;
    return f[i][j][k];
}
void clear(long long i,long long j,long long k)
{
	/*if(i>j)
	{
		swap(i,j);
		swap(n,m);
	}*/
    f[i][j][k]=-1;
    if(i&&f[i-1][j][k-1]!=-1) clear(i-1,j,k-1);
    if(j&&f[i][j-1][k-1]!=-1) clear(i,j-1,k-1);
    if((n-i)*(m-j)>n*m-k)
        clear(i,j,k-1);
    return;
}
int main()
{
    long long ans;
    scanf("%d",&T_T);
    memset(f,-1,sizeof(f));
    while(T_T--)
    {
        scanf("%lld%lld%lld",&n,&m,&K);
        pre_calc();
        ans=calc(n-1,m-1,n*m-1)*n%K*m%K;
        printf("%lld\n",ans);
        clear(n-1,m-1,n*m-1);
		ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

