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
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int c,v0,a,v1,l,cnt=0;
	scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
	v0-=a;
	while(true)
	{
		v0=min(v0+a,v1);
		if(cnt++) c-=(v0-l);
		else c-=v0;
		if(c<=0) break;
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

