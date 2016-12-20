#pragma once

#include <vector>
#include "person_t.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	person_t person;
	bool edu; // 0 - середня освіта, 1 - вища освіта
	void set_employee();
} employee_t;

typedef struct {
	std::vector<employee_t> employeers;
	void set_help_staff();
} helpStaff_t;