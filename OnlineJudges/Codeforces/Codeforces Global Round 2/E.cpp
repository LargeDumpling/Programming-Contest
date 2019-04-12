/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
int n,num[MAXN];
long long ans=0,lEft=0;
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'&&'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	read1n(n);
	for(int i=1;i<=n;i++)
		read1n(num[i]);
	for(int i=1;i<=n;i++)
	{
		long long cnt=min(lEft,(long long)num[i]>>1);
		lEft-=cnt;
		num[i]-=(cnt<<1);
		ans+=cnt;
		ans+=(cnt=num[i]/3);
		lEft+=num[i]%3;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

