/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,mIn,sec;
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		long long ans=0;
		read1n(mIn);
		read1n(mIn);
		read1n(mIn);
		read1n(mIn);
		read1n(mIn);
		read1n(sec);
		if(!mIn&&!sec) ans=0;
		else ans=60*(59-mIn)+60-sec;
		printf("%lld\n",ans%100);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

