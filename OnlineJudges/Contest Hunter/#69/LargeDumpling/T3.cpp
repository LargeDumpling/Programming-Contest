#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
char A[2050],B[2050];
int F[2050][2050],Al,Bl,ans=0;
bool can[2050][2050];
unsigned long long Ha[2050][3],Hb[2050][3],p[2050][3];
unsigned long long calc(unsigned long long X[2050][3],int L,int len,int k){return X[L][k]-X[L+len][k]*p[len][k];}
int main()
{
	p[0][0]=p[0][1]=p[0][2]=1;
	for(int i=1;i<2050;i++)
	{
		p[i][0]=p[i-1][0]*13;
		p[i][1]=p[i-1][1]*17;
		p[i][2]=p[i-1][2]*19;
	}
	scanf("%s%s",A,B);
	Al=strlen(A);
	Bl=strlen(B);
	for(int i=Al-1;i>=0;i--)
	{
		Ha[i][0]=13*Ha[i+1][0]+A[i]-'A';
		Ha[i][1]=17*Ha[i+1][1]+A[i]-'A';
		Ha[i][2]=19*Ha[i+1][2]+A[i]-'A';
	}
	for(int i=Bl-1;i>=0;i--)
	{
		Hb[i][0]=13*Hb[i+1][0]+B[i]-'A';
		Hb[i][1]=17*Hb[i+1][1]+B[i]-'A';
		Hb[i][2]=19*Hb[i+1][2]+B[i]-'A';
	}
	for(int i=0;i<Al;i++)
		for(int j=0;j<Bl;j++)
		{
			F[i][j]==max(F[i][j],max(F[i-1][j-1],max(F[i-1][j],F[i][j-1])));
			if(calc(Ha,i,3,0)==calc(Hb,j,3,0)&&calc(Ha,i,3,1)==calc(Hb,j,3,1)&&calc(Ha,i,3,2)==calc(Hb,j,3,2))
			 	can[i][j]=true;
			if(A[i]==B[j]&&can[i][j])
			{
				F[i][j]=max(F[i][j],F[i-1][j-1]+1);
				can[i+1][j+1]=true;
			}
//			else if(A[i]==B[j-1])
//				F[i][j]=max(F[i][j],F[i][j-1]);
//			else if(A[i-1]==B[j])
//				F[i][j]=max(F[i][j],F[i-1][j]);
			ans=max(ans,F[i][j]);
		}
	printf("%d",ans);
    return 0;
}

