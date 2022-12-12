#include <err.h>
#include <stdio.h>
#include <stdlib.h>

static void nummax(int);

enum { N = 3 };
int max[N];

int
main(void)
{
	FILE *fp;
	char buf[1024];
	int i;
	int sum = 0;
	int num = 0;

	if ((fp = fopen("./input", "r")) == NULL) err(1, "fopen");
	while (fgets(buf, sizeof(buf), fp) != NULL) {
		if (buf[0] == '\n') {
			nummax(num);
			num = 0;
		} else {
			num += atoi(buf);
		}
	}
	fclose(fp);
	fp = NULL;

	nummax(num);
	for (i = 0; i < N; i++) {
		sum += max[i];
	}
	(void)printf("%d\n", sum);

	return 0;
}

static void
nummax(int n)
{
	int i;

	if (n < max[0]) return;

	max[0] = n;
	for (i = 0; i < (N-1); i++) {
		if (max[i] > max[i+1]) {
			n = max[i];
			max[i] = max[i+1];
			max[i+1] = n;
		}
	}
}
