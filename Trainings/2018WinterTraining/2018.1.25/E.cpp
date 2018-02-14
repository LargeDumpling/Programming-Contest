/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,num[15];
bool check()
{
	for(int i=2;i<=n;i++)
		if(num[i]!=num[1])
			return false;
	return true;
}
void fInd(int &mAx,int &mIn)
{
	mAx=mIn=1;
	for(int i=2;i<=n;i++)
	{
		if(num[i]<num[mIn])
			mIn=i;
		if(num[mAx]<num[i])
			mAx=i;
	}
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		while(!check())
		{
			int i,j;
			fInd(i,j);
			num[i]=num[j]=num[i]-num[j];
		}
		printf("%d\n",num[1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

