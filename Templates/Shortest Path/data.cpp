#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime> 
#include<algorithm>
using namespace std;
int n,m,num[100050];
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	n=rand()%100000+2;
	m=rand()%(100000-n<1?1:100000-n)+n;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		num[i]=i;
	for(int limit=n-1;limit;limit--)
	{
		swap(num[rand()%limit+1],num[limit]);
		printf("%d %d %d\n",num[limit],num[rand()%(n-limit)+limit+1],rand());
	}
	for(int i=n;i<=m;i++)
		printf("%d %d %d\n",num[rand()%n+1],num[rand()%n+1],rand());
	fclose(stdout);
	return 0;
}

