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
const long long mod=1000000007;
int k;
long long n;
void input()
{
	int len;
	char str[1050];
	scanf("%s%d",str,&k);
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[len-i-1]=='1')
			n+=(1<<i);
	}
	return;
}
int calc(long long x)
{
	int cnt;
	for(cnt=0;x;x>>=1)
		if(x&1)
			cnt++;
	return cnt;
}
int cnt(long long x)
{
	if(x==1) return 0;
	return cnt(calc(x))+1;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C_BL.out","w",stdout);
	input();
	int ans=0;
	for(long long i=1;i<=n;i++)
		if(cnt(i)==k)
			ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

