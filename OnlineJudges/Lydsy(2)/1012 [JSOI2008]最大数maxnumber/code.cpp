#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int data[800050],n,m,D;
void change(int root,int pos,int x,int l,int r)
{
	if(l==pos&&pos==r)
	{
		data[root]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		change(root<<1,pos,x,l,mid);
	else
		change(root<<1|1,pos,x,mid+1,r);
	data[root]=max(data[root<<1],data[root<<1|1]);
	return;
}
int query(int root,int L,int R,int l,int r)
{
	if(L<=l&&r<=R)
		return data[root];
	int mid=(l+r)>>1,a,ans=0;
	if(L<=mid)
	{
		a=query(root<<1,L,R,l,mid);
		ans=max(ans,a);
	}
	if(mid<R)
	{
		a=query(root<<1|1,L,R,mid+1,r);
		ans=max(ans,a);
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char ch[2];
	int x,ans=0;
	scanf("%d%d",&m,&D);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d",ch,&x);
		if(ch[0]=='A')
		{
			x=(x+ans)%D;
			change(1,++n,x,1,200000);
		}
		else if(ch[0]=='Q')
		{
			ans=query(1,n-x+1,n,1,200000);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

