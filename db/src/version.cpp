#include <stdio.h>
#include <stdlib.h>

void WriteVersion()
{
	FILE* fp(fopen("VERSION.txt", "w"));

	if (NULL != fp)
	{
		fprintf(fp, "game perforce revision: %s\n", __SERVER_VERSION__);
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "cannot open VERSION.txt\n");
		exit(0);
	}
}

