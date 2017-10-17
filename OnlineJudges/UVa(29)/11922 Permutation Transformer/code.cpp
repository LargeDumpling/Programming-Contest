/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp *null;
struct jp
{
	int key,size;
	bool flag;
	jp *son[2];
	jp(const int &x=0) { key=x; size=1; flag=false; son[0]=son[1]=null; }
	int cmp(int x) { return x==(son[0]->size+1)?-1:(x<son[0]->size+1?0:1);}
	void updata() { size=son[0]->size+son[1]->size+1; return; }
	void down()
	{
		if(!flag) return;
		swap(son[0],son[1]);
		son[0]->flag^=true;
		son[1]->flag^=true;
		flag=false;
		return;
	}
}*root;
int cnt=0;
void build(jp* &u,int l,int r)
{
	if(l>r) { u=null; return; }
	u=new jp();
	int mid=(l+r)>>1;
	build(u->son[0],l,mid-1);
	u->key=cnt++;
	build(u->son[1],mid+1,r);
	u->updata();
	return;
}
void adjust(jp* &r,int d)
{
	jp *u=r->son[d]; r->son[d]=u->son[d^1]; u->son[d^1]=r;
	r->updata(); (r=u)->updata(); return;
}
void splay(jp* &r,int k)
{
	r->down();
	int d=r->cmp(k);
	if(d==1) k-=(r->son[0]->size+1);
	if(d!=-1)
	{
		jp *u=r->son[d];
		u->down();
		int d2=u->cmp(k);
		int k2=d2==1?k-u->son[0]->size-1:k;
		if(d2!=-1)
		{
			splay(u->son[d2],k2);
			if(d==d2) adjust(r,d);
			else adjust(r->son[d],d2);//勿写为u
		}
		adjust(r,d);
	}
	return;
}
jp* merge(jp* left,jp* right)
{
	//if(left==null) return right;
	//else if(right==null) return left;
	splay(left,left->size);
	left->son[1]=right;
	left->updata();
	return left;
}
void split(jp* all,int k,jp* &left,jp* &right)
{
	splay(all,k);
	left=all;
	right=all->son[1];
	all->son[1]=null;
	left->updata();
	return;
}
void rEverse(int l,int r)
{
	jp *left,*mid,*right,*o;
	split(root,l,left,o);
	split(o,r-l+1,mid,right);
	mid->flag^=true;
	root=merge(merge(left,right),mid);
	return;
}
int tot=0,n,m;
void print(jp* &r)
{
	if(r==null) return;
	r->down();
	print(r->son[0]);
	if(r->key)
	{
		printf("%d",r->key);//特殊结点可以不输出，但它是通往AC的大门
		if(++tot!=n) putchar(' ');
	}
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
	int a,b;
	scanf("%d%d",&n,&m);
	build(root,0,n);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		rEverse(a,b);
	}
	print(root);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

