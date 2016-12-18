#pragma once

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "teachingStaff_t.h"
#include "helpStaff_t.h"
#include <typeinfo>


typedef struct university{
	char name[50];
	char hName[50];
	int staffCount;
	teachingStaff_t tStaff;
	helpStaff_t hStaff;

	void setUniversity();
} university_t;
