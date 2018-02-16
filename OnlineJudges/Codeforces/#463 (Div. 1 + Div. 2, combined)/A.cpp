/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[1050];
int len;
int main()
{
	scanf("%s",str);
	len=strlen(str);
	printf("%s",str);
	for(int i=len-1;0<=i;i--)
		putchar(str[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

