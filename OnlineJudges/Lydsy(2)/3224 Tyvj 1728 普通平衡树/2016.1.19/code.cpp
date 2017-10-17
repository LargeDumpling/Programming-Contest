/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-20	File created.
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
	int key,num,size,v;
	jp *son[2];
	jp(const int &x=0):key(x) { v=0; num=size=1; son[0]=son[1]=null; }
	int cmp(const int &x) { return x==key?-1:(x<key?0:1); }
	void updata() { size=son[0]->size+son[1]->size+num; }
}*root;
void adjust(jp* &r,int d)
{//把r结点的d儿子旋转上来
	jp *node=r->son[d];
	r->son[d]=node->son[d^1];
	node->son[d^1]=r;
	r->updata();
	node->updata();
	r=node;
	return;
}
void insert(jp* &r,int x)
{//在r子树中插入一个键值为x的结点
	if(r==null)
	{
		r=new jp(x);
		r->v=rand();
		return;
	}
	r->size++;
	int d=r->cmp(x);
	if(d==-1) r->num++;
	else
	{
		insert(r->son[d],x);
		if(r->son[d]->v > r->v) adjust(r,d);
	}
	return;
}
bool del(jp* &r,int x)
{//在r子树中删除键值为x的结点
	if(r==null) return false;
	int d= r->cmp(x);
	if(d==-1)
	{
		if(r->num > 1) r->num--;
		else
		{
			if(r->son[0]==null||r->son[1]==null)
			{
				jp *temp=r;
				r=(r->son[0]==null)?r->son[1]:r->son[0];
				delete temp;
			}
			else
			{
				d=r->son[0] < r->son[1];
				adjust(r,d);
				r->size--;
				del(r->son[d^1],x);
			}
		}
		r->updata();
		return true;
	}
	bool flag=del(r->son[d],x);
	r->updata();
	return flag;
}
int rank(jp* &r,int x)
{
	if(r==null) return 0;
	int d=r->cmp(x);
	if(!d) return rank(r->son[0],x);
	return r->son[0]->size+(d==-1?1:rank(r->son[1],x)+r->num);
}
int kth(jp* &r,int rk)
{
	if(r==null) return 0;
	if(rk<=r->son[0]->size) return kth(r->son[0],rk);
	else if(rk>r->son[0]->size+r->num)
		return kth(r->son[1],rk - r->son[0]->size - r->num);
	return r->key;
}
int query(int x,int D)
{
	int d,ans=0;
	jp* u=root;
	while(u!=null)
	{
		d=u->cmp(x);
		if(d==(D^1)) ans=u->key;
		u=u->son[d==-1?D:d];
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	null=new jp();
	root=null->son[0]=null->son[1]=null;
	null->num=null->size=0;
	int T_T,a,b;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&a,&b);
		switch(a)
		{
			case 1: insert(root,b); break;
			case 2: del(root,b); break;
			case 3: printf("%d\n",rank(root,b)); break;
			case 4: printf("%d\n",kth(root,b)); break;
			case 5: printf("%d\n",query(b,0)); break;
			case 6: printf("%d\n",query(b,1)); break;
			default: break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

