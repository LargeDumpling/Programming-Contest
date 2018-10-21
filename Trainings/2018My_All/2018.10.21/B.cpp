/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n;
int D[MAXN],S[MAXN],ans=0;
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	int cnt;
	read1n(T_T);
	while(T_T--)
	{
		read1n(n);
		for(int i=1;i<=n;i++)
			read1n(D[i]);
		for(int i=1;i<=n;i++)
		{
			read1n(S[i]);
			S[i]-=D[i];
		}
		sort(S+1,S+n+1);
		cnt=ans=0;
		for(int i=1;i<=n+1;i++)
		{
			if(i==1||i==n+1||S[i]!=S[i-1])
			{
				ans=max(ans,cnt);
				cnt=1;
			}
			else if(S[i]==S[i-1])
				cnt++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

