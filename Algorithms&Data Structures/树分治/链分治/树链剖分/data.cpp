#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n,m,cn,f[100050],limit;
int find(int x)
{
	while(f[x]!=f[f[x]])
		f[x]=f[f[x]];
	return f[x];
}
void JP(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
		f[b]=a;
	return;
}
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	n=rand()%10+1;m=rand()%10+1;cn=rand()%4+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%cn+1);
	printf("\n"); 
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0,a,b;i<n-1;i++)
	{
		do
		{
			a=rand()%n+1;
			b=rand()%n+1;
		}while(find(a)==find(b));
		JP(a,b);
		printf("%d %d\n",a,b);
	}
	for(int i=1;i<=m;i++)
	{
		if(rand()&1)
			printf("C %d %d %d\n",rand()%n+1,rand()%n+1,rand()%cn+1);
		else
			printf("Q %d %d\n",rand()%n+1,rand()%n+1);
	}
	fclose(stdout);
	return 0;
}

