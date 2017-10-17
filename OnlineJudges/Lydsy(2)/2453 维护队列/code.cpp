/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int BS,pre_pos[1000050],n,m;
int A[10050],B[10050],L[10050],R[10050],pre[10050],last[10050];
void calc_pre()
{
	memset(pre_pos,-1,sizeof(pre_pos));
	for(int i=0;i<n;i++) { pre[i]=pre_pos[A[i]]; pre_pos[A[i]]=i; }
	return;
}
void mAintain(int x)
{
	for(int i=L[x];i<R[x];i++) B[i]=pre[i];
	sort(B+L[x],B+R[x]);
	return;
}
int qUery(int l,int r)
{
	int ans=0;
	if(L[l]!=L[r])
	{
		for(int i=l;i<R[l];i++) if(pre[i]<l) ans++;
		for(int i=L[r];i<=r;i++) if(pre[i]<l) ans++; r=L[r];
		for(int i=R[l];i<r;i=R[i]) ans+=(lower_bound(B+i,B+R[i],l)-(B+i));
	}
	else if(L[l]==L[r]) for(int i=l;i<=r;i++) if(pre[i]<l) ans++;
	return ans;
}
void cHange(int x,int v)
{
	for(int i=0;i<n;i++) pre_pos[A[i]]=-1;
	A[x]=v;
	for(int i=0;i<n;i++)
	{
		int t=pre[i];
		pre[i]=pre_pos[A[i]];
		if(t!=pre[i]) mAintain(i);
		pre_pos[A[i]]=i;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char ord[5];
	int a,b;
	scanf("%d%d",&n,&m);
	BS=sqrt(n);
	for(int i=0;i<n;i++) { L[i]=(i/BS)*BS; R[i]=min(n,L[i]+BS); }
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	calc_pre(); for(int i=0;i<n;i+=BS) mAintain(i);
	while(m--)
	{
		scanf("%s%d%d",ord,&a,&b); a--;
		switch(ord[0])
		{
			case 'Q':
				b--;
				printf("%d\n",qUery(a,b));
				break;
			case 'R':
				cHange(a,b);
				break;
			default: break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

