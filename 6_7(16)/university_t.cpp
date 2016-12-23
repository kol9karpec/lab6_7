#include "university_t.h"

void university::setUniversity() {
	input_field("Name", name);
	input_field("Historical name", hName);
	hStaff.set_help_staff();
	tStaff.set_teaching_staff();
	staffCount = hStaff.count + tStaff.count;
}

char* getUniversity() {

	return NULL;
}

