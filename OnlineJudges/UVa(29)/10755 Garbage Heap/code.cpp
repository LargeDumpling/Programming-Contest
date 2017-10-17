/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,A,B,C;
long long num[21][21][21],ans,M;
void extract(int p,int &p0,int &p1,int &p2)
{
	p2=p&1; p>>=1;
	p1=p&1; p>>=1;
	p0=p&1;
	return;
}
int sign(int p0,int p1,int p2)
{
	return ((p0+p1+p2)&1)?1:-1;
}
long long get_sum(int x1,int x2,int y1,int y2,int z1,int z2)
{
	long long ans=num[x2][y2][z2];
	int p0,p1,p2;
	//x1--; y1--; z1--;
	x1=x2-x1+1;
	y1=y2-y1+1;
	z1=z2-z1+1;
	for(int p=1;p<=7;p++)
	{
		extract(p,p0,p1,p2);
		ans-=num[x2-x1*p0][y2-y1*p1][z2-z1*p2]*sign(p0,p1,p2);
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int p0,p1,p2;
	long long tm;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(num,0,sizeof(num));
		scanf("%d%d%d",&A,&B,&C);
		ans=-(1LL<<60);
		for(int i=1;i<=A;i++)
			for(int j=1;j<=B;j++)
				for(int k=1;k<=C;k++)
					scanf("%lld",&num[i][j][k]);
		for(int i=1;i<=A;i++)
			for(int j=1;j<=B;j++)
				for(int k=1;k<=C;k++)
				{
					for(int p=1;p<=7;p++)
					{
						extract(p,p0,p1,p2);
						num[i][j][k]+=num[i-p0][j-p1][k-p2]*sign(p0,p1,p2);
					}
					//fprintf(stderr,"%d %d %d :%lld\n",i,j,k,num[i][j][k]);
				}
		for(int x1=1;x1<=A;x1++)
			for(int y1=1;y1<=B;y1++)
				for(int x2=x1;x2<=A;x2++)
					for(int y2=y1;y2<=B;y2++)
					{
						M=0;
						for(int z=1;z<=C;z++)
						{
							tm=get_sum(x1,x2,y1,y2,1,z);
							ans=max(ans,tm-M);
							M=min(M,tm);
						}
					}
		printf("%lld\n",ans);
		if(T_T) puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

