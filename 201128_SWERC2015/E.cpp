#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 2005;
int a[maxn];
long long f[maxn][maxn];

const int large = 2147483647;

int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n + 1; ++i)
		scanf("%d", &a[i]);

	// f[i][j] i^{th} bottom at j
	// f[i][j] = f[i-1][j] (i < i-1) + f[i-1][...] (if a[i-1] == j)
	memset(f, 0, sizeof(f));
	f[1][a[0]] = 1;
	for (int i = 2; i <= n; ++i) {
		// the tail of the (i-1)^{th}
		for (int j = 1; j <= n + 1; j++) {
			int l = min(j, a[i-1]);
			int r = max(j, a[i-1]);
			// for i^th, tail can be l or r
			if (a[i] > l)
				f[i][l] = (f[i][l] + f[i-1][j]) % large;
			if (a[i] < r)
				f[i][r] = (f[i][r] + f[i-1][j]) % large;
		}
	}

	long long sum = 0;
	for (int i = 1; i <= n + 1; i++)
		sum = (sum + f[n][i]) % large;

	printf("%lld\n", sum);

	return 0;
}