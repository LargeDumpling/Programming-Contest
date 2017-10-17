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
#include<algorithm>
using namespace std;
int data[400050][2],tag[400050];
void down(int root)
{
	if(tag[root]==-1) return;
	data[root<<1][0]=max(data[root<<1][0],tag[root]);
	data[root<<1][1]=max(data[root<<1][1],tag[root]);
	tag[root<<1]=max(tag[root<<1],tag[root]);
	data[root<<1|1][0]=max(data[root<<1|1][0],tag[root]);
	data[root<<1|1][1]=max(data[root<<1|1][1],tag[root]);
	tag[root<<1|1]=max(tag[root<<1|1],tag[root]);
	tag[root]=-1;
	return;
}
void change(int root,int l,int r,int h,int L,int R)
{
	if(L!=R) down(root);
	if(l<=L&&R<=r)
	{
		data[root][0]=max(data[root][0],h);
		data[root][1]=max(data[root][1],h);
		tag[root]=h;
		return;
	}
	int mid=(L+R)>>1;
	if(l<=mid) change(root<<1,l,r,h,L,mid);
	if(mid<r) change(root<<1|1,l,r,h,mid+1,R);
	data[root][0]=min(data[root<<1][0],data[root<<1|1][0]);
	data[root][1]=max(data[root<<1][1],data[root<<1|1][1]);
	return;
}
int query(int root,int l,int r,int h,int L,int R)
{
	int ans=0;
	if(L!=R) down(root);
	if(l<=L&&R<=r&&(h<data[root][0]||data[root][1]<=h))
		return h<data[root][0]?0:(R-L+1);
	int mid=(L+R)>>1;
	if(l<=mid) ans+=query(root<<1,l,r,h,L,mid);
	if(mid<r) ans+=query(root<<1|1,l,r,h,mid+1,R);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,n,l,r,h,ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(data,0,sizeof(data));
		memset(tag,-1,sizeof(tag));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&l,&r,&h); r--;
			if(l>r) continue;
			ans+=query(1,l,r,h,1,100000);
			fprintf(stderr,"%d\n",ans);
			change(1,l,r,h,1,100000);
		}
		printf("%d\n",ans);
		fprintf(stderr,"\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

