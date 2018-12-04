/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
struct BST_node
{
	int data;
	BST_node *son[2];
	BST_node(const int &x=0):data(x) { son[0]=son[1]=NULL; }
	int cmp(int x) { return x==data?-1:data<x; }
}*root;
int n,m;
bool insert(BST_node* &r,int x)
{
	if(r==NULL)
	{
		r=new BST_node(x);
		return true;
	}
	int d=r->cmp(x);
	return d==-1?false:insert(r->son[d],x);
}
bool del(BST_node* &r,int x)
{
	if(r==NULL) return false;
	int d=r->cmp(x);
	if(d==-1)
	{
		if(r->son[0]!=NULL&&r->son[1]!=NULL)
		{
			BST_node* t=r->son[0];
			while(t->son[1]) t=t->son[1];
			int tem=t->data;
			del(r,t->data);
			r->data=tem;
		}
		else
		{
			BST_node* tem=r;
			r=r->son[r->son[1]!=NULL];
			delete tem;
		}
		return true;
	}
	return del(r->son[d],x);
}
bool find(BST_node* r,int x)
{
	if(r==NULL) return false;
	int d=r->cmp(x);
	return d==-1?true:find(r->son[d],x);
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
	freopen("BST.in","r",stdin);
	freopen("BST.out","w",stdout);
	int op,x;
	//scanf("%d%d",&n,&m);
	read1n(n);
	read1n(m);
	while(n--)
	{
		//scanf("%d",&x);
		read1n(x);
		insert(root,x);
	}
	while(m--)
	{
		//scanf("%d%d",&op,&x);
		read1n(op);
		read1n(x);
		switch(op)
		{
			case 1:
				puts(insert(root,x)?"Yes":"No");
				break;
			case 2:
				puts(del(root,x)?"Yes":"No");
				break;
			case 3:
				puts(find(root,x)?"Yes":"No");
				break;
			default:
				break;
		}
	}
	fprintf(stderr,"Binary Search Tree %lf\n",(double)clock()/CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

