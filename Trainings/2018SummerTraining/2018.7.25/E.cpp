#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int cnt=0;
int pr = 47;
int main()
{
	int N = 2000;
	//freopen("E.txt","w",stdout);
	printf("%d\n", N);
	int sumx = 0;
	for (int i = 0; i < pr; i++)
	{
		if (sumx == N) break;
		for (int j = 0; j < pr; j++)
		{
			if (sumx == N) break;
			int sumy = 0;
			for (int k = 0; k < pr; k++)
			{
				if (sumy == N) break;
				for (int l = 0; l < pr; l++)
				{
					if (sumy == N) break;
					if ((j + k * i) % pr == l)
					{
						putchar('1');
						cnt++;
					}
					else putchar('0');
					sumy++;
				}
			}
			sumx++;
			putchar('\n');
		}
	}
	//fprintf(stderr,"%d\n",cnt);
	return 0;
}
