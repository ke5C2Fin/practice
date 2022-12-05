#include <err.h>
#include <stdio.h>
#include <stdlib.h>

static void nummax(void);

enum { N = 3 };
int num, max[N];

int
main(void)
{
	FILE *fp;
	char buf[1024];
	int i;
	int sum = 0;

	if ((fp = fopen("./input", "r")) == NULL) err(1, "fopen");
	while (fgets(buf, sizeof(buf), fp) != NULL) {
		if (buf[0] == '\n') {
			(void)nummax();
			num = 0;
		} else {
			num += atoi(buf);
		}
	}
	fclose(fp);
	fp = NULL;

	(void)nummax();
	for (i = 0; i < N; i++) {
		sum += max[i];
	}
	(void)printf("%d\n", sum);

	return 0;
}

static void
nummax(void)
{
	int i, tmp;

	if (num < max[0]) return;

	max[0] = num;
	for (i = 0; i < (N-1); i++) {
		if (max[i] > max[i+1]) {
			tmp = max[i];
			max[i] = max[i+1];
			max[i+1] = tmp;
		}
	}
}
