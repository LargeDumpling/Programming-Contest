#include<stdio.h>
#include<string.h>
char str[100];
int len;
int main()
{
	int x;
	gets(str);
	len=strlen(str);
	scanf("%d",&x);

	// 1
	/*for(x--;x<len;x++)
		str[x]=str[x+1];*/
	// 2
	strcpy(str+x-1,str+x);

	puts(str);
	return 0;
}

