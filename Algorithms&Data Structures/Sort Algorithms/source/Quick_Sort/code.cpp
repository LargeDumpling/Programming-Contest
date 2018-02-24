#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[1000050];
template<typename Ty>
void Quick_Sort(Ty *l,Ty *r)
{
	if(l>=r-1)
		return;
	Ty *p=l,*i=l,*j=l;
	for(j=l+1;j<r;j++)
		if(*j<*p)
		{
			i++;
			if(i!=j)
				swap(*i,*j);
		}
	swap(*p,*i);
	Quick_Sort(l,i);
	Quick_Sort(i+1,r);
	return;
}
template<typename Ty>
void Quick_Sort(Ty *l,Ty *r,bool (*f)(Ty,Ty))
{
	if(l>=r-1)
		return;
	Ty *p=l,*i=l,*j=l;
	for(j=l+1;j<r;j++)
		if(f(*j,*p))
		{
			i++;
			if(i!=j)
				swap(*i,*j);
		}
	swap(*p,*i);
	Quick_Sort(l,i,f);
	Quick_Sort(i+1,r,f);
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
	Quick_Sort(num+1,num+n+1,cnmp);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

