#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int data[800050][2],mIn[800050],mAx[800050],mI,mA,ans,n,m,num[800050];
int read1n()
{
	char ch;int x=0;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		mAx[root]=mIn[root]=num[l];
		data[root][0]=data[root][1]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root][0]=max(max(data[root<<1][0],data[root<<1|1][0]),mAx[root<<1]-mIn[root<<1|1]);
	data[root][1]=max(max(data[root<<1][1],data[root<<1|1][1]),mAx[root<<1|1]-mIn[root<<1]);
	mIn[root]=min(mIn[root<<1],mIn[root<<1|1]);
	mAx[root]=max(mAx[root<<1],mAx[root<<1|1]);
	return;
}
void query_A(int root,int ql,int qr,int l,int r)
{
	if(ql<=l&&r<=qr)
	{
		ans=max(max(ans,mA-mIn[root]),data[root][0]);
		mA=max(mA,mAx[root]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)
		query_A(root<<1,ql,qr,l,mid);
	if(qr>mid)
		query_A(root<<1|1,ql,qr,mid+1,r);
	return;
}
void query_I(int root,int ql,int qr,int l,int r)
{
	if(ql<=l&&r<=qr)
	{
		ans=max(max(ans,mAx[root]-mI),data[root][1]);
		mI=min(mI,mIn[root]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)
		query_I(root<<1,ql,qr,l,mid);
	if(qr>mid)
		query_I(root<<1|1,ql,qr,mid+1,r);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		num[i]=read1n();
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		if(l<=r)
		{
			ans=0;
			mI=2147483647;
			query_I(1,l,r,1,n);
		}
		else if(l>r)
		{
			l^=r;
			r=l^r;
			l^=r;
			ans=mA=0;
			query_A(1,l,r,1,n);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

