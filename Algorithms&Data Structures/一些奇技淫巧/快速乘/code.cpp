#include<iostream>
#include<cmath>
#define mod 123456789
using namespace std;
inline int mul_mod0(int a,int b)
{
	int ret;
	__asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mod));
	return ret;
}
inline long long mul_mod1(long long a,long long b)
{
	long long d=(long long)floor(a*(double)b/mod+0.5);
	long long ans=a*b-d*mod;
	if(ans<0) ans+=mod;
	return ans;
}
inline long long mul_mod2(long long a,long long b)
{
	//https://blog.csdn.net/xuxiayang/article/details/81623511
	a%=mod; b%=mod;
	long double c=a*b/mod;
	long long ans=a*b-c*mod;
	if(ans<0) ans+=mod;
	if(mod<=ans) ans-=mod;
	return ans;
}
int main()
{
	cout<<mul_mod0(654321,123789)<<endl;
	cout<<mul_mod1(654321LL,123789LL)<<endl;
	cout<<mul_mod2(654321LL,123789LL)<<endl;
	/*float a=0.12345678901234567890;
	double b=0.12345678901234567890;
	long double c=0.12345678901234567890;
	cout.setf(ios::showpoint);
	cout.precision(30);
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;*/
}

