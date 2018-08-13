/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[10000];
int len=0;
int main()
{
	freopen("Dic.txt","r",stdin);
	while(scanf("%s",str)!=-1)
		len=max(len,(int)strlen(str));
	printf("%d",len);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
