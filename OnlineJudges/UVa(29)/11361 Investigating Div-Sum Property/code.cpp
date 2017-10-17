/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,A,B,K;
int f[11][100][100],dn[11][10];
void pre_DP()
{
	memset(f,0,sizeof(f));
	f[0][0][0]=1;
	for(int i=0;i<10;i++) //i位数
		for(int j=0;j<100;j++) //位数和为j
			for(int k=0;k<100;k++)
			{//数字膜K为k
				if(f[i][j][k]==-1) continue;
				for(int l=0;l<10;l++) //枚举
					f[i+1][(j+l)%K][(k+dn[i+1][l])%K]+=f[i][j][k];
			}
	return;
}
int num[10];
int calc(int x)
{
	if(!x) return 0;
	int len,ans=0,a=0,b=0;
	memset(num,0,sizeof(num));
	for(len=0;x;x/=10) num[len++]=x%10;
	for(int i=1;i<len;i++) ans+=f[i][0][0];
	for(int i=1;i<num[len-1];i++) //首位确定
		ans+=f[len-1][((K-i)%K+K)%K][((K-dn[len][i]%K)%K+K)%K];
	a=num[len];
	b=dn[len][num[len]];
	for(int i=len-1;i;i--)
	{
		for(int j=0;j<num[i-1];j++)
			ans+=f[i-1][((K-a-j)%K+K)%K][((K-b-dn[i][j]%K)%K+K)%K];
		a=(a+num[i-1])%K;
		b=(b+dn[i][num[i-1]])%K;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	for(int i=1;i<10;i++) dn[1][i]=i;
	for(int i=2;i<=10;i++)
		for(int j=0;j<10;j++)
			dn[i][j]=dn[i-1][j]*10;
	while(T_T--)
	{
		scanf("%d%d%d",&A,&B,&K);
		pre_DP();
		if(100<K) puts("0");
		printf("%d\n",calc(B+1)-calc(A));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

