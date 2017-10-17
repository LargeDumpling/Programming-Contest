/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,MAXL,MINR;
int main()
{
	int l,r;
	scanf("%d%d",&n,&m);
	MAXL=1; MINR=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		if(i==1) MAXL=l,MINR=r;
		else MAXL=max(MAXL,l),MINR=min(MINR,r);
	}
	printf("%d",max(MINR-MAXL,0));
	return 0;
}

