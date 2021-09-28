#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <string>

void getFileModifiedTime(const std::string &src) {
    struct stat attr;
    stat(src.c_str(), &attr);
    printf("Last modified time: %s", ctime(&attr.st_mtime));
}

int main()
{
	getFileModifiedTime(std::string("./index.html"));
}