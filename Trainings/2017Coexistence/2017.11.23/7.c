#include<stdio.h>
#include<math.h>
int equation(double a,double b,double c,double *x1,double *x2)
{
	double delta=b*b-4.*a*c;
	if(delta<0) return 0;
	else if(delta==0)
	{
		*x1=-b/2.*a;
		return 1;
	}
	*x1=(-b-sqrt(delta))/2.*a;
	*x2=(-b+sqrt(delta))/2.*a;
	return 2;
}
int main()
{
	double a,b,c,x1,x2;
	int k;
	scanf("%lf%lf%lf",&a,&b,&c);
	k=equation(a,b,c,&x1,&x2);
	if(k==0) puts("No solution");
	else if(k==1) printf("%.2lf",x1);
	else if(k==2) printf("%.2lf %.2lf",x1,x2);
	return 0;
}

