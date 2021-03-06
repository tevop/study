#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void printBlank(int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf(" ");
	}
}

void printDir(char *dirName, int depth) {
	//printf("in printDIr: %s\n", dirName);
	DIR *dir;
	struct dirent *dirDes;
	if ((dir = opendir(dirName)) == NULL) {
		printf("can not read dir: %s\n", dirName);
		return;
	}
	chdir(dirName);
	//printf("current working directory:%s\n", getcwd(NULL, NULL));
	while((dirDes = readdir(dir)) != NULL) {
		struct stat buff;
		lstat(dirDes->d_name, &buff);
		printBlank(depth);
		//dir
		if(S_ISDIR(buff.st_mode)) {
			if (strcmp(".", dirDes->d_name) == 0 ||
					strcmp("..", dirDes->d_name) == 0) {
				continue;
			}
			printf("%s\n", dirDes->d_name);
			printDir(dirDes->d_name, depth + 4);
		} else {
			printBlank(depth);
			printf("%s\n", dirDes->d_name);
		}
	}
	chdir("..");
	closedir(dir);
}

int main(int argCount, char* args[]) {
	if (argCount >= 2) {
	    int i;
		for (i = 1; i < argCount; i++) {
			printDir(args[i], 0);
		}
	}
	exit (0);
}
