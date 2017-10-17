#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int key[10050],dist[10050],L[10050],R[10050],p[10050],top;
void swap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
int merge(int A,int B)
{
	if(!A)
		return B;
	else if(!B)
		return A;
	if(key[B]<key[A])
		swap(A,B);
	R[A]=merge(R[A],B);
	if(dist[L[A]]<dist[R[A]])
		swap(L[A],R[A]);
	dist[A]=R[A]?0:dist[R[A]]+1;
	return A;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,a,b,ans=0;
	for(int i=0;i<10049;i++)p[i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&key[p[++p[0]]]);
		top=merge(top,p[p[0]]);
	}
	for(int i=1;i<n;i++)
	{
		a=key[top];
		p[p[0]--]=top;
		top=merge(L[top],R[top]);
		b=key[top];
		p[p[0]--]=top;
		top=merge(L[top],R[top]);
		ans+=a+b;
		key[p[++p[0]]]=a+b;
		L[p[p[0]]]=R[p[p[0]]]=0;
		top=merge(top,p[p[0]]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

