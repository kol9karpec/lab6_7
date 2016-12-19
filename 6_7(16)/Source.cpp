#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "university_t.h"
#include <string.h>

void help_out(int choice);
bool open_file(FILE * f);

int main(int argc, const char * argv[])
{
	printf(":::::::::Database of universities:::::::::\n");
	while(true) {
		/*FILE * file;
		while (!open_file(file));
		printf("Succesfull opening!\n");*/
		//fseek(file, 0, SEEK_END);
		university_t u;
		u.setUniversity();

		printf("Name: %s\nHName: %s\n",u.name,u.hName);



		break;
	}
	return 0;
}

void help_out(int choice) {

}
bool open_file(FILE * f) {
	char file[256];
	printf("Please, input the name of file with database: ");
	scanf("%s", file);
	f = fopen("1.bin", "r");
	if (f == NULL) {
		printf("File open error!\n");
		return false;
	}
	else return true;
}