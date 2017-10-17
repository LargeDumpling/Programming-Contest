/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N=400000;
int n,m,num[20050],numh[20050],hash[20050],tem[20050],tot,ans;
int sum[N][3],tag[N],son[N][2],sz=0;
int root[20050];
int find(int x) { return lower_bound(hash+1,hash+tot+1,x)-hash; };
void maintain(int now)
{
	sum[now][1]=sum[son[now][0]][1]+sum[son[now][1]][1];
	sum[now][0]=max(sum[son[now][0]][0],sum[son[now][0]][1]+sum[son[now][1]][0]);
	sum[now][2]=max(sum[son[now][1]][2],sum[son[now][1]][1]+sum[son[now][0]][2]);
	return;
}
void build(int &now,int l,int r)
{
	now=++sz;
	if(l==r)
	{
		sum[now][0]=sum[now][1]=sum[now][2]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(son[now][0],l,mid);
	build(son[now][1],mid+1,r);
	maintain(now);
	return;
}
void change(int pre,int &now,int l,int r,int pos,int x)
{
	now=++sz;
	sum[now][1]=x;
	sum[now][0]=sum[now][2]=x;
	son[now][0]=son[pre][0];
	son[now][1]=son[pre][1];
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) change(son[pre][0],son[now][0],l,mid,pos,x);
	else change(son[pre][1],son[now][1],mid+1,r,pos,x);
	maintain(now);
	return;
}
vector<int> havas[20050];
int querym(int now,int l,int r,int L,int R)
{
	if(L>R) return 0;
	if(L<=l&&r<=R) return sum[now][1];
	int ans=0,mid=(l+r)>>1;
	if(L<=mid) ans+=querym(son[now][0],l,mid,L,R);
	if(mid<R) ans+=querym(son[now][1],mid+1,r,L,R);
	return ans;
}
int queryr(int now,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return sum[now][2];
	int ans=-1000000,mid=(l+r)>>1;
	if(R<=mid) ans=queryr(son[now][0],l,mid,L,R);
	else if(mid<L) ans=queryr(son[now][1],mid+1,r,L,R);
	else
	{//L<=mid&&mid<R
		ans=max(queryr(son[now][1],mid+1,r,L,R),
				querym(son[now][1],mid+1,r,L,R)+queryr(son[now][0],l,mid,L,R));
	}
	return ans;
}
int queryl(int now,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return sum[now][0];
	int ans=-1000000,mid=(l+r)>>1;
	if(L<=mid) ans=queryl(son[now][0],l,mid,L,R);
	else if(mid<R) ans=queryl(son[now][1],mid+1,r,L,R);
	else
	{//L<=mid&&mid<R
		ans=max(queryl(son[now][0],mid+1,r,L,R),
				querym(son[now][0],mid+1,r,L,R)+queryl(son[now][1],l,mid,L,R));
	}
	return ans;
}
void print(int now,int l,int r)
{
	if(l==r)
	{
		fprintf(stderr,"%d ",sum[now][1]);
		return;
	}
	int mid=(l+r)>>1;
	print(son[now][0],l,mid);
	print(son[now][1],mid+1,r);
	return;
}
void print(int now)
{
	fprintf(stderr,"%d\n",now);
	print(root[now],1,n);
	fprintf(stderr,"\n");
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int para[4],k,l,r,mid;
	scanf("%d",&n);
	tot=tem[0]=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		tem[i]=num[i];
	}
	sort(tem+1,tem+n+1);
	hash[++tot]=tem[1];
	for(int i=2;i<=n;i++)
		if(tem[i]!=tem[i-1])
			hash[++tot]=tem[i];
	for(int i=1;i<=n;i++)
	{
		numh[i]=find(num[i]);
		havas[numh[i]].push_back(i);
	}
	build(root[1],1,n);
	print(1);
	for(int i=2;i<=n;i++)
	{
		for(unsigned j=0;j<havas[i-1].size();j++)
			change(root[i-1],root[i],1,n,havas[i-1][j],-1);
		print(i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",&para[j]);
			para[j]=(para[j]+ans)%n;
		}
		sort(para,para+4);
		for(int j=0;j<4;j++) para[j]++;
		l=1; r=n+1;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			k=queryr(root[mid],1,n,para[0],para[1])+
				querym(root[mid],1,n,para[1]+1,para[2]-1)+
				queryl(root[mid],1,n,para[2],para[3]);
			if(k>=0) l=mid;
			else r=mid;
		}
		ans=hash[l];
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

