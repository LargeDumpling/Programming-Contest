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
	freopen("T1.in","w",stdout);
	srand(time(NULL));
	int n;
	printf("%d\n",n=rand()+1);
	for(int i=1;i<=n;i++)
		printf("%d ",rand());
	fclose(stdout);
    return 0;
}

