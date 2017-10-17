#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=100000;
char tex1[D],tex2[D];
int main(int argc,char *argv[])
{
	fread(tex1,1,D,fopen(argv[0],"r"));
	fread(tex2,1,D,fopen(argv[1],"r"));
}

