/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char T[10050],tex[1050];
int pre[1050],lenT,lenth;
void get_fail()
{
	memset(pre,-1,sizeof pre);
	pre[0]=-1;
	for(int i=1,k=-1;i<lenth;i++)
	{
		while(k>=0&&tex[i]!=tex[k+1])k=pre[k];
		if(tex[i]==tex[k+1])k++;
		pre[i]=k;
	}
	return;
}
int KMP()
{
	for(int i=0,k=-1;i<lenT;i++)
	{
		while(k>=0&&T[i]!=tex[k+1])k=pre[k];
		if(T[i]==tex[k+1])
		{
			k++;
			if(k==lenth-1)
				return i-k;
		}
	}
	return -1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%s%s",tex,T);
	lenT=strlen(T);
	lenth=strlen(tex);
	get_fail();
	printf("%d",KMP());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

