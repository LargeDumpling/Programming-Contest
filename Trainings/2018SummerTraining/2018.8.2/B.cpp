/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int num[2050],ws;
	jp() { memset(num,ws=0,sizeof(num)); }
}m;
char str[2050];
void read1n(jp &X)
{
	scanf("%s",str);
	X.ws=strlen(str);
	for(int i=0;i<X.ws;i++)
		X.num[i]=str[X.ws-1-i]-'0';
	return;
}
int main()
{
	read1n(m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

