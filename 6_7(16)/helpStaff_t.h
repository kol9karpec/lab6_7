#pragma once

#include <vector>
#include "person_t.h"


typedef struct {
	person_t person;
	bool edu; // 0 - ������� �����, 1 - ���� �����
}employee_t;

typedef struct {
	std::vector<employee_t> employeers;
} helpStaff_t;