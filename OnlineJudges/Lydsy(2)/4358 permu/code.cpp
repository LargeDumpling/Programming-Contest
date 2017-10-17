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
#include<ctime>
#include<algorithm>
using namespace std;
struct jp { int l,r,id,ans,L,R; }Q[50050];
//int data[200050],combo[200050][3];
const int M=131072;
int data[M<<1],combo[M<<1][3];
bool all[M<<1];
int n,m,val[50050],BLOCK;
/*void change(int root,int l,int r,int pos,int add)
{
	if(l==pos&&pos==r)
	{
		data[root]+=add;
		combo[root][0]=combo[root][1]=combo[root][2]=0;
		if(data[root]>0)
			combo[root][0]=combo[root][1]=combo[root][2]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) change(root<<1,l,mid,pos,add);
	else if(mid<pos) change(root<<1|1,mid+1,r,pos,add);
	if((combo[root][0]=combo[root<<1][0])==mid-l+1)
		combo[root][0]+=combo[root<<1|1][0];
	if((combo[root][2]=combo[root<<1|1][2])==r-mid)
		combo[root][2]+=combo[root<<1][2];
	combo[root][1]=max(combo[root<<1][2]+combo[root<<1|1][0],
					max(combo[root<<1][1],combo[root<<1|1][1]));
	return;
}*/
void change(int pos,int add)
{
	int root=pos+M;
	data[root]+=add;
	combo[root][0]=combo[root][1]=combo[root][2]=0;
	all[root]=false;
	if(data[root]>0)
	{
		combo[root][0]=combo[root][1]=combo[root][2]=1;
		all[root]=true;
	}
	root>>=1;
	while(root)
	{
		combo[root][0]=combo[root<<1][0];
		if(all[root<<1]) combo[root][0]+=combo[root<<1|1][0];
		combo[root][2]=combo[root<<1|1][2];
		if(all[root<<1|1]) combo[root][2]+=combo[root<<1][2];
		combo[root][1]=max(combo[root<<1][1],combo[root<<1|1][1]);
		combo[root][1]=max(combo[root][1],combo[root<<1][2]+combo[root<<1|1][0]);
		all[root]=all[root<<1]&all[root<<1|1];
		root>>=1;
	}
	return;
}
bool cmp(jp a,jp b)
{ return a.L==b.L?a.R<b.R:a.L<b.L; }
bool cmp_id(jp a,jp b) { return a.id<b.id; }
int read1n()
{
	int x;
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int l,r;
	//scanf("%d%d",&n,&m);
	n=read1n(); m=read1n();
	BLOCK=sqrt(n);
	for(int i=1;i<=n;i++)// scanf("%d",&val[i]);
		val[i]=read1n();
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d",&Q[i].l,&Q[i].r);
		Q[i].l=read1n(); Q[i].r=read1n();
		Q[i].L=Q[i].l/BLOCK;
		Q[i].R=Q[i].r/BLOCK;
		Q[i].l--;
		Q[i].id=i;
	}
	sort(Q+1,Q+m+1,cmp);
	l=r=0;
	for(int i=1;i<=m;i++)
	{
		/*while(r<Q[i].r) change(1,1,n,val[++r],1);
		while(r>Q[i].r) change(1,1,n,val[r--],-1);
		while(l<Q[i].l) change(1,1,n,val[++l],-1);
		while(l>Q[i].l) change(1,1,n,val[l--],1);*/
		while(r<Q[i].r) change(val[++r],1);
		while(r>Q[i].r) change(val[r--],-1);
		while(l<Q[i].l) change(val[++l],-1);
		while(l>Q[i].l) change(val[l--],1);
		Q[i].ans=combo[1][1];
	}
	sort(Q+1,Q+m+1,cmp_id);
	for(int i=1;i<=m;i++) printf("%d\n",Q[i].ans);
	fprintf(stderr,"%.6f\n",(double)clock()/CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

