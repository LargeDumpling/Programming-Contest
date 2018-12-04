/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Treap_node *null;
struct Treap_node
{
	int data,num,size,v;
	Treap_node* son[2];
	Treap_node()
	{
		data=num=size=0;
		v=rand();
		son[0]=son[1]=null;
	}
	int cmp(int x)
	{
		if(x==data) return -1;
		return data<x;
	}
	void maintain()
	{
		size=son[0]->size+son[1]->size+num;
		return;
	}
}*root;
void adjust(Treap_node* &r,int d)
{
	Treap_node* t=r->son[d];
	r->son[d]=t->son[d^1];
	t->son[d^1]=r;
	r->maintain();
	(r=t)->maintain();
	return;
}
void insert(Treap_node* &r,int x)
{
	if(r==null)
	{
		r=new Treap_node();
		r->data=x;
		r->size=r->num=1;
		return;
	}
	int d=r->cmp(x);
	if(d==-1) r->num++;
	else
	{
		insert(r->son[d],x);
		if(r->v < r->son[d]->v)
			adjust(r,d);
	}
	r->maintain();
	return;
}
void del(Treap_node* &r,int x)
{
	if(r==null) return;
	int d=r->cmp(x);
	if(d==-1)
	{
		if(1<r->num) r->num--;
		else
		{
			if(r->son[0]!=null && r->son[1]!=null)
			{
				int d1=r->son[0]->v < r->son[1]->v;
				adjust(r,d1);
				del(r->son[d1^1],x);
			}
			else
			{
				int d1=r->son[1]!=null;
				Treap_node* tem=r;
				r=r->son[d1];
				delete tem;
			}
		}
	}
	else del(r->son[d],x);
	r->maintain();
	return;
}
int rank(Treap_node* &r,int x)
{
	if(r==null) return 1;
	int d=r->cmp(x);
	if(!d) return rank(r->son[0],x);
	return r->son[0]->size+(d==-1?1:rank(r->son[1],x)+r->num);
}
int kth(Treap_node* &r,int x)
{
	if(r==null) return 0;
	if(x<=r->son[0]->size) return kth(r->son[0],x);
	x-=r->son[0]->size;
	//Wrong Answer: return x<=r->num?r->data:kth(r->son[0],x-r->num);
	return x<=r->num?r->data:kth(r->son[1],x-r->num);
}
int get_num(Treap_node* &r,int x)
{
	int d=r->cmp(x);
	if(d==-1) return r->num;
	return get_num(r->son[d],x);
}
int neigh(int x,int d)
{
	Treap_node* r=root;
	int ans=0,d1;
	while(r!=null)
	{
		d1=r->cmp(x);
		//Wrong Answer: if(d1!=d) ans=r->data;
		if(d==(d1^1)) ans=r->data;
		r=r->son[d1==-1?d:d1];
	}
	return ans;
}
int T_T;
int main()
{
	freopen("3224.in","r",stdin);
	freopen("3224.out","w",stdout);
	int op,num;
	root=null=new Treap_node();
	null->son[0]=null->son[1]=null;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&op,&num);
		switch(op)
		{
			case 1:
				insert(root,num);
				break;
			case 2:
				del(root,num);
				break;
			case 3:
				printf("%d\n",rank(root,num));
				break;
			case 4:
				printf("%d\n",kth(root,num));
				break;
			case 5:
			case 6:
				printf("%d\n",neigh(num,op-5));
				break;
		}
	}
	//print();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
