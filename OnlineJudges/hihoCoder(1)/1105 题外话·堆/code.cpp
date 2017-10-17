#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,L[100050],R[100050],dist[100050],data[100050],sz=0,top=0;
int merge(int A,int B)
{
	if(!A)
		return B;
	if(!B)
		return A;
	if(data[A]<data[B])
	{
		A^=B;
		B=B^A;
		A^=B;
	}
	R[A]=merge(R[A],B);
	if(dist[L[A]]<dist[R[A]])
	{
		L[A]^=R[A];
		R[A]=L[A]^R[A];
		L[A]^=R[A];
	}
	dist[A]=R[A]?dist[R[A]]+1:0;
	return A;
}
int main()
{
	char tex[5];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tex);
		if(tex[0]=='A')
		{
			scanf("%d",&data[++sz]);
			top=merge(top,sz);
		}
		else if(tex[0]=='T')
		{
			printf("%d\n",data[top]);
			top=merge(L[top],R[top]);
		}
	}
	return 0;
}

