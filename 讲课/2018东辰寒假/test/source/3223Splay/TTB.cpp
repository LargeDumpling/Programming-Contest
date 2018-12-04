/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jz *null;
struct jz
{
	int data,size;
	bool rev;
	jz *son[2];
	jz() { size=0; rev=false; }
	int cmp(int x)
	{
		x-=son[0]->size;
		if(x==1) return -1;
		return x<=0?0:1;
	}
	void maintain() { size=son[0]->size+son[1]->size+1; return; }
	void down()
	{
		if(this==null||!rev) return;
		swap(son[0]->son[0],son[0]->son[1]);
		swap(son[1]->son[0],son[1]->son[1]);
		son[0]->rev^=true;
		son[1]->rev^=true;
		rev=false;
		return;
	}
}*root;
int n,m;
jz* build(int l,int r)
{
	if(r<l) return null;
	int mid=(l+r)>>1;
	jz* ans=new jz();
	ans->data=mid;
	ans->son[0]=build(l,mid-1);
	ans->son[1]=build(mid+1,r);
	ans->maintain();
	return ans;
}
void adjust(jz* &r,int d)
{
	jz* t=r->son[d];
	r->son[d]=t->son[d^1];
	t->son[d^1]=r;
	r->maintain();
	(r=t)->maintain();
	return;
}
void Splay(jz* &r,int x)
{
	if(r==null) return;
	r->down();
	int d=r->cmp(x);
	if(d!=-1)
	{
		if(d==1) x-=(r->son[0]->size+1);
		jz* u=r->son[d];
		u->down();
		int d1=u->cmp(x);
		if(d1!=-1)
		{
			if(d1==1) x-=(u->son[0]->size+1);
			Splay(u->son[d1],x);
			if(d==d1) adjust(r,d);//
			else adjust(r->son[d],d1);// 注意为什么是r->son[d]？
		}
		adjust(r,d);
	}
	return;
}
void Split(jz* r,int k,jz* &L,jz* &R)
{
	Splay(r,k);
	R=r->son[1];
	r->son[1]=null;
	r->maintain();
	L=r;
	return;
}
jz* Merge(jz* &L,jz *R)
{
	Splay(L,L->size);
	L->son[1]=R;
	L->maintain();
	return L;
}
void reverse(int l,int r)
{
	jz *left,*mid,*right;
	Split(root,l,left,mid);
	Split(mid,r-l+1,mid,right);
	swap(mid->son[0],mid->son[1]);
	mid->rev^=true;
	root=Merge(left,Merge(mid,right));
}
void print(jz* &r)
{
	if(r==null) return;
	r->down();
	print(r->son[0]);
	if(r->data) printf("%d ",r->data);
	print(r->son[1]);
	return;
}
int main()
{
	int l,r;
	null=new jz();
	null->son[0]=null->son[1]=null;
	scanf("%d%d",&n,&m);
	root=build(0,n);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		reverse(l,r);
	}
	print(root);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

