/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,m,num[MAXN],h[MAXN],cnt[MAXN],ans;
int d[MAXN],s[2][MAXN];
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void init(int n)
{
	for(int i=1;i<=h[0];i++)
		cnt[i]=0;
	for(int i=0;i<=n;i++)
		s[0][i]=s[1][i]=d[i]=0;
	ans=-1;
	return;
}
int main()
{
	read1n(T_T);
	ans=-1;
	while(T_T--)
	{
		read1n(n); read1n(m);
		h[0]=0;
		for(int i=1;i<=n;i++)
		{
			read1n(num[i]);
			h[++h[0]]=num[i];
		}
		sort(h+1,h+h[0]+1);
		h[0]=unique(h+1,h+h[0]+1)-h-1;
		for(int i=1;i<=n;i++)
		{
			num[i]=lower_bound(h+1,h+h[0]+1,num[i])-h;
			cnt[num[i]]++;
		}
		for(int i=1;i<=h[0];i++)
			d[cnt[i]]++;
		for(int i=1;i<=n;i++) if(d[i])
		{
			s[0][i]+=d[i];
			s[1][i]+=i*d[i];
		}
		for(int i=n;i;i--)
			for(int j=0;j<2;j++)
				s[j][i-1]+=s[j][i];
		for(int i=h[0];i;i--)
		{
			int tem=0;
			tem=s[1][cnt[i]]-cnt[i]-(cnt[i]-1)*(s[0][cnt[i]]-1);
			if(tem<=m)
			{
				ans=h[i];
				break;
			}
		}
		printf("%d\n",ans);
		init(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

