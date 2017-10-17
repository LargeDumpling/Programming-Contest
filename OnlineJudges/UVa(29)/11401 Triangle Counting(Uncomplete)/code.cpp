#include<iostream>
using namespace std;
unsigned long long F[1000050],n;
int main()
{
	F[0]=F[1]=F[2]=F[3]=0;
	for(int i=4;i<=1000000;i++)
		F[i]=F[i-1]+( ((i-1)*(i-2))/2-(i-1)/2 )/2;
	while(true)
	{
		cin>>n;
		if(n<3)
			break;
		else
			cout<<F[n]<<"\n";
	}
	return 0; 
}

