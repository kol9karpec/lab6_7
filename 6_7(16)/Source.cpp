#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "university_t.h"
#include <string.h>
#include <vector>
#include "table.h"

void menu_help();
void menu_fopen(FILE ** f, char ** mode, char ** filename);
void menu_create(FILE ** f, char ** mode, char ** filename);
void menu_add(std::vector<university_t> * db);
void menu_save(std::vector<university_t> * db, FILE ** file, char ** mode);
void menu_read(std::vector<university_t> * db, FILE ** file, char ** mode);
void menu_out(std::vector<university_t> * db);
void menu_cout(std::vector<university_t> * db);
void menu_status(std::vector<university_t> db, FILE * f, char * mode, char * filename);
bool open_file(FILE ** f, char * mode, char ** filename);



int main(int argc, const char * argv[])
{
	printf(":::::::::Database of universities:::::::::\n");
	printf("type \"help\" to print available commands\n");
	printf("WAITING FOR COMMANDS\n");
	FILE * file = NULL;
	char * mode = (char*)malloc(sizeof(char)*10);
	char * filename = "";
	std::vector<university_t> db; //database;
	while(true) {
		char command[10];
		scanf("%s", command);
		getchar();
		if (!strncmp(command,"help",strlen("help"))) 
			menu_help();
		else if (!strncmp(command, "fopen", strlen("fopen")))
			menu_fopen(&file, &mode, &filename);
		else if (!strncmp(command, "create", strlen("create")))
			menu_create(&file, &mode, &filename);
		else if (!strncmp(command, "add", strlen("add")))
			menu_add(&db);
		else if (!strncmp(command, "save", strlen("save")))
			menu_save(&db, &file, &mode);
		else if (!strncmp(command, "read", strlen("read"))) 
			menu_read(&db, &file, &mode);
		else if (!strncmp(command, "out", strlen("out")))
			menu_out(&db);
		else if (!strncmp(command, "cout", strlen("cout")))
			menu_cout(&db);
		else if (!strncmp(command, "status", strlen("status")))
			menu_status(db,file,mode,filename);
		else if (!strncmp(command, "clean", strlen("clean"))) {
			system("cls");
		}
		else if (!strncmp(command, "exit", strlen("exit"))) {
			break;
		}
		else printf("Input correct command!\n");		
	}
	if(file != NULL) fclose(file);
	return 0;
}

void menu_help() {
	printf("fopen    -    (file open) open database file\n");
	printf("create   -    create database file\n");
	printf("add      -    create university\n");
	printf("save     -    export buffer to opened file\n");
	printf("read     -    read data from file\n");
	printf("out      -    print database on the screen\n");
	printf("cout     -    (custom out)print database with filtering and sorting\n");
	printf("status   -    print technical information\n");
	printf("exit     -    close the application\n");
}

bool open_file(FILE ** f, char * mode, char ** filename) {
	char file[256];
	printf("File name: ");
	scanf("%s", file);
	getchar();
	*f = fopen(file, mode);
	if (*f == NULL) {
		printf("File open error!\n");
		return false;
	}
	else {
		*filename = (char*)malloc(sizeof(char)*(strlen(file)+1));
		(*filename)[0] = '\0';
		strcat(*filename,file);
		return true;
	}
}

void menu_fopen(FILE ** file, char ** mode, char ** filename) {
	if (*file != NULL) {
		fclose(*file);
		*file = NULL;
		*mode = "";
		printf("Previous file closed.\n");
	}
	if (!open_file(file, "rb+", filename)) printf("Error reading file!\n");
	else {
		fseek(*file, 0, SEEK_END);
		if (ftell(*file) <= 0) {
			printf("File is empty. Enter not empty file!\n");
			*file = NULL;
			*mode = "";
		}
		else {
			printf("Successful opening file.\n");
			*mode = "read";
			rewind(*file);
		}
	}
	
}

void menu_create(FILE ** file, char ** mode, char ** filename) {
	if (*file != NULL) {
		fclose(*file);
		*file = NULL;
		*mode = "";
		printf("Previous file closed.\n");
	}
	if (!open_file(file, "wb+", filename)) printf("Error creating file!\n");
	else {
		printf("Successful opening file!\n");
		*mode = "write";
	}
}

void menu_add(std::vector<university_t> * db) {
	university_t newU;
	newU.set();
	db->push_back(newU);
	printf("Successful adding.\n");
}

void menu_save(std::vector<university_t> * db, FILE ** file, char ** mode) {
	if (*file == NULL) printf("Open file first!\n");
	else if (strncmp(*mode, "write", strlen("write"))) printf("Open file for writing first!\n");
	else {
		int buff = db->size();
		fwrite(&buff, sizeof(int), 1, *file);
		for (unsigned int i = 0; i < db->size(); i++)
			(*db)[i].to_bFile(file);
		printf("Successful saved.");
	}	
}

void menu_read(std::vector<university_t> * db, FILE ** file, char ** mode) {
	if (*file == NULL) printf("Open file first!\n");
	else if (strncmp(*mode, "read", strlen("read"))) printf("Open file for reading first!\n");
	else {
		int size;
		if (fread(&size, sizeof(int), 1, *file) != 1) printf("Error reading file!\n");
		else {
			for (int i = 0; i < size; i++) {
				university_t newU;
				newU.from_bFile(file);
				db->push_back(newU);
			}
			rewind(*file);
			printf("Successful reading.\n");
		}		
	}	
}

void menu_out(std::vector<university_t> * db) {
	if (db->size() == 0) printf("Nothing to output!\n");
	else 
		for (unsigned int i = 0; i < db->size(); i++) {
			char * buff = (*db)[i].to_str();
			printf("%s", buff);
			free(buff);
			buff = NULL;
		}
}

void menu_cout(std::vector<university_t> * db) {
	char * input = (char*)malloc(sizeof(char) * 30);
	field fields[8];
	
	printf("List of fields: \n");
	for (int i = 0; i < 8; i++) {
		printf("\t%i) %s\n",i+1,sFields[i]);
	}
	printf("Enter fields in order you want to output them: \n");
	int counter = 0;
	while (true) {
		int buff;
		buff = input_field("field", 1, 8);
		fields[counter++] = (field)(--buff);
		if (!question("Do you want to continue?")) break;
	}

	int table_size;	
	char *** table = init_table(counter, fields, *db, &table_size);

	if (question("Do you want to sort fields?")) {
		printf("Available fields: \n");
		for (int i = 0; i < counter; i++) {
			printf("\t%i) %s\n", i + 1, sFields[fields[i]]);
		}
		printf("Enter sort queue: ");
		int * order = (int*)malloc(sizeof(int)*counter);
		for (int i = 0; i < counter; i++) order[i] = -1;
		bool * sort_type = (bool*)malloc(sizeof(bool)*counter);
		int index = 0;
		while (true) {
			order[index] = input_field("Field #",1,counter) - 1;
			sort_type[index++] = question("In increasing order?");
			if (!question("Do you want to continue?")) break;
		}
		sort_table(table, table_size, counter, order, sort_type);
	}


	char * res = table_to_str(table, table_size, counter);
	printf("\n%s", res);
	free(res);
}

void menu_status(std::vector<university_t> db, 
					FILE * f, 
					char * mode, 
					char * filename) {
	printf("\n\nBuffer:\tElements - %i\n",db.size());
	printf("File:\t");
	if (f == NULL) printf("<not opened>\n\n\n");
	else printf("Name - \"%s\"\tMode - %s\n\n\n",filename,mode);
}