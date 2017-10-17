/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-26	File created.
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
	jp(const int &x=0):key(x) { size=1; flag=false; son[0]=son[1]=null; }
	int cmp(int k) { return k==(son[0]->size+1)?-1:(k<=son[0]->size?0:1); }
	void updata() { size=son[0]->size+son[1]->size+1; return; }
	void down()
	{
		if(!flag) return;
		flag=false;
		swap(son[0],son[1]);
		son[0]->flag^=true;
		son[1]->flag^=true;
		return;
	}
}*root;
int cnt=0,n,m;
void adjust(jp* &r,int d)
{
	jp* u=r->son[d]; r->son[d]=u->son[d^1]; u->son[d^1]=r;
	r->updata(); (r=u)->updata(); return;
}
void build(jp* &u,int l,int r)
{
	if(l>r) { u=null; return; }
	int mid=(l+r)>>1;
	u=new jp();
	build(u->son[0],l,mid-1);
	u->key=cnt++;
	build(u->son[1],mid+1,r);
	u->updata();//ÎðÍü
	return;
}
void m41441(jp* &r,int k)
{
	r->down();
	int d=r->cmp(k);
	if(d==1) k=k-r->son[0]->size-1;
	if(d!=-1)
	{
		jp* u=r->son[d];
		u->down();
		int d2=u->cmp(k);
		int k2=d2==1?k-u->son[0]->size-1:k;
		if(d2!=-1)
		{
			m41441(u->son[d2],k2);
			if(d2==d) adjust(r,d);
			else adjust(r->son[d],d2);
		}
		adjust(r,d);
	}
	return;
}
void split(jp* all,int k,jp* &left,jp* &right)
{
	m41441(all,k);
	left=all;
	right=all->son[1];
	left->son[1]=null;
	left->updata();
	return;
}
jp *merge(jp* left,jp* right)
{
	m41441(left,left->size);
	left->son[1]=right;
	left->updata();
	return left;
}
void rEverse(int l,int r)
{
	jp *temp,*left,*mid,*right;
	split(root,l,left,temp);
	split(temp,r-l+1,mid,right);
	mid->flag^=true;
	root=merge(merge(left,mid),right);
	return;
}
int tot=0;
void print(jp* &r)
{
	if(r==null) return;
	r->down();
	print(r->son[0]);
	if(r->key)
	{
		printf("%d",r->key);
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

