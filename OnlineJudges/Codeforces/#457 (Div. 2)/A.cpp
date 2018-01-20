/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int x,h,m;
bool check() { return h%10==7||m%10==7; }
int main()
{
	int cnt;
	scanf("%d%d%d",&x,&h,&m);
	for(cnt=0;!check();cnt++)
	{
		m-=x;
		if(m<0) h-=1,m+=60;
		if(h<0) h+=24;
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

