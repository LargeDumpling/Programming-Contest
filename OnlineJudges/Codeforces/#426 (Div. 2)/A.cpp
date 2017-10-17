/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[10];
int n,k;
int trans(char x)
{
	if(x==94) return 0;
	else if(x==62) return 1;
	else if(x==118) return 2;
	return 3;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int a1,a2;
	gets(tex);
	a1=trans(tex[0]);
	a2=trans(tex[2]);
	k=(a2-a1+4)%4;
	scanf("%d",&n);
	if(n%4==k&&n%4!=(4-k)%4)
		printf("cw");
	else if(n%4!=k&&n%4==(4-k)%4)
		printf("ccw");
	else printf("undefined");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

