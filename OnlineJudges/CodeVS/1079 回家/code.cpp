#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int map[53][53],P;
int idx(char ch)
{
	if('A'<=ch&&ch<='Z')
		return ch-'A'+1;
	else if('a'<=ch&&ch<='z')
		return ch-'a'+27;
	return 0;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char A[2],B[2];
	int x,a,b;
	scanf("%d",&P);
	for(int i=1;i<=52;i++)
		for(int j=1;j<=52;j++)
			if(i==j)
				map[i][i]=0;
			else
				map[i][j]=1000001;
	for(int i=1;i<=P;i++)
	{
		scanf("%s%s%d",A,B,&x);
		a=idx(A[0]);
		b=idx(B[0]);
		map[a][b]=map[b][a]=min(map[a][b],x);
	}
	for(int k=1;k<=52;k++)
		for(int i=1;i<=52;i++)
			for(int j=1;j<=52;j++)
				if(map[i][k]+map[k][j]<map[i][j])
					map[i][j]=map[j][i]=map[i][k]+map[k][j];
	x=1;
	for(int i=2;i<26;i++)
		if(map[i][26]<map[x][26])
			x=i;
	printf("%c %d",x+'A'-1,min(map[x][26],map[26][x]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

