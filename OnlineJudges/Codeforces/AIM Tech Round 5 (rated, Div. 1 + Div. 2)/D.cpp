/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=400050;
const int M=524288;
const long long mod=1000000007;
struct jz
{
	int typ;
	int p;
}ord[MAXN];
long long ans;
int n,h[MAXN];
bool tag[MAXN<<2][2],d[MAXN<<2][2];
char ins[10];
void down(int root,int L,int R)
{
	if(!tag[root][0]&&!tag[root][1]) return;
	if(L==R)
	{
		tag[root][0]=tag[root][1]=false;
		return;
	}
	for(int i=0;i<2;i++) if(tag[root][i])
	{
		d[root<<1][i]=0;
		tag[root<<1][i]=true;
		d[root<<1|1][i]=0;
		tag[root<<1|1][i]=true;
	}
	tag[root][0]=tag[root][1]=false;
	return;
}
void add(int root,int L,int R,int x)
{
	if(L==R)
	{
		d[root][0]=d[root][1]=1;
		tag[root][0]=tag[root][1]=false;
		return;
	}
	down(root,L,R);
	int mid=(L+R)>>1;
	if(x<=mid) add(root<<1,L,mid,x);
	else add(root<<1|1,mid+1,R,x);
	return;
}
void del(int root,int L,int R,int x)
{
}
int main()
{
	memset(tag,false,sizeof(tag));
	memset(d,false,sizeof(d));
	scanf("%d",&n);
	ans=1;
	h[0]=0;
	set<int> S[2],s;
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d",ins,&ord[i].p);
		h[++h[0]]=ord[i].p;
		if(ins[1]=='D')
		{
			ord[i].typ=0;
			S[0].insert(ord[i].p);
			S[1].insert(ord[i].p);
		}
		else if(ins[1]=='C') ord[i].typ=1;
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		ord[i].p=lower_bound(h+1,h+h[0]+1,ord[i].p)-h;
		if(ord[i].typ==0)
			add(ord[i].p);
		else if(ord[i].typ==1)
		{
			set<int>::iterator it;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

