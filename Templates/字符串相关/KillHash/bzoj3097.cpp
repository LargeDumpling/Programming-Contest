#include <cstdio>

int N, L;
char s[50005];

int main() {
	freopen("code.in", "w", stdout);
	s[1] = 'a'; N = 1;
	for (int i = 1; i < 14; i++) {
		for (int j = 1; j <= N; j++)
			s[N + j] = 'a' + 'b' - s[j];
		N <<= 1;
	}
	for (int i = 1; i <= 64; i++)
		s[N + i] = 'a';
	N += 64;

	for (int i = 1; i <= 64; i++)
		putchar('a');	
	puts(s + 1);
	for (int i = 1; i <= 64; i++)
		putchar('a');
	for (int i = 1; i <= N - 64; i++)
		putchar('a' + 'b' - s[i]);
	for (int i = 1; i <= 64; i++)
		putchar('a');
	return 0;
}

/*
typedef unsigned long long u64;

const int MaxN = 100000;

inline int hash_handle(const char *s, const int &n, const int &l, const int &base)
{
 u64 hash_pow_l = 1;
 for (int i = 1; i <= l; i++)
  hash_pow_l *= base;

 int li_n = 0;
 static u64 li[MaxN];

 u64 val = 0;
 for (int i = 0; i < l; i++)
  val = val * base + s[i] - 'a';
 li[li_n++] = val;
 for (int i = l; i < n; i++)
 {
  val = val * base + s[i] - 'a';
  val -= (s[i - l] - 'a') * hash_pow_l;
  li[li_n++] = val;
 }

 sort(li, li + li_n);
 li_n = unique(li, li + li_n) - li;
 return li_n;
}
*/
