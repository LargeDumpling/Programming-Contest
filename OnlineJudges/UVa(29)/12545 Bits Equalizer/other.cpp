#include<cstring>
#include<cstdio>

using namespace std;

int C;
int one_zero, zero_one, q_one, q_zero;
int ans;
const int maxn = 100 + 5;
char s1[maxn], s2[maxn];

void init() {
    ans = 0;
    one_zero  = zero_one = q_one = q_zero = 0;
    scanf("%s",s1);
    scanf("%s",s2);
    for(int i = 0; i < strlen(s1); i ++) {
        if(s1[i] == '1' && s2[i] == '0') one_zero ++;
        else if (s1[i] == '0' && s2[i] == '1') zero_one ++;
        else if(s1[i] == '?' && s2[i] == '0') q_zero ++;
        else if(s1[i] == '?' && s2[i] == '1') q_one ++;
    }
}

int main() {
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    scanf("%d", &C);
    for(int kase = 0; kase < C; kase ++) {
        init();
        while(one_zero && zero_one) {       //swap 1-0 and 0-1
            one_zero --;
            zero_one --;
            ans ++;
        }
        while(one_zero && q_one) {          //swap 1-0 and ?-1
            one_zero --;
            q_one --;
            ans += 2;
        }
        if(one_zero)
            ans = -1;
        else
            ans += zero_one + q_one + q_zero;
        printf("Case %d: %d\n", kase+1, ans);
    }
    return 0;
}
