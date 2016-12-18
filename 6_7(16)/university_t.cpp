#include "university_t.h"

void empty_err(char * field);
void input_string_field(char * fName, char * field);

void university::setUniversity() {
	input_string_field("Name", name);
	input_string_field("Historical name", hName);
	
	




}

void empty_err(char * field) {
	printf("Field '%s' can't be empty!\n", field);
}

void input_string_field(char * fName, char * field) {
	char * buff = new char[255];
	while (true) {
		printf("%s: ", fName);
		fgets(buff,255,stdin);
		if (strlen(buff)-1 == 0) empty_err(fName);
		else break;
	}
	buff[strlen(buff)-1] = '\0';
	strcpy(field, buff);
	delete(buff);
}