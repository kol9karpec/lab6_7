#include "teachingStaff_t.h"

void teachingStaff::set() {
	printf("Enter data for professors: \n");
	while (true) {
		professor_t professor;
		professor.set();
		professors.push_back(professor);
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

	printf("Enter data for docents: \n");
	while (true) {
		docent_t docent;
		docent.set();
		docents.push_back(docent);
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

	printf("Enter data for senior lecturers: \n");
	while (true) {
		seniorLecturer sLecturer;
		sLecturer.set();
		sLecturers.push_back(sLecturer);
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

	printf("Enter data for assistants: \n");
	while (true) {
		assistant_t assistant;
		assistant.set();
		assistants.push_back(assistant);
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

int teachingStaff::to_bFile(FILE ** file) {
	if (!vec_to_bFile<professor_t>(file, &professors)) return 0;
	if (!vec_to_bFile<docent_t>(file, &docents)) return 0;
	if (!vec_to_bFile<assistant_t>(file, &assistants)) return 0;
	if (!vec_to_bFile<seniorLecturer_t>(file, &sLecturers)) return 0;
	return 1;
}

int teachingStaff::from_bFile(FILE ** file) {
	if (vec_from_bFile<professor_t>(file, &professors) == NULL) return 0;
	if (vec_from_bFile<docent_t>(file, &docents) == NULL) return 0;
	if (vec_from_bFile<assistant_t>(file, &assistants) == NULL) return 0;
	if (vec_from_bFile<seniorLecturer_t>(file, &sLecturers) == NULL) return 0;
	return 1;
}

char * teachingStaff::to_str() {
	int size = 0;
	for each (professor var in professors) {
		char * buff = var.to_str();
		size += (strlen(buff) + 4);
		free(buff);
		buff = NULL;
	}
	for each (docent var in docents) {
		char * buff = var.to_str();
		size += (strlen(buff) + 4);
		free(buff);
		buff = NULL;
	}
	for each (seniorLecturer var in sLecturers) {
		char * buff = var.to_str();
		size += (strlen(buff) + 4);
		free(buff);
		buff = NULL;
	}
	for each (assistant var in assistants) {
		char * buff = var.to_str();
		size += (strlen(buff) + 4);
		free(buff);
		buff = NULL;
	}

	size += 100;
	char * result = (char*)malloc(sizeof(char)*(size+600));
	result[0] = '\0';
	strcat(result, "\tProfessors:\n");
	strcat(result, "\t\tName\t\tSurname\t\tAge\t\tAcademic title\n");
	strcat(result, "\t\t__________________________________________________________________\n");
	for each (professor var in professors) {
		char * buff = var.to_str();
		strcat(result,"\t\t");
		strcat(result, buff);
		strcat(result, "\n");
		free(buff);
		buff = NULL;
	}
	strcat(result, "\tDocents:\n");
	strcat(result, "\t\tName\t\tSurname\t\tAge\t\tAcademic title\n");
	strcat(result, "\t\t__________________________________________________________________\n");
	for each (docent var in docents) {
		char * buff = var.to_str();
		strcat(result, "\t\t");
		strcat(result, buff);
		strcat(result, "\n");
		free(buff);
		buff = NULL;
	}
	strcat(result, "\tSenior lecturers:\n");
	strcat(result, "\t\tName\t\tSurname\t\tAge\t\tIs Ph.D.\n");
	strcat(result, "\t\t__________________________________________________________________\n");
	for each (seniorLecturer var in sLecturers) {
		char * buff = var.to_str();
		strcat(result, "\t\t");
		strcat(result, buff);
		strcat(result, "\n");
		free(buff);
		buff = NULL;
	}
	strcat(result, "\tAssistants:\n");
	strcat(result, "\t\tName\t\tSurname\t\tAge\t\tIs Ph.D.\n");
	strcat(result, "\t\t__________________________________________________________________\n");
	for each (assistant var in assistants) {
		char * buff = var.to_str();
		strcat(result, "\t\t");
		strcat(result, buff);
		strcat(result, "\n");
		free(buff);
		buff = NULL;
	}
	return result;
}

void professor::set() {
	person.set();
	printf("Academic title\n1)Professor\n2)Docent\n3)Senior Serearch Fellow\n");
	int choice = input_field("", 1, 3);
	switch (choice) {
		case 1: {
			title = Professor;
			break;
		}
		case 2: {
			title = Docent;
			break;
		}
		case 3: {
			title = SeniorResearchFellow;
			break;
		}
		default: break;
	}
}

void docent::set() {
	person.set();
	printf("Academic title\n1)Professor\n2)Docent\n3)Senior Serearch Fellow\n");
	int choice = input_field("", 1, 3);
	switch (choice) {
		case 1: {
			title = Professor;
			break;
		}
		case 2: {
			title = Docent;
			break;
		}
		case 3: {
			title = SeniorResearchFellow;
			break;
		}
		default: break;
	}
}

void assistant::set() {
	person.set();
	printf("Is Ph.D. (Y/N)? ");
	char choice;
	while (true) {
		choice = getchar();
		if ((choice == 'Y') | (choice == 'y')) break;
		else if ((choice == 'N') | (choice == 'n')) break;
		else printf("Wrong answer!\n");
	}
	if ((choice == 'Y') | (choice == 'y')) isPhD = true;
	else isPhD = false;
}

void seniorLecturer::set() {
	person.set();
	printf("Is Ph.D. (Y/N)? ");
	char choice;
	while (true) {
		choice = getchar();
		if ((choice == 'Y') | (choice == 'y')) break;
		else if ((choice == 'N') | (choice == 'n')) break;
		else printf("Wrong answer!\n");
	}
	if ((choice == 'Y') | (choice == 'y')) isPhD = true;
	else isPhD = false;

}

char * professor::to_str() {
	char * buff = person.to_str();
	int size = strlen(buff) + strlen(titles[title]) + 3;
	char * result = (char *)malloc(sizeof(char)*(++size));	
	result[0] = '\0';
	strcat(result, buff);
	free(buff);
	buff = NULL;
	strcat(result, "\t\t");
	strcat(result, titles[title]);
	return result;
}

char * docent::to_str() {
	char * buff = person.to_str();
	int size = strlen(buff) + strlen(titles[title]) + 3;
	char * result = (char *)malloc(sizeof(char)*(++size));	
	result[0] = '\0';
	strcat(result, buff);
	free(buff);
	buff = NULL;
	strcat(result, "\t\t");
	strcat(result, titles[title]);
	return result;
}

char * seniorLecturer::to_str() {
	char * buff = person.to_str();
	int size = strlen(buff) + 6 + 3;
	char * result = (char *)malloc(sizeof(char)*(++size));
	result[0] = '\0';
	strcat(result, buff);
	free(buff);
	buff = NULL;
	strcat(result, "\t\t");
	char * buff1 = isPhD ? "Ph.D." : "-";
	strcat(result, buff1);
	//free(buff1);
	buff1 = NULL;
	return result;
}

char * assistant::to_str() {
	char * buff = person.to_str();
	int size = strlen(buff) + 6 + 3;
	char * result = (char *)malloc(sizeof(char)*(++size));
	result[0] = '\0';
	strcat(result, buff);
	free(buff);
	buff = NULL;
	strcat(result, "\t\t");
	char * buff1 = isPhD ? "Ph.D." : "-";
	strcat(result, buff1);
	//free(buff1);
	buff1 = NULL;
	return result;
}