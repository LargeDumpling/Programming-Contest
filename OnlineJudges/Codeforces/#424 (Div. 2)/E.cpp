/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=1<<17;
int tot[M<<1];
struct jp
{
	int num,idx;
	bool operator<(const jp &x)const
	{
		return num==x.num?idx>x.idx:num<x.num;
	}
}a[100050];
int n;
int query(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans+=tot[L^1];
		if(R&1) ans+=tot[R^1];
	}
	return ans;
}
void build()
{
	memset(tot,0,sizeof(tot));
	for(int i=1;i<=n;i++) tot[i+M]=1;
	for(int i=M-1;i;i--)
		tot[i]=tot[i<<1]+tot[i<<1|1];
	return;
}
void dec(int p)
{
	tot[p+M]--;
	for(p=(p+M)>>1;p;p>>=1)
		tot[p]--;
	return;
}
int lef[100050],rig[100050];
void del(int p)
{
	int lEft=lef[p],rIght=rig[p];
	lef[rIght]=lEft;
	rig[lEft]=rIght;
	return;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int pre;
	long long ans=0;
	scanf("%d",&n);
	build();
	lef[1]=n;
	rig[n]=1;
	for(int i=1;i<=n;i++)
	{
		if(i!=1) lef[i]=i-1;
		if(i!=n) rig[i]=i+1;
		a[i].idx=i;
		scanf("%d",&a[i].num);
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)
		//printf("%d %d\n",a[i].num,a[i].idx);
	pre=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i].idx<=pre) ans+=query(a[i].idx,pre);
		else ans+=query(1,pre)+query(a[i].idx,n);
		dec(a[i].idx);
		del(a[i].idx);
		pre=lef[a[i].idx];
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

