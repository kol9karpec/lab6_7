#include "university_t.h"

void empty_err(char * field);
void input_string_field(char * fName, char * field);

void university::setUniversity() {
	/*char buff[255] = "\0";
	while (true) {
		printf("Name: ");
		fgets(buff,sizeof(buff),stdin);
		if (strlen(buff)-1 == 0) empty_err("name");
		else break;
	}
	buff[strlen(buff) - 1] = '\0';
	strcpy(name, buff);*/

	input_string_field("Name", name);

	/*while (true) {
		printf("Historical name: ");
		fgets(buff, sizeof(buff), stdin);
		if (strlen(buff) - 1 == 0) empty_err("historical name");
		else break;
	}
	buff[strlen(buff) - 1] = '\0';
	strcpy(hName, buff);*/
	




}

void empty_err(char * field) {
	printf("Field '%s' can't be empty!\n", field);
}

void input_string_field(char * fName, char * field) {
	char * buff = new char[255];
	while (true) {
		printf("%s: ", fName);
		fgets(buff, sizeof(buff), stdin);
		if (strlen(buff) - 1 == 0) empty_err(fName);
		else break;
	}
	buff[strlen(buff) - 1] = '\0';
	strcpy(field, buff);
}