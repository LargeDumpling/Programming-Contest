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
const int MAXN=1000000;
int BLOCK_SIZE=1000;
int A[MAXN+50],B[MAXN+50],L[MAXN+50],R[MAXN+50],tag[MAXN+50],N,Q;
void mAintain(int x)//对x所在的块进行重新维护
{ for(int i=L[x];i<R[x];i++) B[i]=A[i]; sort(B+L[x],B+R[x]); return; }
void pRepare()
{
	for(int i=0;i<N;i++)
	{
		L[i]=(i/BLOCK_SIZE)*BLOCK_SIZE;
		R[i]=min(L[i]+BLOCK_SIZE,N);
	}
	for(int i=0;i<N;i+=BLOCK_SIZE) mAintain(i),tag[i]=0;
	return;
}
void cHange(int l,int r,int x)
{
	if(L[l]!=L[r])//不在同一块
	{
		for(int i=l;i<R[l];i++) A[i]+=x; mAintain(l);
		for(int i=L[r];i<=r;i++) A[i]+=x; mAintain(r); r=L[r];
		for(int i=R[l];L[i]!=r;i+=BLOCK_SIZE) tag[i]+=x;
	}
	else if(L[l]==L[r])//在同一块
	{
		for(int i=l;i<=r;i++) A[i]+=x;
		mAintain(l);
	}
	return;
}
int qUery(int l,int r,int x)
{
	int C,ans=(r-l+1);
	if(L[l]!=L[r])
	{
		C=x-tag[L[l]];
		for(int i=l;i<R[l];i++) if(A[i]<C) ans--;
		C=x-tag[L[r]];
		for(int i=L[r];i<=r;i++) if(A[i]<C) ans--; r=L[r];
		for(int i=R[l];L[i]!=r;i+=BLOCK_SIZE)
		{
			C=x-tag[i];
			ans-=(lower_bound(B+i,B+R[i],C)-(B+i));
		}
	}
	else if(L[l]==L[r])
	{
		C=x-tag[L[l]];
		for(int i=l;i<=r;i++) if(A[i]<C) ans--;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char ord[5];
	int a,b,c;
	scanf("%d%d",&N,&Q);
	BLOCK_SIZE=sqrt(N);
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	pRepare();
	while(Q--)
	{
		scanf("%s%d%d%d",ord,&a,&b,&c); a--; b--;
		switch(ord[0])
		{
			case 'M': cHange(a,b,c); break;
			case 'A': printf("%d\n",qUery(a,b,c)); break;
			default: break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

