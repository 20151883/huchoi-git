#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>


std::string autoindex()
{
	DIR *dir;
    struct dirent *ent;
	std::string path = "./";
    dir = opendir (path.c_str());
	char buf[1000];
	struct stat state;
	std::string temp;
	std::string ret;
	getcwd(buf,999);
    if (dir != NULL) 
	{
		while ((ent = readdir (dir)) != NULL)
		{
			temp += path + std::string(ent->d_name);
			stat(temp.c_str(), &state);
			if (S_ISREG(state.st_mode))
			{
				ret += "<a href=";
				ret += buf + std::string("/") + ent->d_name ;
				ret += std::string(">  ") + ent->d_name + "</a>\n";
			}
			else if (S_ISDIR(state.st_mode))
			{
				ret += "<a href=";
				if (ent->d_name == std::string("."))
					ret += buf + std::string("/");
				else if (ent->d_name == std::string(".."))
				{
					std::string test = buf;
					test.pop_back();
					std::string test2;
					test2.assign(test, 0, test.find_last_of("/") + 1);
					ret += test2;
				}
				else
					ret += buf + std::string("/") + ent->d_name + "/";
				ret += std::string(">  ") + ent->d_name + "/" + "</a>\n";
			}
			temp.clear();
		}
		std::cout << ret << std::endl;
		closedir (dir);
    } 
	else 
        perror ("");
	return std::string();
}

int main(void)
{
	autoindex();
	return 0;
}