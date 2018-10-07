/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,cnt[10],ans;
char str[105];
int main()
{
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++)
		cnt[str[i]-'0']++;
	ans=0;
	for(int i=1;i<=cnt[8];i++) if(i*11<=n)
		ans=i;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

