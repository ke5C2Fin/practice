/* err */
#include <err.h>
/* open */
#include <fcntl.h>
/* read, close, write */
#include <unistd.h>

static void rwf(const char *p);

char buffer[4096];
int read_bytes;

static void
rwf(const char *p)
{
	int fd;

	if ((fd = open(p, O_RDONLY)) == -1)
		err(1, "rwf open");
	if ((read_bytes = read(fd, buffer, sizeof(buffer))) == -1)
		err(1, "rwf read");
	if ((close(fd)) == -1)
		err(1, "rwf close");
	/* cast int read_bytes to unsigned long for write size_t count */
	if ((write(1, buffer, (unsigned long) read_bytes - 1)) == -1)
		err(1, "rwf write");
}

int
main(void)
{
	rwf("./a");
	rwf("./b");
	if ((write(1, buffer + (read_bytes - 1), 1)) == -1)
		err(1, "rb write");
	return 0;
}
