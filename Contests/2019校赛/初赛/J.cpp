/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const int INF=2147483647;
int n,m;
int num[MAXN][MAXN<<1],r[MAXN][MAXN<<1],id,rig;
int q[MAXN<<1],head,tail,ans;
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
		else if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	ans=0;
	read1n(n); read1n(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			num[i][j<<1]=-INF;
			read1n(num[i][j<<1|1]);
		}
		num[i][m<<1]=-INF;
		r[i][0]=id=rig=0;
		for(int j=1;j<=m*2;j++)
		{
			if(j<=rig) r[i][j]=min(rig-j,r[i][2*id-j]);
			while(0<j-r[i][j]&&j+r[i][j]<2*m&&num[i][j-r[i][j]-1]==num[i][j+r[i][j]+1])
				r[i][j]++;
			if(rig<j+r[i][j])
			{
				rig=j+r[i][j];
				id=j;
			}
		}
		/*for(int j=0;j<=2*m;j++)
			printf("%d%c",num[i][j],j==2*m?'\n':' ');*/
	}
	/*for(int i=0;i<n;i++)
		for(int j=0;j<=2*m;j++)
			printf("%d%c",r[i][j],j==2*m?'\n':' ');*/
	for(int j=1;j<m*2;j++)
	{
		head=1; tail=0;
		for(int i=0;i<n;i++)
		{
			while(head<=tail&&r[i][j]<r[q[tail]][j]) tail--;
			q[++tail]=i;
			while(head<tail&&r[q[head]][j]*(i-q[head]+1)<r[q[head+1]][j]*(i-q[head+1]+1))
				head++;
			ans=max(ans,r[q[head]][j]*(i-q[head]+1));
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

