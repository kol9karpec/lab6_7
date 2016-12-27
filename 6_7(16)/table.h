#pragma once

#include "university_t.h"

enum field { U_Name = 0, U_H_Name, Staff, Name, Surname, Age, Position, Education };
static const char * sFields[] = {"University name",
								"University historical name",
								"Staff",
								"Name",
								"Surname",
								"Age",
								"Position",
								"Education"};

char *** init_table(int fields_count, field * fields,
					std::vector<university_t> dataBase, 
					int * size);
char * table_to_str(char *** table, int size, 
					int fields_count);
void str_null(char * str);

void sort_table(char *** table, int size,
				int fields_count,
				int * order,
				bool * sort_type);