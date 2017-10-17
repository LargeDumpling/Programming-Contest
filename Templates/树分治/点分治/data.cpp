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
	int t=rand()%10+1,n,k,num[10005];
	while(t--)
	{
		n=rand()%10000+1;
		k=rand();
		printf("%d %d\n",n,k);
		for(int i=1;i<=n;i++)
			num[i]=i;
		for(int i=n-1;i;i--)
		{
			swap(num[rand()%i+1],num[i]);
			printf("%d %d %d\n",num[i],num[rand()%(n-i)+i+1],rand()%k);
		}
	}
	printf("0 0");
	fclose(stdout);
	return 0;
}

