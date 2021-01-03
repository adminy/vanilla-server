#include <stdio.h>

void WriteVersion() {
	FILE* fp = fopen("ver.txt", "w");
	if (fp) {
		fprintf(fp, "emulated game server revision: %s\n", __SERVER_VERSION__);
		fclose(fp);
	}
}

