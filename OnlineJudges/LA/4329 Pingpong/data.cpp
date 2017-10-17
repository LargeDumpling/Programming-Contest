#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	int n=rand()%2000+1,a[2050],c;
	bool exist[2050];
	memset(exist,false,sizeof(exist));
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=n;i++)
		swap(a[rand()%n+1],a[rand()%n+1]);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	fclose(stdout);
	return 0;
}

