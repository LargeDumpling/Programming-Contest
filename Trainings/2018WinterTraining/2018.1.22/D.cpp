/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,num[5050];
int cnt[1000050];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	freopen("cases.in","r",stdin);
	int ans;
	read1n(T_T);
	while(T_T-->0)
	{
		memset(cnt,ans=0,sizeof(cnt));
		read1n(n);
		for(int i=1;i<=n;i++)
			read1n(num[i]);
		for(int l=1;l<=n;l++)
		{
			for(int r=l;r<=n;r++)
			{
				cnt[num[r]]^=1;
				if(cnt[num[r]]) cnt[0]++;
				else cnt[0]--;
				if(cnt[0]==1)
					ans++;
			}
			cnt[0]=0;
			for(int r=l;r<=n;r++)
				cnt[num[r]]=0;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

