/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int n,m,A[10050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b;
	char ord[5];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d%d",ord,&a,&b);
		if(ord[0]=='Q')
		{
			set<int>s;
			for(int i=a;i<=b;i++) s.insert(A[i]);
			printf("%d\n",(int)s.size());
		}
		else if(ord[0]=='R')
			A[a]=b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

