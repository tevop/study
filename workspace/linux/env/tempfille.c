#include <stdio.h>
#include <stdlib.h>

int main() {
	char tmpname[L_tmpnam];
	char *filename;
	FILE *tmpfp;
	
	//filename = tmpnam(tmpname);
	//tmpfp = tmpfile();
	tmpfp = (FILE *)mkstemp(tmpname);
	
	printf("Temporary file name is: %s\n", filename);
	
	if(tmpfp) {
		printf("Opened a temporary file OK\n");
	} else {
		perror("tmpfile");
	}
	exit (0);
}
