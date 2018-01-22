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
const int MAXN=1000050;
int n,ch[MAXN<<1][10],val[MAXN<<1],sz=0;
unsigned long long num[MAXN];
char str[MAXN][20];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void insert(int j)
{
	int u=0;
	for(int i=0;i<19;u=ch[u][str[j][i++]])
		if(!ch[u][str[j][i]])
			ch[u][str[j][i]]=++sz;
	val[u]=j;
	return;
}
unsigned long long calc(int a,int b)
{
	unsigned long long ans=0;
	for(int i=0;i<19;i++)
		ans=ans*10+(str[a][i]+str[b][i])%10;
	return ans;
}
int fInd_max(int k)
{
	int u=0,v;
	for(int i=0;i<19;i++)
	{
		v=-1;
		for(int j=0;j<10;j++)
			if(ch[u][j]&&v<(j+str[k][i])%10)
				v=j;
		u=ch[u][v];
	}
	return val[u];
}
int fInd_min(int k)
{
	int u=0,v;
	for(int i=0;i<19;i++)
	{
		v=2147483647;
		for(int j=0;j<10;j++)
			if(ch[u][j]&&(j+str[k][i])%10<v)
				v=j;
		u=ch[u][v];
	}
	return val[u];
}
int main()
{
	unsigned long long mAx=0,mIn=-1;
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		sprintf(str[i],"%019I64d",num[i]);
		for(int j=0;j<19;j++)
			str[i][j]-='0';
		if(1<i)
		{
			mAx=max(mAx,calc(i,fInd_max(i)));
			mIn=min(mIn,calc(i,fInd_min(i)));
		}
		insert(i);
	}
	cout<<mIn<<" "<<mAx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

