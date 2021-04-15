#include <sys/utsname.h>
#include <iostream>
#include <cstdio>
#include <string>

int main()
{
	utsname names;
	if (uname(&names) != 0) {
		std::perror("cannot get unames");
	}

	std::cout << "Linux kernel version: " << names.release << std::endl;
	return 0;
}