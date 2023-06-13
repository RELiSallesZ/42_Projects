#include <unistd.h>

int main (int argc, const char *argv[])
{	int i = 1;
	const char *word = argv[i];
	size_t len = 5;
	write(1, word, len);
	write(1, " ", len);
	return 0;
}

