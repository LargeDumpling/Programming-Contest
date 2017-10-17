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
	int t=rand()%20+1,n,num[20050],u,v;
	printf("%d\n",t);
	for(int i=1;i<20050;i++)
		num[i]=i;
	while(t--)
	{
		n=rand()%20000+1;
		printf("%d\n",n);
		for(int i=n;i>1;i--)
		{
			u=rand()%(i-1)+1;
			v=i+rand()%(n-i+1);
			printf("%d %d\n",num[u],num[v]);
			swap(num[u],num[i-1]);
		}
	}
	fclose(stdout);
	return 0;
}

