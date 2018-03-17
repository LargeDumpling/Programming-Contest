/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int pri[MAXN],p,y;
bool exist[MAXN];
void pre_calc()
{
	pri[0]=0;
	memset(exist,true,sizeof(exist));
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&pri[j]*i<MAXN;j++)
		{
			exist[pri[j]*i]=false;
			if(i%pri[j]==0)
				break;
		}
	}
	return;
}
int main()
{
	int ans=-1;
	bool flag;
	pre_calc();
	scanf("%d%d",&p,&y);
	for(int i=y;p<i;i--)
	{
		flag=true;
		for(int j=1;j<=pri[0]&&pri[j]<=p&&pri[j]*pri[j]<=i;j++)
		{
			if(i%pri[j]==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			ans=i;
			break;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

