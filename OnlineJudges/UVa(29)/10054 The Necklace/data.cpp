#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int limit,t,n;
	t=1;
	printf("%d\n",t);
	while(t--)
	{
		n=10;
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			printf("%d %d\n",rand()%n+1,rand()%n+1);
	}
	fclose(stdout);
	return 0;
}

