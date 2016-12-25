#include "helpStaff_t.h"

void employee_t::set() {
	person.set();
	edu = input_field("Education(0 - secondary, 1 - higher)", 0, 1);
}

char * employee_t::to_str() {
	char * str_per = person.to_str();
	int size = strlen(str_per) + 23;
	char * result = (char *)malloc(sizeof(char)*size);
	result[0] = '\0';
	strcat(result,str_per);
	strcat(result, "\t\t");
	char * education = (edu == 1) ? "higher aducation" : "secondary education";
	strcat(result, education);
	free(str_per);
	str_per = NULL;
	//free(education);
	education = NULL;
	return result;
}

void helpStaff_t::set() {
	printf("Enter data for employeers from help staff: \n");
	while (true) {
		employee_t employee;
		employee.set();
		employeers.push_back(employee);
		printf("Do you want to continue?(Y/N): ");
		char choice;
		while (true) {
			choice = getchar();
			if ((choice == 'Y') | (choice == 'y')) break;
			else if ((choice == 'N') | (choice == 'n')) break;
			else printf("Wrong answer!\n");
		}
		if ((choice == 'N') | (choice == 'n')) break;
	}
}

int helpStaff_t::to_bFile(FILE ** file) {
	if (!vec_to_bFile<employee_t>(file, &employeers)) return 0;
	return 1;
}

int helpStaff_t::from_bFile(FILE ** file) {
	if (vec_from_bFile<employee_t>(file, &employeers) == NULL) return 0;
	return 1;
}

char * helpStaff_t::to_str() {
	int size = 0;
	for each (employee_t var in employeers) {
		char * buff = var.to_str();
		size += strlen(buff);
		size += 2;
		free(buff);
	}
	char * result = (char*)malloc(sizeof(char)*(++size+200));
	result[0] = '\0';
	strcat(result, "\tName\t\tSurname\t\tAge\t\tAcademic title\n");
	strcat(result, "\t__________________________________________\n");
	for each (employee_t var in employeers) {
		char * buff = var.to_str();
		strcat(result,"\t");
		strcat(result, buff);
		strcat(result, "\n");
		free(buff);
		buff = NULL;
	}		
	return result;
}