#include<stdio.h>
int fun(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
		if(!(x%i))
			return 0;
	return 1;
}
double avg()
{
	int cnt=0,sum=0,i;
	for(i=2;i<=5000;i++)
		if(fun(i))
		{
			cnt++;
			sum+=i;
		}
	return (double)sum/cnt;
}
int main()
{
	printf("%lf",avg());
	return 0;
}

