/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int dec(int x)
{
	if(x<=0)return 1;
	int ans=1;
	for(int i=1;i<=x;i++)ans*=10;
	return ans;
}
int f[10][10][10],a,b;
void pre_calc()
{
	memset(f,0,sizeof(f));
	for(int i=0;i<=9;i++)f[i][1][i]=1;
	for(int k=0;k<=9;k++)
	{
		for(int i=2;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				if(j==k)f[k][i][j]=dec(i-1);
				for(int l=0;l<=9;l++)
					f[k][i][j]+=f[k][i-1][l];
			}
		}
	}
	return;
}
int calc(int X,int digit)
{
	int ans=0,num[11],sum=0;
	if(!X)num[num[0]=1]=0;
	for(num[0]=0;X;X/=10)num[++num[0]]=X%10;
	for(int i=1;i<num[0];i++)for(int j=1;j<=9;j++)
		ans+=f[digit][i][j];
	for(int i=1;i<num[num[0]];i++)
	{
		ans+=f[digit][num[0]][i]/*+dec(num[0]-1)*(i==digit)*/;
	}
	sum=(num[num[0]]==digit);
	for(int i=num[0]-1;i;i--)
	{
		for(int j=0;j<num[i];j++)
			ans+=f[digit][i][j]+dec(i-1)*sum;
		if(num[i]==digit)sum++;
	}
	return ans;
}
void solve(int L,int R)
{
	if(L>R)
	{
		L^=R;
		R=L^R;
		L^=R;
	}
	for(int k=0;k<9;k++)printf("%d ",calc(R+1,k)-calc(L,k));
	printf("%d\n",calc(R+1,9)-calc(L,9));
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pre_calc();
	while(scanf("%d%d",&a,&b)!=-1&&a&&b)solve(a,b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

