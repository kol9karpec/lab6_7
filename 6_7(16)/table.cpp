#include "table.h"

void str_null(char * str) {
	for (int i = 0; i < strlen(str); i++) {
		str[i] = '\0';
	}
}

char *** init_table(int fields_count, field * fields,
	std::vector<university_t> db, int * size) {
	* size = 0;
	for each (university var in db)
	{
		*size += var.hStaff.employeers.size();
		*size += var.tStaff.professors.size();
		*size += var.tStaff.docents.size();
		*size += var.tStaff.sLecturers.size();
		*size += var.tStaff.assistants.size();
	}
	char *** result = (char ***)malloc(sizeof(char**)*(++(*size)));
	
	result[0] = (char **)malloc(sizeof(char*)*fields_count);
	for (int j = 0; j < fields_count; j++) {
		result[0][j] = (char*)malloc(sizeof(char)*(strlen(sFields[fields[j]]) + 1));
		result[0][j][0] = fields[j];
	}

	int counter = 1;
	for each (university un in db)
	{
		char ** man;
		man = (char**)malloc(sizeof(char*) * 8);
		for (int i = 0; i < 8; i++) {
			man[i] = (char*)malloc(sizeof(char) * 50);
			man[i][0] = '\0';
		}

		man[U_Name][0] = '\0';
		strcat(man[U_Name],un.name);
		man[U_H_Name][0] = '\0';
		strcat(man[U_H_Name],un.hName);
		man[Staff][0] = '\0';
		strcat(man[Staff], "Help");
		man[Position][0] = '\0';
		strcat(man[Position], "Help");
		for each (employee_t emp in un.hStaff.employeers)
		{			
			str_null(man[Education]);
			strcat(man[Education],emp.edu ? "higher" : "secondary");
			str_null(man[Name]);
			strcat(man[Name],emp.person.name);
			str_null(man[Surname]);
			strcat(man[Surname] ,emp.person.surname);
			str_null(man[Age]);
			char * buff = (char*)malloc(sizeof(char)*10);
			_itoa(emp.person.age, buff, 10);
			strcat(man[Age],buff);
			free(buff);
			result[counter] = (char**)malloc(sizeof(char*)*fields_count);
			for (int j = 0; j < fields_count; j++) {
				int size = (strlen(man[fields[j]]) + 1);
				result[counter][j] = (char*)malloc(sizeof(char)*size);
				result[counter][j][0] = '\0';
				strcat(result[counter][j], man[fields[j]]);
			}
			counter++;
		}

		str_null(man[Staff]);
		man[Staff] = "Teaching";
		str_null(man[Position]);
		man[Position] = "Professor";
		for each (professor_t prof in un.tStaff.professors)
		{
			man[Education][0] = '\0';
			strcat(man[Education], titles[prof.title]);
			man[Name] = prof.person.name;
			man[Surname] = prof.person.surname;
			man[Age] = _itoa(prof.person.age, man[Age], 10);
			result[counter] = (char**)malloc(sizeof(char*)*fields_count);
			for (int j = 0; j < fields_count; j++) {
				result[counter][j] = (char*)malloc(sizeof(char)*(strlen(man[fields[j]]) + 1));
				result[counter][j][0] = '\0';
				strcat(result[counter][j], man[fields[j]]);
			}
			counter++;
		}

		man[Position] = "Docent";
		for each (docent_t doc in un.tStaff.docents)
		{
			man[Education][0] = '\0';
			strcat(man[Education], titles[doc.title]);
			man[Name] = doc.person.name;
			man[Surname] = doc.person.surname;
			man[Age] = _itoa(doc.person.age, man[Age], 10);
			result[counter] = (char**)malloc(sizeof(char*)*fields_count);
			for (int j = 0; j < fields_count; j++) {
				result[counter][j] = (char*)malloc(sizeof(char)*(strlen(man[fields[j]]) + 1));
				result[counter][j][0] = '\0';
				strcat(result[counter][j], man[fields[j]]);
			}
			counter++;
		}

		man[Position] = "Senior Lecturer";
		for each (seniorLecturer sLec in un.tStaff.sLecturers)
		{
			man[Education] = sLec.isPhD ? "Ph.D." : "-";
			man[Name] = sLec.person.name;
			man[Surname] = sLec.person.surname;
			man[Age] = _itoa(sLec.person.age, man[Age], 10);
			result[counter] = (char**)malloc(sizeof(char*)*fields_count);
			for (int j = 0; j < fields_count; j++) {
				result[counter][j] = (char*)malloc(sizeof(char)*(strlen(man[fields[j]]) + 1));
				result[counter][j][0] = '\0';
				strcat(result[counter][j], man[fields[j]]);
			}
			counter++;
		}

		man[Position] = "Assistant";
		for each (assistant_t ass in un.tStaff.assistants)
		{
			man[Education] = ass.isPhD ? "Ph.D." : "-";
			man[Name] = ass.person.name;
			man[Surname] = ass.person.surname;
			man[Age] = _itoa(ass.person.age, man[Age], 10);
			result[counter] = (char**)malloc(sizeof(char*)*fields_count);
			for (int j = 0; j < fields_count; j++) {
				result[counter][j] = (char*)malloc(sizeof(char)*(strlen(man[fields[j]]) + 1));
				result[counter][j][0] = '\0';
				strcat(result[counter][j], man[fields[j]]);
			}
			counter++;
		}
		/*for (int i = 0; i < 8; i++) {
			free(man[i]);
		}
		free(man);*/
	}

	

	return result;
}

char * table_to_str(char *** table, int size, int fields_count) {
	char * result = (char*)malloc(sizeof(char) * 200 * size);
	result[0] = '\0';
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < fields_count; j++) {
			if (i == 0) {
				strcat(result,sFields[table[i][j][0]]);
				strcat(result, "\t\t");
			}
			else {
				strcat(result, table[i][j]);
				strcat(result, "\t\t");
			}
		}
		strcat(result, "\n");
	}
	return result;
}

void sort_table(char *** table, int size,
	int fields_count,
	int * order,
	bool * sort_type) {
	for (int i = 0; i < fields_count; i++) {
		if (i == 0) {
			int curField = order[i];
			if(curField != -1)
				for (int c = 1; c < size - 1; c++) {
					for (int row = 1; row < size - 1; row++) {
						if (((sort_type[i] == 1) &&
							(strcmp(table[row][curField],table[row + 1][curField]) > 0)) ||
							((sort_type[i] == 0) &&
							(strcmp(table[row][curField], table[row + 1][curField]) < 0))) {
							char ** buff = table[row];
							table[row] = table[row + 1];
							table[row + 1] = buff;
						}
					}
				}
		}
		else {
			int curField = order[i];
			int prevField = order[i - 1];
			if (curField != -1)
				for (int c = 1; c < size - 1; c++) {
					for (int row = 1; row < size - 1; row++) {
						char * buf1 = table[row][prevField];
						char * buf2 = table[row + 1][prevField];
						if( (!strncmp(buf1,buf2,strlen(buf1))) && (strlen(buf1) == strlen(buf2)))
							if (((sort_type[i] == 1) &&
								(strcmp(table[row][curField], table[row + 1][curField]) > 0)) ||
								((sort_type[i] == 0) &&
								(strcmp(table[row][curField], table[row + 1][curField]) < 0))) {
								char ** buff = table[row];
								table[row] = table[row + 1];
								table[row + 1] = buff;
							}
					}
				}
		}
	}
}