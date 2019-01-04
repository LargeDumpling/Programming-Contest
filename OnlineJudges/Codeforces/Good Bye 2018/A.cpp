/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-12-30	File created.
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
	int y,b,r,ans=0;
	scanf("%d%d%d",&y,&b,&r);
	if(y+1<=b&&y+2<=r)
		ans=max(ans,y*3+3);
	if(b-1<=y&&b+1<=r)
		ans=max(ans,b*3);
	if(r-2<=y&&r-1<=b)
		ans=max(ans,r*3-3);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

