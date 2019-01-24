/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,k,ans=0;
char str[MAXN];
int search(char x)
{
	int cnt=0,len=0;
	for(int i=0;i<=n;i++)
		if(str[i]==x) len++;
		else
		{
			cnt+=len/k;
			len=0;
		}
	return cnt;
}
int main()
{
	scanf("%d%d%s",&n,&k,str);
	for(char ch='a';ch<='z';ch++)
		ans=max(ans,search(ch));
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

