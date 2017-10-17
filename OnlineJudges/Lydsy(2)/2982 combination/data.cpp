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
	int T=rand()%2+1;
	printf("%d\n",T);
	while(T--)
		printf("%d %d\n",rand(),rand());
	fclose(stdout);
	return 0;
}

