/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=120;
int n,m,l,r,u,d;
char str[MAXN];
int main()
{
	l=r=u=d=-1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		for(int j=0;j<m;j++) if(str[j]=='B')
		{
			if(u==-1)
			{
				u=d=i+1;
				l=r=j+1;
			}
			else
			{
				u=min(u,i+1);
				d=max(d,i+1);
				l=min(l,j+1);
				r=max(r,j+1);
			}
		}
	}
	printf("%d %d",(u+d)/2,(l+r)/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

