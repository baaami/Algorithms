#include<stdio.h>

int Min(int a, int b) { return a < b ? a : b; }

int main() {
	int i, j, n, k, a[101], d[10001];
	scanf("%d%d", &n, &k);

	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (i = 1; i <= k; i++) d[i] = 10000000; d[0] = 0;

	for (i = 1; i <= n; i++)
		for (j = a[i]; j <= k; j++)
			d[j] = Min(d[j], d[j - a[i]] + 1);

	if (d[k] == 10000000) d[k] = -1;
	printf("%d", d[k]);

	return 0;
}