#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1<<18,P=(479<<21)+1,G=3;
long long A[240050],B[240050],inv,W[2][240050];
int rev[240050],n;
long long Q_pow(long long a,int x)
{
	long long ans=1;
	while(x)
	{
		if(x&1)
			ans=(ans*a)%P;
		a=(a*a)%P;
		x>>=1;
	}
	return ans;
}
void FNT_pre(int &n)
{
	int tem=1;while((1<<tem)<n)tem++;n=1<<tem;
//	W[0][0]=W[0][n]=1;
//	W[0][1]=Q_pow(G,(P-1)/n);
	inv=Q_pow(n,P-2);
//	for(int i=2;i<n;i++)W[0][i]=(long long)(W[0][i-1]*W[0][1])%P;
//	for(int i=0;i<=n;i++)W[1][i]=W[0][n-i];
	for(int i=1;i<n;i++)rev[i]=(rev[i>>1]>>1)|(i&1)<<(tem-1);
	return;
}
void FNT(long long X[],int n,int inver)
{
	for(int i=0;i<n;i++)if(rev[i]>i)swap(X[i],X[rev[i]]);
	long long temp,cur=1,w;
	for(int i=2;i<=n;i<<=1)
	{
		cur=1;
		w=Q_pow(G,(P-1)/i);
		if(inver)w=Q_pow(w,i-1);
		for(int k=0;k<(i>>1);k++)
		{
			for(int j=0;j<n;j+=i)
			{
				temp=(long long)/*(W[inver][k*n/i]*/(cur*X[j+k+(i>>1)])%P;
				X[j+k+(i>>1)]=(long long)(X[j+k]+P-temp)%P;
				X[j+k]=(long long)(X[j+k]+temp)%P;
			}
			cur=(cur*w)%P;
		}
	}
	if(inver)
		for(int i=0;i<n;i++)
			X[i]=(long long)(X[i]*inv)%P;
}
int main()
{
	int m;
	char tex[60050];
	scanf("%d",&n);
	scanf("%s",tex);
	for(int i=0;i<n;i++)
		A[i]=tex[n-i-1]-'0';
	scanf("%s",tex);
	for(int i=0;i<n;i++)
		B[i]=tex[n-i-1]-'0';
	n+=n;
	FNT_pre(n);
	FNT(A,n,0);FNT(B,n,0);
	for(int i=0;i<n;i++)
		A[i]=(A[i]*B[i])%P;
	FNT(A,n,1);
	for(int i=0;i<n;i++)
		if(A[i]>=10)
		{
			A[i+1]+=A[i]/10;
			A[i]%=10;
			if(i==n-1)
				n++;
		}
	while(!A[n-1])n--;
	for(int i=n-1;i>=0;i--)
		printf("%d",A[i]);
	return 0;
}

