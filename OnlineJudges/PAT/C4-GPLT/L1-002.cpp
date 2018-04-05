#include<cstdio>
using namespace std;
int num,lev;
char ch[2];
void print(int x)
{
	for(int i=1;i<=x;i++) putchar(' ');
	for(int i=1;i<=(lev-x)*2-1;i++) putchar(ch[0]);
	putchar('\n');
	if(x==lev-1) return;
	else print(x+1);
	for(int i=1;i<=x;i++) putchar(' ');
	for(int i=1;i<=(lev-x)*2-1;i++) putchar(ch[0]);
	putchar('\n');
	return;
}
int main()
{
	scanf("%d%s",&num,ch);
	lev=0;
	while(true)
	{
		if(lev==0&&1<=num)
			num-=1;
		else if(lev&&(lev*2+1)*2<=num)
			num-=(lev*2+1)*2;
		else break;
		lev++;
	}
	print(0);
	printf("%d",num);
	return 0;
}

