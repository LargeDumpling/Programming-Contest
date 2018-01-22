/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[55][105];
int m;
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m+m+1;j++)
			str[i][j]=' ';
	for(int i=1;i<=m;i++)
		str[i][1]=str[i][m]=str[i][m+2]=str[i][m+m+1]=str[m][i]=str[1][m+1+i]='*';
	for(int i=1;i<=m;i++)
		puts(str[i]+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

