#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teachingStaff_t.h"
#include "helpStaff_t.h"
#include <typeinfo>


typedef struct university{
	char name[50];
	char hName[50];
	teachingStaff_t tStaff;
	helpStaff_t hStaff;

	void set();
	void set(FILE ** file);
	char* to_str();
	void to_bFile(FILE ** file);
	void from_bFile(FILE ** file);
} university_t;
