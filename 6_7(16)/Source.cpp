#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "university_t.h"
#include <string.h>
#include <vector>

void help_out();
bool open_file(FILE ** f, char * mode);

int main(int argc, const char * argv[])
{
	printf(":::::::::Database of universities:::::::::\n");
	FILE * file = NULL;
	std::vector<university_t> db; //database;
	while(true) {
		char command[10];
		scanf("%s", command);
		if (!strncmp(command,"help",strlen(command))) {
			printf("fopen    -    open database\n");
			printf("create   -    create database\n");
			printf("fill     -    create university\n");
			printf("save     -    export all created to opened file\n");
			printf("read     -    read data from file\n");
			printf("out      -    print database on the screen\n");
			printf("exit     -    quit the application\n");
		}
		else if (!strncmp(command, "fopen", strlen(command))) {
			if (!open_file(&file, "rb+")) continue;
			else {
				fseek(file, 0, SEEK_END);
				if (ftell(file) <= 0) {
					printf("File is empty!\n");
				}
				else rewind(file);
			}
		}
		else if (!strncmp(command, "create", strlen(command))) {
			if (!open_file(&file, "wb+")) continue;
			else {
				fseek(file, 0, SEEK_END);
				if (ftell(file) <= 0) {
					printf("File is empty!\n");
				}
				else rewind(file);
			}

		}
		else if (!strncmp(command, "fill", strlen(command))) {
			university_t newU;
			newU.set();
			db.push_back(newU);
		}
		else if (!strncmp(command, "save", strlen(command))) {
			int buff = db.size();
			fwrite(&buff, sizeof(int), 1, file);
			for (unsigned int i = 0; i < db.size(); i++) 
				db[i].to_bFile(&file);
		}
		else if (!strncmp(command, "read", strlen(command))) {
			int size;
			fread(&size, sizeof(int), 1, file);
			for (int i = 0; i < size; i++) {
				university_t newU;
				newU.from_bFile(&file);
				db.push_back(newU);
			}
			rewind(file);
		}
		else if (!strncmp(command, "out", strlen(command))) {
			for (unsigned int i = 0; i < db.size(); i++) {
				char * buff = db[i].to_str();
				printf("%s", buff);
				free(buff);
				buff = NULL;
			}
		}
		else if (!strncmp(command, "exit", strlen(command))) {
			break;
		}
		else printf("Input correct command!\n");		
	}
	if(file != NULL) fclose(file);
	return 0;
}

void help_out() {

}
bool open_file(FILE ** f, char * mode) {
	char file[256];
	printf("File name: ");
	scanf("%s", file);
	*f = fopen(file, mode);
	if (*f == NULL) {
		printf("File open error!\n");
		return false;
	}
	else return true;
}