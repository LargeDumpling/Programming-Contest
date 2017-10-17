/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
//const unsignelong long mod=1000000007;
unsigned long long P[400050];
struct jp *null;
struct jp
{
	int size;
	unsigned long long key[2],v;
	bool flag;
	jp *son[2];
	jp(const char &x=0)
	{ key[0]=key[1]=v=x; size=1; son[0]=son[1]=null; flag=false;}
	int cmp(const int &x=0)
	{ return x==son[0]->size+1?-1:(x<son[0]->size+1?0:1); }
	void updata()
	{
		size=son[0]->size+son[1]->size+1;
		/*key[0]=(son[0]->key[0]
			+(v*P[son[0]->size])%mod
			+(son[1]->key[0]*P[son[0]->size+1])%mod)%mod;
		key[1]=(son[1]->key[1]
			+(v*P[son[1]->size])%mod
			+(son[0]->key[1]*P[son[1]->size+1])%mod)%mod;*/
		key[0]=son[0]->key[0]+v*P[son[0]->size]+son[1]->key[0]*P[son[0]->size+1];
		key[1]=son[1]->key[1]+v*P[son[1]->size]+son[0]->key[1]*P[son[1]->size+1];
		return;
	}
	void reverse()
	{
		flag^=true;
		swap(son[0],son[1]);
		swap(key[0],key[1]);
		return;
	}
	void down()
	{
		if(!flag) return;
		flag=false;
		//swap(son[0],son[1]);
		//swap(key[0],key[1]);
		//son[0]->flag^=true;
		//son[1]->flag^=true;
		son[0]->reverse();
		son[1]->reverse();
		return;
	}
}*root;
int cnt=0;
char tex[200050];
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
	u->key[0]=u->key[1]=u->v=tex[cnt++];
	build(u->son[1],mid+1,r);
	u->updata();
	return;
}
void m41441(jp* &r,int k)
{
	r->down();
	int d=r->cmp(k);
	if(d==1) k-=(r->son[0]->size+1);
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
{//将all中前k个放在left中，后面的放在right中
	m41441(all,k);
	left=all;
	right=all->son[1];
	all->son[1]=null;
	left->updata();
	return;
}
jp* merge(jp* left,jp* right)
{
	m41441(left,left->size);
	left->son[1]=right;
	left->updata();
	return left;
}
void insert(int pos,char x)
{
	pos++;
	jp *left,*right;
	split(root,pos,left,right);
	root=merge(merge(left,new jp(x)),right);
	return;
}
void del(int pos)
{
	jp *temp,*left,*right,*mid;
	split(root,pos,left,temp);
	split(temp,1,mid,right);
	root=merge(left,right);
	return;
}
void rEverse(int l,int r)
{
	jp *all,*left,*mid,*right;
	split(root,l,left,all);
	split(all,r-l+1,mid,right);
	mid->reverse();
	root=merge(merge(left,mid),right);
	return;
}
unsigned long long  get_hash(int l,int r)
{
	unsigned long long ans;
	jp *temp,*left,*mid,*right;
	split(root,l,left,temp);
	split(temp,r-l+1,mid,right);
	ans=mid->key[0];
	root=merge(merge(left,mid),right);
	return ans;
}
int query(int p1,int p2)
{
	int now_size=root->size-1,l,mid,r;
	l=0,r=min(now_size-p1,now_size-p2)+1;
	unsigned long long a1,a2;
	/*if(l+1==r)
	{
		long long a1=get_hash(p1,p1+r-1);
		long long a2=get_hash(p2,p2+r-1);
		if(a1==a2)
			l=r;
	}
	else */while(l<r-1)
	{
		mid=(l+r)>>1;
		a1=get_hash(p1,p1+mid-1);
		a2=get_hash(p2,p2+mid-1);
		if(a1==a2) l=mid;
		else r=mid;
	}
	a1=get_hash(p1,p1+r-1);
	a2=get_hash(p2,p2+r-1);
	if(a1==a2)
		l=r;
	return l;
}
void print(jp* &r)
{
	if(r==null) return;
	r->down();
	print(r->son[0]);
	//if(r->v!=0) putchar(r->v);
	print(r->son[1]);
	return;
}
void print() { print(root);/* putchar('\n'); */return; }
int n,m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tem[5];
	int a,b,c;
	root=null=new jp();
	null->son[0]=null->son[1]=null;
	null->size=0;
	P[0]=1;// for(int i=1;i<400050;i++) P[i]=(P[i-1]*79)%mod;
	for(int i=1;i<400050;i++) P[i]=P[i-1]*79;
	tex[0]=0;
	scanf("%d%d%s",&n,&m,tex+1);
	build(root,0,n);
	//print();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		switch(a)
		{
			case 1:
				scanf("%s",tem);
				insert(b,tem[0]);
				//print();
				break;
			case 2:
				del(b);
				//print();
				break;
			case 3:
				scanf("%d",&c);
				rEverse(b,c);
				//print();
				break;
			case 4:
				scanf("%d",&c);
				printf("%d\n",query(b,c));
				//print();
			default:
				break;
		}
	}
	fprintf(stderr,"code's time = %.3lf\n",clock()/(double)CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

