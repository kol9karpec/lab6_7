/* 
	person_t - опис особи
		name - ім'я
		surname - прізвище
*/
#pragma once

typedef struct {
	char name[30];
	char surname[30];
	int age;
} person_t;