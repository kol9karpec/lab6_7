#include "helpStaff_t.h"

void employee_t::set_employee() {
	person.setPerson();
	edu = input_field("Education(0 - secondary, 1 - higher)", 0, 1);
}

void helpStaff_t::set_help_staff() {
	printf("Enter data for employeers from help staff: \n");
	while (true) {
		employee_t employee;
		employee.set_employee();
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
	count = employeers.size();
}