/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=100050;
int nExt[MAXL],n,head=-1,newhead=-1,tail=-1;
int data[MAXL];
bool exist[MAXL];
int main()
{
	int x;
	memset(exist,false,sizeof(exist));
	scanf("%d%d",&head,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		scanf("%d%d",&data[x],&nExt[x]);
	}
	for(int i=head;i!=-1;i=nExt[i])
	{
		exist[abs(data[i])]=true;
		if(nExt[i]==-1) break;
		else while(exist[abs(data[nExt[i]])])
		{
			int tem=nExt[i];
			nExt[i]=nExt[nExt[i]];
			if(tail==-1) newhead=tail=tem;
			else
			{
				nExt[tail]=tem;
				tail=tem;
			}
			nExt[tail]=-1;
		}
	}
	for(int i=head;i!=-1;i=nExt[i])
	{
		printf("%05d %d ",i,data[i]);
		if(nExt[i]==-1) puts("-1");
		else printf("%05d\n",nExt[i]);
	}
	for(int i=newhead;i!=-1;i=nExt[i])
	{
		printf("%05d %d ",i,data[i]);
		if(nExt[i]==-1) puts("-1");
		else printf("%05d\n",nExt[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

