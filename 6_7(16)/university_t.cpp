#include "university_t.h"

void university::set() {
	input_field("Name", name);
	input_field("Historical name", hName);
	hStaff.set();
	tStaff.set();
	staffCount = hStaff.count + tStaff.count;
}

char* university::to_str() {


	return NULL;
}

