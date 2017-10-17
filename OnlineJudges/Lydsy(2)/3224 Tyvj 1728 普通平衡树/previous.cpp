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
	int x,num,sonn[2],v;
	jp *son[2];
	jp()
	{
		x=num=sonn[0]=sonn[1]=0;
		son[0]=son[1]=null;
	}
	int cmp(int data)
	{
		return x==data?-1:x<data;
	}
}*root;
void adjust(jp* &r,int d)
{
	jp* temp=r->son[d];
	r->sonn[d]-=(temp->sonn[d]+temp->num);
	temp->sonn[d^1]+=r->sonn[d^1]+r->num;
	r->son[d]=temp->son[d^1];
	temp->son[d^1]=r;
	r=temp;
	return;
}
void insert(jp* &r,int data)
{
	if(r!=null)
	{
		int d=r->cmp(data);
		if(d==-1)
			r->num++;
		else
		{
			r->sonn[d]++;
			insert(r->son[d],data);
			if(r->son[d]->v > r->v)
				adjust(r , d);
		}
		return;
	}
	r=new jp();
	r->v=rand();
	r->x=data;
	r->num=1;
	return;
}
void del(jp* &r,int data)
{
	int d=r->cmp(data);
	if(d==-1)
	{
		if(r->num>1)
			r->num--;
		else
		{
			jp* temp=r;
			if(r->son[0]==null&&r->son[1]==null)
			{
				r=null;
				delete temp;
			}
			else if(r->son[0]==null||r->son[1]==null)
			{
				if(r->son[0]!=null)
					r=r->son[0];
				else
					r=r->son[1];
				delete temp;
			}
			else
			{
				int d2=r->son[0]->v < r->son[1]->v;
				adjust(r,d2);
				r->sonn[d2^1]--;
				del(r->son[d2^1],data);
			}
		}
		return;
	}
	r->sonn[d]--;
	del(r->son[d],data);
	return;
}
int rank(jp* r,int data)
{
	if(r==null)
		return 0;
	int d=r->cmp(data);
	if(d==-1)
		return r->sonn[0]+1;
	else if(d==0)
		return rank(r->son[0],data);
	else if(d==1)
		return r->sonn[0]+r->num+rank(r->son[1],data);
	return 0;
}
int kth(jp* r,int k)
{
	if(k<=r->sonn[0])
		return kth(r->son[0],k);
	k-=r->sonn[0]+r->num;
	if( k <= 0)
		return r->x;
	else
		return kth(r->son[1],k);
	return 0;
}
int find(int data,int d)
{
	int ans=root->x,d2;
	jp* r=root;
	while(r!=null)
	{
		d2=r->cmp(data);
		if(d2==(d^1))
			ans=r->x;
		r=r->son[d2!=-1?d2:d];
	}
	return ans;
}
/*
您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
1. 插入x数
2. 删除x数(若有多个相同的数，因只删除一个)
3. 查询x数的排名(若有多个相同的数，因输出最小的排名)
4. 查询排名为x的数
5. 求x的前驱(前驱定义为小于x，且最大的数)
6. 求x的后继(后继定义为大于x，且最小的数)
*/
int main()
{
	freopen("code.in","r",stdin);
	freopen("previous.out","w",stdout);
	root=null=new jp();
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a==1)
			insert(root,b);
		else if(a==2)
			del(root,b);
		else if(a==3)
			printf("%d\n",rank(root,b));
		else if(a==4)
			printf("%d\n",kth(root,b));
		else
			printf("%d\n",find(b,a-5));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
