#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	c-=a;
	d-=b;
	if(d<0)
	{
		d+=60;
		c--;
	}
	printf("%d %d",c,d);
	return 0;
}

