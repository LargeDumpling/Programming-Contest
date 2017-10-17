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
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n=rand()%1000+1,m=rand()%2000+n;
	int num[n+1];
	for(int i=1;i<=n;i++)num[i]=i;
	for(int i=n-1;i;i--)
	{
		swap(num[rand()%i+1],num[i]);
		swap(num[rand()%(n-i)+i+1],num[i+1]);
		printf("%d %d %d\n",num[i],num[i+1],rand());
	}
	for(int i=n;i<=m;i++)
		printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand());
	fclose(stdout);
	return 0;
}

