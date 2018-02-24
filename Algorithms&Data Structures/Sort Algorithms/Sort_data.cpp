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
	int n=rand()+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()+1);
	fclose(stdout);
	return 0;
}

