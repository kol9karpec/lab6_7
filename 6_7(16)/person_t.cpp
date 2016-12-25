#include "person_t.h"

void person_t::set() {
	input_field("Name", name);
	input_field("Surname", surname);
	age = input_field("Age",15,100);
}

char * person_t::to_str() {
	int size = strlen(name) + strlen(surname) + 20;
	char * result = (char*)malloc(sizeof(char)*size);
	strcat(result, name);
	strcat(result, "\t");
	strcat(result, surname);
	strcat(result, "\t");
	char age_buff[10];
	_itoa_s(age, age_buff,sizeof(age_buff), 10);
	strcat(result, age_buff);
	return result;
}

void empty_err(char * field) {
	printf("Field '%s' can't be empty!\n", field);
}

void input_field(char * fName, char * field) {
	char * buff = new char[255];
	while (true) {
		if(fName != "") printf("%s: ", fName);
		fgets(buff, 255, stdin);
		if (strlen(buff) - 1 == 0) empty_err(fName);
		else break;
	}
	buff[strlen(buff) - 1] = '\0';
	strcpy(field, buff);
	delete(buff);
}

int input_field(char * fName, int min, int max) {
	char * buff = new char[6];
	while (true) {
		if (fName != "") printf("%s: ", fName);
		fgets(buff, 6, stdin);
		if (strlen(buff) - 1 == 0) empty_err(fName);
		else {
			buff[strlen(buff) - 1] = '\0';
			int iBuff = atoi(buff);
			if ((iBuff >= min) & (iBuff <= max)) {
				delete(buff);
				return iBuff;
			}
			else printf("Please, enter correct data!\n");
		}
	}
}