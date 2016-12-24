#pragma once

#include <vector>
#include "person_t.h"
#include <stdio.h>
#include <stdlib.h>
#include "vectorio.h"


typedef struct {
	person_t person;
	bool edu; // 0 - середня освіта, 1 - вища освіта

	void set();
	char * to_str();
} employee_t;

typedef struct {
	std::vector<employee_t> employeers;

	void set();
	int to_bFile(FILE ** file);
	int from_bFile(FILE ** file);
	/*
		error codes:
		0 - null file pointer
	*/
	char * to_str();
} helpStaff_t;