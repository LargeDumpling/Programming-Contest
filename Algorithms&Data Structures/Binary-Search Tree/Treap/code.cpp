/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-26	File created.
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
	int data,v,size;
	jp *son[2];
	jp()
	{
		data=v=size=0;
		son[0]=son[1]=null;
	}
	int cmp(int x)
	{
		return (x==data)?-1:data<x;
	}
	void maintain()
	{
		if(this==null)return;
		size=1+son[0]->size+son[1]->size;
		return;
	}
}*root;
void adjust(jp* &r,int d)
{
	jp* temp=r->son[d];
	r->son[d]=temp->son[d^1];
	temp->son[d^1]=r;
	r->maintain();
	temp->maintain();
	r=temp;
	return;
}
void insert(jp* &r,int key)
{
	if(r==null)
	{
		r=new jp();
		r->v=rand();
		r->data=key;
		r->size=1;
		return;
	}
	int d=r->cmp(key);
	if(d==-1)d=0;
	r->size++;
	insert(r->son[d],key);
	if(r->son[d]->v>r->v)
		adjust(r,d);
	return;
}
void del(jp* &r,int key)
{
	if(r==null)return;
	int d=r->cmp(key);
	if(d==-1)
	{
		if(r->son[0]==null)r=r->son[0];
		else if(r->son[1]==null)r=r->son[1];
		else
		{
			int d2=r->son[1]->v > r->son[0]->v;
			adjust(r,d2);
			del(r->son[d2^1],key);
		}
	}
	else del(r->son[d],key);
	r->maintain();
	return;
}
int query(jp* &r,int key)
{
	if(r==null)return 0;
	int ans=0,d=r->cmp(key);
	ans=query(r->son[0],key);
	if(!d)
		return ans;
	ans++;
	if(r==1)
		ans+=query(r->son[1],key);
	return ans;
}
int kth(jp* &r,int k)
{
	if(k<=r->son[0]->size)
		return kth(r->son[0],k);
	k-=(r->son[0]->size+1);
	if(!k)
		return r->data;
	return kth(r->son[1],k);
}
int presuf(int key,int d)
{
	int ans=0,d2;
	for(jp *o=root;o!=null;o=o->son[d])
	{
		d2=o->cmp(key);
		if(d2==-1)
	}
	return anse;
}
/*
����Ҫдһ�����ݽṹ���ɲο���Ŀ���⣩����ά��һЩ����������Ҫ�ṩ���²�����
1. ����x��
2. ɾ��x��(���ж����ͬ��������ֻɾ��һ��)
3. ��ѯx��������(���ж����ͬ�������������С������)
4. ��ѯ����Ϊx����
5. ��x��ǰ��(ǰ������ΪС��x����������)
6. ��x�ĺ��(��̶���Ϊ����x������С����)
*/
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	null=new jp();
	root=root->son[0]=root->son[1]=null->son[0]=null->son[1]=null;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

