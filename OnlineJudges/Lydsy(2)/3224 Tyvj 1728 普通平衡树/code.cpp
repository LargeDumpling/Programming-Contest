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
	int data,size;
	jp *son[2];
	jp(const int a=0,const int b=0):data(a),size(b)
	{
		son[0]=son[1]=null;
	}
}*root;
void adjust(jp* &node,int d)
{
	jp *temp=node->son[d];
	int t=node->size-temp->size;
	node->size-=(temp->size-temp->son[d^1]->size);
	temp->size+=t;
	node->son[d]=temp->son[d^1];
	temp->son[d^1]=node;
	node=temp;
	return;
}
void insert(jp* &r,int key)
{
	if(r==null)
	{
		r=new jp(key,1);
		return;
	}
	r->size++;
	if(r->data!=key)
		insert(r->son[r->data<key],key);
	return;
}
void del(jp* &r,int key)
{
	if(r==null)
		return;
	if(r->data==key)
	{
		if(r->size-(r->son[0]->size)-(r->son[1]->size)==1)
		{
			for(int d;r->son[0]!=null&&r->son[1]!=null;r=r->son[d^1])
				adjust(r,d=(r->son[0]->size<r->son[1]->size));
			if(r->son[0]!=null)
				r=r->son[0];
			else if(r->son[1]!=null)
				r=r->son[1];
			else
				r=null;
		}
		else
			r->size--;
		return;
	}
	else
		del(r->son[r->data<key],key);
	r->size--;
	return;
}
int query(const jp *r,int key)
{
	if(r==null)
		return 1;
	if(r->data==key)
		return r->son[0]->size+1;
	if(key<r->data)
		return query(r->son[0],key);
	return r->size-r->son[1]->size+query(r->son[1],key);
}
int k_th(const jp *r,int rank)
{
	if(r==null)
		return 0;
	if(rank<=r->son[0]->size)
		return k_th(r->son[0],rank);
	rank-=r->son[0]->size;
	return (rank<=r->size-r->son[1]->size-r->son[0]->size)?r->data:k_th(r->son[1],rank-(r->size-r->son[1]->size-r->son[0]->size));
}
int find(int key,int d)
{
	int d2,ans;
	d2=root->data==key?-1:root->data<key;
	if(d2==-1||d2==d)
		ans=0;
	else
		ans=root->data;
	jp *r=root;
	while(r!=null)
	{
		d2=r->data==key?-1:r->data<key;
		if(d2==(d^1))
			ans=r->data;
		r=r->son[d2==-1?d:d2];
	}
	return ans;
}
int n;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	null=new jp();
	root=null->son[0]=null->son[1]=null;
	int opt,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&opt,&x);
		if(opt==1)
			insert(root,x);
		else if(opt==2)
			del(root,x);
		else if(opt==3)
			printf("%d\n",query(root,x));
		else if(opt==4)
			printf("%d\n",k_th(root,x));
		else if(opt==5||opt==6)
			printf("%d\n",find(x,opt-5));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

