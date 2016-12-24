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
	char * result = "";
	strcat(result, "Name:\t");
	strcat(result, name);
	strcat(result, "\nHistorical name:\t");
	strcat(result, hName);
	strcat(result, "\nTeching staff\n");
	strcat(result, tStaff.to_str());
	strcat(result, "\Help staff\n");
	strcat(result, hStaff.to_str());
	return NULL;
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

