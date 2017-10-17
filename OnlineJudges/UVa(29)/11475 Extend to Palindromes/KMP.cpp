/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int lenth,pre[100050];
char tex[100050],rev[100050];
void get_pre()
{
	pre[0]=-1;
	for(int i=1,k=-1;i<lenth;pre[i++]=k)
	{
		while(k>=0&&rev[i]!=rev[k+1]) k=pre[k];
		if(rev[i]==rev[k+1])k++;
	}
	return;
}
int find()
{
	int k=-1;
	for(int i=0;i<lenth;i++)
	{
		while(k>=0&&tex[i]!=rev[k+1]) k=pre[k];
		if(tex[i]==rev[k+1])k++;
	}
	return k+1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("KMP.out","w",stdout);
	while(scanf("%s",tex)!=-1)
	{
		lenth=strlen(tex);
		for(int i=0;i<lenth;i++) rev[i]=tex[lenth-1-i];
		rev[lenth]=rev[lenth+1]='\0';
		get_pre();
		printf("%s%s\n",tex,rev+max(find(),1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

