#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char* dir, int depth) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuff;
	if ((dp = opendir(dir)) == NULL) {
		printf("cant open this dir: %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuff);
		if (S_ISDIR(statbuff.st_mode)) {
			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}
			printf("%*s%s/\n", depth, " ", entry->d_name);
			printdir(entry->d_name, depth + 4);
		} else {
			printf("%*s%s\n", depth, "", entry->d_name);
		}
	}
	chdir("..");
	closedir(dp);
}
int main(int argc, char* argv[]) {
	char *topdir = ".";
	if (argc >= 2) {
		printf("arg0 is: %s\n", argv[0]);
		topdir = argv[1];
	}
	printf("Directory scan of %s\n", topdir);
	printdir(topdir, 0);
	printf("done.\n");
	exit (0);
	
}
