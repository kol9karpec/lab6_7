#include "university_t.h"

void university::set() {
	input_field("Name", name);
	input_field("Historical name", hName);
	hStaff.set();
	tStaff.set();
}

void university::set(FILE ** file) {
	char * buff = (char *)malloc(sizeof(char)*50);
	fread(buff, sizeof(char) * 50, 1, *file);
	strcpy(name, buff);
	fread(buff, sizeof(char) * 50, 1, *file);
	strcpy(hName, buff);
	tStaff.from_bFile(file);
	hStaff.from_bFile(file);
}

char* university::to_str() {
	int size = strlen(name) + strlen(hName);
	char * buffTStaff = tStaff.to_str();
	char * buffHStaff = hStaff.to_str();
	size += (strlen(buffHStaff) + strlen(buffTStaff) + 1);
	char * result = (char*)malloc(sizeof(char)*(size+100));
	result[0] = '\0';
	strcat(result, "Name:\t");
	strcat(result, name);
	strcat(result, "\nHistorical name:\t");
	strcat(result, hName);
	strcat(result, "\nTeching staff\n");
	strcat(result, buffTStaff);
	strcat(result, "\Help staff\n");
	strcat(result, buffHStaff);
	free(buffHStaff);
	buffHStaff = NULL;
	free(buffTStaff);
	buffTStaff = NULL;
	return result;
}

void university::to_bFile(FILE ** file) {
	if (file == NULL) printf("File pointer cannot be NULL!");
	else {
		fwrite(name, sizeof(char) * 50, 1, *file);
		fwrite(hName, sizeof(char) * 50, 1, *file);
		tStaff.to_bFile(file);
		hStaff.to_bFile(file);
	}
}

void university::from_bFile(FILE ** file) {
	if (file == NULL) printf("File pointer cannot be NULL!");
	else {
		char * buff = (char *)malloc(sizeof(char)*50);
		fread(buff, sizeof(char) * 50, 1, *file);
		strcpy(name, buff);
		fread(buff, sizeof(char) * 50, 1, *file);
		strcpy(hName, buff);
		tStaff.from_bFile(file);
		hStaff.from_bFile(file);
	}
}

