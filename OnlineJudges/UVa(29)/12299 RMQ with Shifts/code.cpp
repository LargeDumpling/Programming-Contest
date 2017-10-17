/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,data[400050],num[100050];
void build(int root,int L,int R)
{
	if(L==R)
	{
		data[root]=num[L];
		return;
	}
	int mid=(L+R)>>1;
	build(root<<1,L,mid);
	build(root<<1|1,mid+1,R);
	data[root]=min(data[root<<1],data[root<<1|1]);
	return;
}
void change(int root,int x,int key,int L,int R)
{
	if(L==x&&x==R)
	{
		data[root]=key;
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid) change(root<<1,x,key,L,mid);
	else if(mid<x) change(root<<1|1,x,key,mid+1,R);
	data[root]=min(data[root<<1],data[root<<1|1]);
	return;
}
int query(int root,int l,int r,int L,int R)
{
	if(l<=L&&R<=r) return data[root];
	int mid=(L+R)>>1,ans=2147483647;
	if(l<=mid) ans=min(ans,query(root<<1,l,r,L,mid));
	if(mid<r) ans=min(ans,query(root<<1|1,l,r,mid+1,R));
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int l,r,x;
	char ch;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	build(1,1,n);
	while(m--)
	{
		while(true)
		{
			ch=getchar();
			if(ch=='q'||ch=='s') break;
		}
		if(ch=='q')
		{
			getchar(); getchar(); getchar(); getchar(); getchar();
			scanf("%d",&l); getchar(); scanf("%d",&r); getchar(); getchar();
			//scanf("%d,%d",&l,&r);
			printf("%d\n",query(1,l,r,1,n));
		}
		else if(ch=='s')
		{
			getchar(); getchar(); getchar(); getchar(); getchar();
			vector<int> shift;
			while(true)
			{
				scanf("%d",&x);
				shift.push_back(x);
				if(getchar()==')') break;
			}
			getchar();
			if(shift.size()>1)
			{
				l=num[shift[0]];
				for(unsigned i=0;i<shift.size()-1;i++)
					num[shift[i]]=num[shift[i+1]];
				num[shift[shift.size()-1]]=l;
				for(unsigned i=0;i<shift.size();i++)
					change(1,shift[i],num[shift[i]],1,n);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

