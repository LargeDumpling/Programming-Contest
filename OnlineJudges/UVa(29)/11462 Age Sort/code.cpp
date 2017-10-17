/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int cnt[100],n,x;
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(true)
	{
		read1n(n);
		if(!n) break;
		for(int i=1;i<=n;i++)
		{
			read1n(x);
			cnt[x]++;
		}
		x=0;
		for(int i=1;i<100;i++)
		{
			while(cnt[i])
			{
				if(!x) x=1;
				else putchar(' ');
				printf("%d",i);
				cnt[i]--;
			}
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

