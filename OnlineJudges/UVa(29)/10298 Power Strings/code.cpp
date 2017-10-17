/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[1000050];
int lenth,pre[1000050];
void KMP_pre()
{
	pre[0]=-1;
	for(int i=1,k=-1;i<lenth;i++)
	{
		while(k>=0&&tex[i]!=tex[k+1]) k=pre[k];
		if(tex[i]==tex[k+1]) k++;
		pre[i]=k;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int k;
	while(scanf("%s",tex)!=-1&&tex[0]!='.')
	{
		lenth=strlen(tex);
		KMP_pre();
		//for(int i=0;i<lenth;i++) printf("%d ",pre[i]);
		//putchar('\n');
		while(pre[lenth-1]!=-1)
		{
			k=lenth-1-pre[lenth-1];
			if(!(lenth%k)) break;
			pre[lenth-1]=pre[pre[lenth-1]];
		}
		printf("%d\n",lenth/(lenth-1-pre[lenth-1]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

