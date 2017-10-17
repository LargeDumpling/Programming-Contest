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
	int T=rand()%3+1,n;
	printf("%d\n",T);
	while(T--)
	{
		n=rand()%5+1;
		printf("%d\n",n);
		while(n--)
			printf("%d.0 %d.0 %d.0 %d.0\n",rand()%10,rand()%10,rand()%10,rand()%10);
	}
	fclose(stdout);
	return 0;
}

