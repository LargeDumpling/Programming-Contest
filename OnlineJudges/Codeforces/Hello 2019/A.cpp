/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char card[10][5];
int main()
{
	bool flag=false;
	for(int i=0;i<=5;i++)
		scanf("%s",card[i]);
	for(int i=1;i<=5;i++)
		flag|=(card[0][0]==card[i][0]||card[0][1]==card[i][1]);
	if(flag) puts("YES");
	else puts("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

