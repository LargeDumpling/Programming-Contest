/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int N;
long long A,B;
long long s[MAXN];
int main()
{
	int cnt=0;
	scanf("%d%I64d%I64d",&N,&A,&B);
	for(int i=1;i<=N;i++)
	{
		scanf("%I64d",&s[i]);
		s[0]+=s[i];
	}
	sort(s+2,s+N+1);
	for(int i=N;1<i&&s[1]*A<s[0]*B;i--)
	{
		s[0]-=s[i];
		cnt++;
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

