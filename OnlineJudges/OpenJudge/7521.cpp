#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	char c;
	int in;
	float a;
	double b;
	scanf("%c%d%f%lf",&c,&in,&a,&b);
	printf("%c %d %.6f %.6lf",c,in,a,b);
    return 0;
}

