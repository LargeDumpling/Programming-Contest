/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,m;
bool rflag[MAXN],cflag[MAXN];
void read1n(int &x)
{
	char ch=getchar();
	for(;ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int ans=0,x,y;
	memset(rflag,false,sizeof(rflag));
	memset(cflag,false,sizeof(cflag));
	read1n(n); read1n(m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		rflag[x]=true;
		cflag[y]=true;
	}
	if(n&1)
	{
		ans=(n/2)*4+1;
		for(int i=1;i<=n;i++)
		{
			if(i==n/2+1)
			{
				if(rflag[i]&&cflag[i])
					ans--;
			}
			else
			{
				if(rflag[i]) ans--;
				if(cflag[i]) ans--;
			}
		}
	}
	else
	{
		ans=(n/2)*4;
		for(int i=1;i<=n;i++)
		{
			if(rflag[i]) ans--;
			if(cflag[i]) ans--;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

