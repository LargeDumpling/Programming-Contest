/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
char str[MAXN];
int main()
{
	int n,cnt=0,state=0,sum=0;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;i++)
	{
		if(sum==0)
		{
			if((state==-1&&str[i]=='U')||(state==1&&str[i]=='R'))
				cnt++;
			if(str[i]=='U') state=1;
			if(str[i]=='R') state=-1;
		}
		if(str[i]=='U') sum++;
		if(str[i]=='R') sum--;
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

