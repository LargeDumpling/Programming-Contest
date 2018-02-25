/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char str[20];
int len,sum;
int main()
{
	int ans=0;
	scanf("%s",str+1);
	len=strlen(str+1);
	for(int i=1;i<=len;i++)
	{
		sum+=str[i]-'0';
		if(str[i]-'0')
			ans=max(ans,sum-1+(len-i)*9);
	}
	ans=max(ans,sum);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

