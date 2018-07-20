#include <bits/stdc++.h>
using namespace std;

#define MAX 100000005

char input[MAX];
char output[MAX];
int pi, po;  // pointer to the input and output arrays

bool check2() {
	return (po >= 2 && output[po - 1] == output[po - 2]);
}

bool check5() {
	return (po >= 5 &&
		output[po - 1] == output[po - 3] && output[po - 1] == output[po - 5] &&
		output[po - 2] == output[po - 4]);
}

int main() {
	int n;
	scanf("%s", input);
	n = strlen(input);
	//    printf("n=%d  input=%s\n",n, input);
	pi = po = 0;

	while (pi < n) {
		output[po] = input[pi];
		pi++;
		po++;
		if (check2()) {
			po -= 2;
		}
		else if (check5()) {
			po -= 5;
			pi -= 3;
			input[pi] = output[po + 1];
			input[pi + 1] = output[po + 2];
			input[pi + 2] = output[po + 3];
		}
	}
	//    for(int i=0; i<po; i++) {
	//        printf("%c", output[i]);
	//    }
	//    printf("\n");
	if (po == 0) printf("closed\n"); else printf("open\n");
}