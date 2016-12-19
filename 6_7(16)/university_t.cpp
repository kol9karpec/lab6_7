#include "university_t.h"

void empty_err(char * field);
void input_field(char * fName, char * field);
void input_field(char * fName, int &field, int minValue, int maxValue);

void university::setUniversity() {
	input_field("Name", name);
	input_field("Historical name", hName);
	
	




}

void empty_err(char * field) {
	printf("Field '%s' can't be empty!\n", field);
}

void input_field(char * fName, char * field) {
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
			else printf("Please, enter correct %s!\n",fName);
		}
	}

	delete(buff);
}