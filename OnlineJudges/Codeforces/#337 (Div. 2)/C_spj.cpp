/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[550][550];
int n;
bool check(int a,int b)
{
	int cnt=0;
	for(int i=0;i<n;i++)if(str[a]!=str[b])cnt++;
	return cnt==(n>>1);
}
int main()
{
	freopen("C.out","r",stdin);
	while(gets(str[n++])!=NULL);
	n--;
	bool flag=true;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(!check(i,j))
				flag=false;
	if(flag)puts("Yes");
	else puts("No");
	system("pause");
	fclose(stdin);
	return 0;
}

