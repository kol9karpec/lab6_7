/*
	teachingStaff_t - тип для професорсько-
						викладацького складу
		
*/
#pragma once

#include <vector>
#include "person_t.h"
#include "vectorio.h"

typedef struct professor professor_t;
typedef struct docent docent_t;
typedef struct seniorLecturer seniorLecturer_t;
typedef struct assistant assistant_t;
typedef struct teachingStaff teachingStaff_t;

enum academicTitle_t { Professor = 0, Docent, SeniorResearchFellow };
static const char *titles[] = { "Professor", "Docent", "Senior Research Fellow" };
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

	void set();
	int to_bFile(FILE ** file);
	int from_bFile(FILE ** file);
	char * to_str();
};

struct professor {
	person_t person;
	academicTitle_t title;
	
	void set();
	char * to_str();
};

struct docent {
	person_t person;
	academicTitle_t title;

	void set();
	char * to_str();
};

struct assistant {
	person_t person;
	bool isPhD;

	void set();
	char * to_str();
};

struct seniorLecturer {
	person_t person;
	bool isPhD;

	void set();
	char * to_str();
};

