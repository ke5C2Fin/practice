#include <err.h>
#include <stdio.h>
#include <stdlib.h>

static void nummax(void);

int num, max1, max2, max3;

int
main(void)
{
        FILE *fp;
        char buf[1024];

        if ((fp = fopen("./input", "r")) == NULL) err(1, "fopen");
        while (fgets(buf, sizeof(buf), fp) != NULL) {
                if (buf[0] == '\n') {
                        (void)nummax();
                        num = 0;
                        continue;
                }

                num += atoi(buf);
        }
        fclose(fp); fp = NULL;
        (void)nummax();
        (void)printf("%d\n", max1 + max2 + max3);

        return 0;
}

static void
nummax(void)
{
        if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
        } else if (num > max2) {
                max3 = max2;
                max2 = num;
        } else if (num > max3) {
                max3 = num;
        }
}
