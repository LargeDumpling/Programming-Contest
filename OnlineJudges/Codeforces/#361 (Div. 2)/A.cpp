/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-07-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
bool exist[10],flag=false;
int main()
{
	char tex[100];
	scanf("%d",&n);
	scanf("%s",tex);
	memset(exist,false,sizeof(exist));
	for(int i=0;i<n;i++)
		exist[tex[i]-'0']=true;
	if(!exist[1]&&!exist[2]&&!exist[3]) flag=true;
	else if(!exist[0])
	{
		if(!exist[7]&&!exist[9]) flag=true;
		else if(!exist[1]&&!exist[4]&&!exist[7]) flag=true;
		else if(!exist[3]&&!exist[6]&&!exist[9]) flag=true;
	}
	if(flag) puts("NO");
	else puts("YES");
	return 0;
}

