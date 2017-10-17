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
	printf("%d",rand()%100+1);
	fclose(stdout);
    return 0;
}

