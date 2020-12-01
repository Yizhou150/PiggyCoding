#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int T, N;
	long long x, min1, min2, cmb, ans;

	vector<long long> canvas;

	scanf("%d", &T);
	for (int case_i = 0; case_i < T; ++case_i) {
		scanf("%d", &N);

		canvas.clear();
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &x);
			canvas.push_back(x);
		}

		make_heap(canvas.begin(), canvas.end(), greater<long long>());

		ans = 0;
		for (int i = 0; i < N - 1; ++i) {
			min1 = canvas.front();
			pop_heap(canvas.begin(), canvas.end(), greater<long long>());
			canvas.pop_back();

			min2 = canvas.front();
			pop_heap(canvas.begin(), canvas.end(), greater<long long>());
			canvas.pop_back();

			cmb = min1 + min2;
			ans += cmb;
			canvas.push_back(cmb);
			push_heap(canvas.begin(), canvas.end(), greater<long long>());
		}

		printf("%lld\n", ans);
	}

	return 0;
}