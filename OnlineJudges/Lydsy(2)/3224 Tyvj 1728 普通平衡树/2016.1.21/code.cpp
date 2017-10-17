/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=10000000;
char in[D],*I=in;
bool read1n(int &x)
{
	int sig=1;
	for(x=0;*I<'0'||'9'<*I;I++)
		if(*I==-1) return false;
		else if(*I=='-') sig=-1;
	while('0'<=*I&&*I<='9') x=(x<<1)+(x<<3)+*(I++)-'0';
	x*=sig;
	return true;
}
struct jp *null;
struct jp
{
	int key,num,size,v;
	jp *son[2];
	jp(const int &X=0):key(X) { num=size=1; v=rand(); son[0]=son[1]=null; }
	int cmp(const int &x) { return x==key?-1:(x<key?0:1); }
	void updata() { size=son[0]->size+son[1]->size+num; }
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
	if(d==-1) r->num++;
	else
	{
		insert(r->son[d],x);
		if(r->son[d]->v > r->v) adjust(r,d);
	}
	r->updata();
	return;
}
bool del(jp* &r,int x)
{
	if(r==null) return false;
	int d=r->cmp(x);
	if(d==-1)
	{
		if(r->num>1) r->num--;
		else
		{
			if(r->son[0]==null||r->son[1]==null)
			{
				jp *u=r;
				r=r->son[0]==null?r->son[1]:r->son[0];
				delete u;
			}
			else
			{
				d=r->son[0]->v < r->son[1]->v;
				adjust(r,d);
				del(r->son[d^1],x);
			}
		}
		r->updata();
		return true;
	}
	bool flag=del(r->son[d],x);
	if(flag) r->updata();
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
	rk-=(r->son[0]->size+r->num);
	return rk>0?kth(r->son[1],rk):r->key;
}
int query(int x,int D)
{
	jp *u=root; int ans=0,d;
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
	in[fread(in,1,D,stdin)]=-1;
	root=null=new jp();
	null->son[0]=null->son[1]=null;
	null->num=null->size=0;
	int n,a,b;
	read1n(n);
	while(n--)
	{
		read1n(a),read1n(b);
		switch(a)
		{
			case 1:
				insert(root,b);
				break;
			case 2:
				del(root,b);
				break;
			case 3:
				printf("%d\n",rank(root,b));
				break;
			case 4:
				printf("%d\n",kth(root,b));
				break;
			default:
				printf("%d\n",query(b,a-5));
				break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

