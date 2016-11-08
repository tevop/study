#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuff;
	//dir is relative path, so you need call chdir func.
	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "can not open directory: %s\n", dir);
		return;
	} else {
		printf("can read this dir: %s\n", dir);
	}
	chdir(dir);
	printf("current working directory:%s\n", getcwd(NULL, NULL));
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
	printf("current working directory:%s\n", getcwd(NULL, NULL));
	closedir(dp);
}

int main() {
	printf("Directory scan of /home/tevop:\n");
	printdir("/home/tevop/mygit/study/linux", 0);
	printf("done.\n");
	
	exit(0);
}
