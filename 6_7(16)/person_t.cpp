#include "person_t.h"



void person_t::setPerson() {
	input_field("Name", name);
	input_field("Surname", surname);
	input_field("Age",age,15,100);
}

void empty_err(char * field) {
	printf("Field '%s' can't be empty!\n", field);
}

void input_field(char * fName, char * field) {
	char * buff = new char[255];
	while (true) {
		printf("%s: ", fName);
		fgets(buff, 255, stdin);
		if (strlen(buff) - 1 == 0) empty_err(fName);
		else break;
	}
	buff[strlen(buff) - 1] = '\0';
	strcpy(field, buff);
	delete(buff);
}

void input_field(char * fName, int &field, int min, int max) {
	char * buff = new char[6];
	while (true) {
		printf("%s: ", fName);
		fgets(buff, 6, stdin);
		if (strlen(buff) - 1 == 0) empty_err(fName);
		else {
			buff[strlen(buff) - 1] = '\0';
			int iBuff = atoi(buff);
			if (iBuff >= min & iBuff <= max) {
				int field = iBuff;
				break;
			}
			else printf("Please, enter correct %s!\n", fName);
		}
	}

	delete(buff);
}