/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int l,r,L,id,ans;
}Q[50050];
int cnt[50050],num[50050],n,m,k,BLOCK;
bool cnmp(jp a,jp b) { return a.L==b.L?a.r<b.r:a.L<b.L; }
bool cnmp_ID(jp a,jp b) { return a.id<b.id; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int l,r,ans;
	scanf("%d%d%d",&n,&m,&k);
	BLOCK=sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&Q[i].l,&Q[i].r); Q[i].l--;
		Q[i].L=Q[i].l/BLOCK;
		Q[i].id=i;
		Q[i].ans=0;
	}
	sort(Q+1,Q+m+1,cnmp);
	l=r=ans=0;
	for(int i=1;i<=m;i++)
	{
		while(r<Q[i].r) ans+=(2*(cnt[num[++r]]++)+1);
		while(Q[i].r<r) ans-=(2*(cnt[num[r--]]--)-1);
		while(l<Q[i].l) ans-=(2*(cnt[num[++l]]--)-1);
		while(Q[i].l<l) ans+=(2*(cnt[num[l--]]++)+1);
		Q[i].ans=ans;
	}
	sort(Q+1,Q+m+1,cnmp_ID);
	for(int i=1;i<=m;i++) printf("%d\n",Q[i].ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

