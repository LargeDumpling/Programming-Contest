/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,c,fir[10];
bool exist[100050];
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	memset(fir,-1,sizeof(fir));
	memset(exist,false,sizeof(exist));
	a%=b;
	for(int i=1;;i++)
	{
		if(exist[a]) break;
		else exist[a]=true;
		a*=10;
		if(fir[a/b]==-1) fir[a/b]=i;
		a%=b;
	}
	printf("%d",fir[c]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

