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

	count = professors.size();
	count += docents.size();
	count += sLecturers.size();
	count += assistants.size();
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