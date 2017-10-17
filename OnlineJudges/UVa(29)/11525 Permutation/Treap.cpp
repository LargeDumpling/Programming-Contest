/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int k;
struct jp *null;
struct jp
{
	int key,v,size;
	jp *son[2];
	jp(const int &x=0):key(x) { v=rand(); size=1; son[0]=son[1]=null; }
	int cmp(const int &x=0) { return x==key?-1:(x<key?0:1); }
	void updata() { size=son[0]->size+son[1]->size+1; }
}*root;
void adjust(jp* &r,int d)
{
	jp *u=r->son[d]; r->son[d]=u->son[d^1]; u->son[d^1]=r;
	r->updata(); (r=u)->updata(); return;
}
void insert(jp* &r,int x)
{
	if(r==null)
	{
		r=new jp(x);
		return;
	}
	int d=r->cmp(x);
	insert(r->son[d],x);
	if(r->son[d]->v > r->v)
		adjust(r,d);
	r->updata();
	return;
}
void del(jp* &r,int x)
{
	//if(r==null) return;
	int d=r->cmp(x);
	if(d==-1)
	{
		if(r->son[0]==null||r->son[1]==null)
		{
			jp *u=r;
			r=r->son[0]==null?r->son[1]:r->son[0];
			delete u;
		}
		else
		{
			int d=r->son[0]->v < r->son[1]->v;
			adjust(r,d);
			del(r->son[d^1],x);
		}
		if(r!=null) r->updata();
		return;
	}
	del(r->son[d],x);
	r->updata();
	return;
}
int kth(jp* &r,int rank)
{
	if(rank<=r->son[0]->size) return kth(r->son[0],rank);
	return (r->son[0]->size+1<rank)?kth(r->son[1],rank-r->son[0]->size-1):r->key;
}
void clear(jp* &r)
{
	if(r==null) return;
	clear(r->son[0]); clear(r->son[1]);
	delete r; r=null; return;
}
void print(jp* &r)
{
	if(r==null) return;
	print(r->son[0]);
	fprintf(stderr,"%d ",r->key);
	print(r->son[1]);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	root=null=new jp();
	null->son[0]=null->son[1]=null;
	null->size=0;
	int T_T,x;
	scanf("%d",&T_T);
	while(T_T--)
	{
		clear(root);
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
			insert(root,i);
		//print(root); fprintf(stderr,"\n");
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&x);
			x=kth(root,x+1);
			printf("%d",x);
			if(i!=k) putchar(' ');
			else putchar('\n');
			del(root,x);
			//print(root); fprintf(stderr,"\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

