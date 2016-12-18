/*
	teachingStaff_t - тип для професорсько-
						викладацького складу
		
*/
#pragma once

#include <vector>
#include "person_t.h"

typedef struct professor professor_t;
typedef struct docent docent_t;
typedef struct seniorLecturer seniorLecturer_t;
typedef struct assistant assistant_t;
typedef struct teachingStaff teachingStaff_t;

enum academicTitle_t { Professor = 0, Docent, SeniorResearchFellow };
static const char *titles[] = { "Professor", "Docent", "SeniorResearchFellow" };
/*
	Professor - професор
	Docent - доцент
	SeniorResearchFellow - старший науковий співробітник
*/

struct teachingStaff {
	std::vector<professor_t> professors;
	std::vector<docent_t> docents;
	std::vector<seniorLecturer_t> sLecturers;
	std::vector<assistant_t> assistants;
	int count;
};

struct professor {
	person_t person;
	academicTitle_t title;
};

struct docent {
	person_t person;
	academicTitle_t title;
};

struct assistant {
	person_t person;
	bool isPhD;
};

struct seniorLecturer {
	person_t person;
	bool isPhD;
};

