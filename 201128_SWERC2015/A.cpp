#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 5005;

int down[maxn], up[maxn];
vector<int> succ[maxn], pred[maxn];
bool visited[maxn];

int dfs_down(int k) {
	if (visited[k]) return 0;

	visited[k] = true;

	int succ_num = succ[k].size();
	int down_num = 1;
	for (int i = 0; i < succ_num; ++i) {
		down_num += dfs_down(succ[k][i]);
	}
	return down_num;
}

int dfs_up(int k) {
	if (visited[k]) return 0;

	visited[k] = true;

	int pred_num = pred[k].size();
	int up_num = 1;
	for (int i = 0; i < pred_num; ++i) {
		up_num += dfs_up(pred[k][i]);
	}
	return up_num;
}

int main(void) {
	int A, B, E, P, x, y;

	scanf("%d%d%d%d", &A, &B, &E, &P);

	for (int i = 0; i < P; ++i) {
		scanf("%d%d", &x, &y);
		succ[x].push_back(y);
		pred[y].push_back(x);
	}

	for (int i = 0; i < E; ++i) {
		memset(visited, false, sizeof(visited));
		down[i] = dfs_down(i);
		memset(visited, false, sizeof(visited));
		up[i] = dfs_up(i);
	}


	int cert_a = 0, cert_b = 0, no_poss = 0;

	for (int i = 0; i < E; ++i) {
		if (E - down[i] < A)
			cert_a++;
		if (E - down[i] < B)
			cert_b++;
		if (up[i] > B)
			no_poss++;
	}
	
	printf("%d\n%d\n%d\n", cert_a, cert_b, no_poss);

	return 0;
}