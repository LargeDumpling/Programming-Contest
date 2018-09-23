/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=500050;
const int M=524288;
int T_T,r[MAXN],len,en;
vector<int> add[MAXN],del[MAXN];
long long d[M<<1];
char str[MAXN];
void Manacher()
{
	int rm=0,rmi=0;
	r[1]=0;
	add[1].push_back(1);
	del[2].push_back(1);
	for(int i=2;i<=len;i++)
	{
		r[i]=0;
		if(i<=rm)
			r[i]=min(rm-i,r[2*rmi-i]);
		while(1<=i-r[i]-1&&i+r[i]+1<=len&&str[i-r[i]-1]==str[i+r[i]+1])
			r[i]++;
		if(rm<i+r[i])
		{
			rm=i+r[i];
			rmi=i;
		}
		add[i-r[i]].push_back(i);
		del[i+r[i]+1].push_back(i);
	}
	return;
}
void change(int p,long long x)
{
	for(p+=M;p;p>>=1)
		d[p]+=x;
	return;
}
long long query(int L,int R)
{
	long long ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans+=d[L^1];
		if(R&1) ans+=d[R^1];
	}
	return ans;
}
void clear()
{
	for(int i=1;i<=len+1;i++)
	{
		vector<int> ().swap(add[i]);
		vector<int> ().swap(del[i]);
	}
	return;
}
int main()
{
	long long ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str+1);
		len=strlen(str+1);
		Manacher();
		ans=0;
		for(int i=1;i<=len;i++)
		{
			for(unsigned j=0;j<del[i].size();j++)
				change(del[i][j],-1);
			for(unsigned j=0;j<add[i].size();j++)
				change(add[i][j],1);
			ans+=query(i-r[i],i-1);
		}
		for(unsigned j=0;j<del[len+1].size();j++)
			change(del[len+1][j],-1);
		clear();
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

