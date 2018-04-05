/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=1024;
const long long mod=1000000007LL;
long long p[MAXN],map[MAXN][MAXN];
void pre_calc()
{
	p[0]=1;
	p[1]=23LL;
	for(int i=2;i<MAXN;i++)
		p[i]=p[i-1]*p[1]%mod;
	return;
}
void check(int l1,int r1,int l2,int r2,int l3,int r3,int l4,int r4)
{
	int h=l2-l1+1,w=r2-r1+1,cnt=0;
	long long t1,t2,t3;
	for(int i=0;i<h&&cnt<2;i++)
	{
		if((t1=(map[l1+i][r2]-map[l1+i][r1-1]*p[w]%mod+mod)%mod)
				!=(t2=(map[l3+i][r4]-map[l3+i][r3-1]*p[w]%mod+mod)%mod))
		{
			t3=abs(t1-t2);
			for(int i=0;i<=w;i++)
			{
				if(i==w) cnt=2;
				else if(t3==p[i])
				{
					cnt++;
					break;
				}
			}
		}
	}
	if(cnt==0) puts("Perfect");
	else if(cnt==1) puts("One difference");
	else puts("Wrong");
	return;
}
int n,m;
int main()
{
	int Q,l1,r1,l2,r2,l3,r3,l4,r4;
	char str[MAXN];
	pre_calc();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			map[i][j]=(map[i][j-1]*p[1]%mod+str[j]-'0')%mod;
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d%d%d%d%d%d",&l1,&r1,&l2,&r2,&l3,&r3,&l4,&r4);
		l1++; r1++;
		l2++; r2++;
		l3++; r3++;
		l4++; r4++;
		check(l1,r1,l2,r2,l3,r3,l4,r4);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

