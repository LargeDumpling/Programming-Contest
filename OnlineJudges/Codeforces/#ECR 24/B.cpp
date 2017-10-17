/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-06-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[105],l[105];
bool ans_exist=true,exist[105];
int main()
{
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	int u,v,temp;
	memset(l,-1,sizeof(l));
	memset(a,-1,sizeof(a));
	memset(exist,false,sizeof(exist));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;l[i++]--)
		scanf("%d",&l[i]);
	for(int i=1;i<m;i++)
	{
		u=l[i]; v=l[i+1];
		temp=v-u;
		if(temp<=0) temp+=n;
		if(a[u]==-1)
			a[u]=temp;
		else if(a[u]!=temp)
		{
			ans_exist=false;
			break;
		}
	}
	if(ans_exist)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]!=-1&&exist[a[i]])
			{
				printf("-1");
				ans_exist=false;
				break;
			}
			exist[a[i]]=true;
		}
		if(ans_exist)
		{
			int p=1;
			for(int i=0;i<n;i++)
			{
				if(a[i]==-1)
				{
					while(exist[p]) p++;
					a[i]=p++;
				}
				printf("%d ",a[i]);
			}
		}
	}
	else printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

