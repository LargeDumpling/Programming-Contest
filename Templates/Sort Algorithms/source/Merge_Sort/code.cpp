#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[1000050];
template<typename Ty>
void Merge_Sort(Ty *l,Ty *r)
{
	if(l>=r-1)
		return;
	static Ty T[1000050];
	static int top=0;
	int *mid=l+(r-l)/2,*i,*j;
	Merge_Sort(l,mid);
	Merge_Sort(mid,r);
	for(i=l,j=mid,top=0;i<mid&&j<r;)
		if(*i<*j)
			T[++top]=*(i++);
		else
			T[++top]=*(j++);
	while(i<mid)T[++top]=*(i++);
	while(j<r)T[++top]=*(j++);
	for(i=l;i<r;i++)
		*i=T[i-l+1];
	return;
}
template<typename Ty>
void Merge_Sort(Ty *l,Ty *r,bool (*f)(Ty A,Ty B))
{
	if(l>=r-1)
		return;
	static Ty T[1000050];
	static int top=0;
	int *mid=l+(r-l)/2,*i,*j;
	Merge_Sort(l,mid,*f);
	Merge_Sort(mid,r,*f);
	for(i=l,j=mid,top=0;i<mid&&j<r;)
		if(f(*i,*j))
			T[++top]=*(i++);
		else
			T[++top]=*(j++);
	while(i<mid)T[++top]=*(i++);
	while(j<r)T[++top]=*(j++);
	for(i=l;i<r;i++)
		*i=T[i-l+1];
	return;
}
bool cnmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	Merge_Sort(num+1,num+n+1,cnmp);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

