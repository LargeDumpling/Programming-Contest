/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-05	File created.
	2018-01-31  Edited.
	2018-02-01  Accepted.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
int n,m;
int fa[MAXN],son[MAXN][2],st[MAXN];
bool rev[MAXN];
bool isroot(int x)
{// Check whether x is the root of the Auxiliary tree it belongs to
	return x!=son[fa[x]][0]&&x!=son[fa[x]][1];
}
void Down(int x)
{
	if(!rev[x]) return;
	swap(son[son[x][0]][0],son[son[x][0]][1]);
	swap(son[son[x][1]][0],son[son[x][1]][1]);
	rev[son[x][0]]^=true;
	rev[son[x][1]]^=true;
	rev[x]=false;
	return;
}
void adjust(int x)
{
	int fa1=fa[x],fa2=fa[fa[x]],d;
	d=son[fa1][1]==x;
	if(!isroot(fa1))
		son[fa2][son[fa2][1]==fa1]=x;
	fa[x]=fa2;
	fa[fa1]=x;
	fa[son[x][d^1]]=fa1;
	son[fa1][d]=son[x][d^1];
	son[x][d^1]=fa1;
	return;
}
void Splay(int x)
{
	st[0]=0;
	st[++st[0]]=x;
	for(int i=x;!isroot(i);i=fa[i])
		st[++st[0]]=fa[i];
	while(st[0]) Down(st[st[0]--]);
	int fa1,fa2;
	while(!isroot(x))
	{
		fa1=fa[x];
		fa2=fa[fa[x]];
		if(!isroot(fa1))
		{
			if((son[fa1][1]==x)==(son[fa2][1]==fa1))
				adjust(fa1);
			else adjust(x);
		}
		adjust(x);
	}
	return;
}
void Access(int x)
{
	int t=0;
	while(x)
	{
		Splay(x);
		son[x][1]=t;
		t=x;
		x=fa[x];
	}
	return;
}
void Change_to_root(int x)
{
	Access(x); Splay(x);
	swap(son[x][0],son[x][1]);
	rev[x]^=true;
	return;
}
void Link(int x,int y)
{
	Change_to_root(y);
	fa[y]=x;
	//Splay(y);
	return;
}
void Cut(int x,int y)
{
	Change_to_root(x);
	Access(y);//
	Splay(y);
	son[y][0]=fa[x]=0;
	return;
}
int Find_root(int x)
{
	Access(x); Splay(x);
	while(son[x][0]) x=son[x][0];
	return x;
}
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
	int u,v;
	char comm[10];
	//scanf("%d%d",&n,&m);
	read1n(n);
	read1n(m);
	while(m--)
	{
		//scanf("%s%d%d",comm,&u,&v);
		scanf("%s",comm);
		read1n(u);
		read1n(v);
		switch(comm[0])
		{
			case 'C':
				Link(u,v);
				break;
			case 'D':
				Cut(u,v);
				break;
			case 'Q':
				puts(Find_root(u)==Find_root(v)?"Yes":"No");
				break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

