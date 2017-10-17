#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int cas=rand()%2+1,Tn,Tm,n,m,super;
char T[1050][1050],tex[105][105];
void gplace(int x,int y)
{
	if(x<0||y<0)
		return;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			T[x+i][y+j]=tex[i][j];
	return;
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	printf("%d\n",cas);
	while(cas--)
	{
		Tn=rand()%1000+2;
		Tm=rand()%1000+2;
		n=rand()%min((Tn-1),100)+1;
		m=rand()%min((Tm-1),100)+1;
		printf("%d %d\n",Tn,Tm);
		for(int i=0;i<Tn;i++)
		{
			for(int j=0;j<Tm;j++)
				T[i][j]=rand()%26+97;
			T[i][Tm]='\0';
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				tex[i][j]=rand()%26+97;
			tex[i][m]='\0';
		}
		for(int i=1;i<=25;i++)
			gplace(rand()%(Tn-n),rand()%(Tm-m));
		for(int i=0;i<Tn;i++)
			printf("%s\n",T[i]);
		printf("%d %d\n",n,m);
		for(int i=0;i<n;i++)
			printf("%s\n",tex[i]);
	}
	fclose(stdout);
	return 0;
}

