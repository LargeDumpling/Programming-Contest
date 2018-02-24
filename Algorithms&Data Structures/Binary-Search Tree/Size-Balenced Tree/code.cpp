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
	int size,data;
	jp* son[2];
	jp()
	{
		son[0]=son[1]=null;
		size=data=0;
	}
}*root;
void adjust(jp* &x,int d)
{
	if(x==null)
		return;
	jp *temp=x->son[d];
	int t=x->size-temp->size;
	x->size=x->size-(temp->size)+(temp->son[d^1]->size);
	temp->size+=t;
	x->son[d]=temp->son[d^1];
	temp->son[d^1]=x;
	x=temp;
	return;
}
void maintain(jp* &x,int d)
{
	if(x==null)
		return;
	if(((x->son[d])->son[d]->size)>(x->son[d^1]->size))
		adjust(x,d);
	else if(((x->son[d])->son[d^1]->size>(x->son[d^1]->size)))
	{
		adjust(x->son[d],d^1);
		adjust(x,d);
	}
	else
		return;
	maintain(x->son[0],0);
	maintain(x->son[1],1);
	maintain(x,0);
	maintain(x,1);
	return;
}
void insert(jp* &x,int key)
{
	if(x==null)
	{
		x=new jp();
		x->size=1;
		x->data=key;
		return;
	}
	x->size++;
	if(key!=x->data)
	{
		insert(x->son[key>x->data],key);
		maintain(x,key>x->data);
	}
//	if(key<x->data)
//		insert(x->son[0],key);
//	else if(key>x->data)
//		insert(x->son[1],key);
	return;
}
int del(jp* &x,int key)
{
	x->size--;
	if(x->data==key||x->son[key>x->data]==null)
	{
		if(!(x->size-x->son[0]->size-x->son[1]->size))
		{
			int ans=x->data;
			if(x->son[0]==null||x->son[1]==null)
				x=x->son[0]==null?x->son[1]:x->son[0];
			else
				x->data=del(x->son[0],2147483647);
			return ans;
		}
		else
			return x->data;
	}
	else
		return del(x->son[key>x->data],key);
}
void print(jp* x)
{
	if(x==null)
		return;
	print(x->son[0]);
	for(int i=1;i<=x->size-x->son[0]->size-x->son[1]->size;i++)
		printf("%d ",x->data);
	print(x->son[1]);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	null=new jp();
	null->son[0]=null->son[1]=null;
	root=null;
	int n,order,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&order);
		if(order==0)
		{
			scanf("%d",&x);
			insert(root,x);
		}
		else if(order==1)
		{
			scanf("%d",&x);
			del(root,x);
		}
		else if(order==2)
		{
			print(root);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

