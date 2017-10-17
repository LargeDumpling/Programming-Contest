#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[1050],T[100050];
unsigned long long H[100050][3],h[3],p[3];
int n,m;
int Hash()
{
	n=strlen(tex);
	m=strlen(T);
	p[0]=p[1]=p[2]=1;
	for(int i=1;i<=n;i++)
	{
		p[0]*=13;
		p[1]*=17;
		p[2]*=19;
	}
	for(int i=n-1;i>=0;i--)
	{
  		h[0]=h[0]*13+tex[i]-97;
		h[1]=h[1]*17+tex[i]-97;
		h[2]=h[2]*19+tex[i]-97;
	}
	for(int i=m-1;i>=0;i--)
	{
		H[i][0]=13*H[i+1][0]+T[i]-97;
		H[i][1]=17*H[i+1][1]+T[i]-97;
		H[i][2]=19*H[i+1][2]+T[i]-97;
	}
	for(int i=0;i<=m-n;i++)
		if(H[i][0]-H[i+n][0]*p[0]==h[0]
		&&H[i][1]-H[i+n][1]*p[1]==h[1]
		&&H[i][2]-H[i+n][2]*p[2]==h[2])
			return i;
	return -1;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("hash.out","w",stdout);
	scanf("%s%s",tex,T);
	printf("%d",Hash());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

