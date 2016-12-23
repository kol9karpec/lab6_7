#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "university_t.h"
#include <string.h>

void help_out(int choice);
bool open_file(FILE ** f);

int main(int argc, const char * argv[])
{
	printf(":::::::::Database of universities:::::::::\n");
	while(true) {
		FILE * fp = NULL;
		while (!open_file(&fp));
		fseek(fp,0, SEEK_END);
		if (ftell(fp) <= 0) printf("File is empty!");
		rewind(fp);

		university_t u;
		//u.setUniversity();

		fwrite(&u, sizeof(university_t), 1, fp); 
		fread(&u,sizeof(university_t),1,fp);
		printf("Name: %s", u.name);

		
		fclose(fp);
		free(fp);
		break;
	}
	return 0;
}

void help_out(int choice) {

}
bool open_file(FILE ** f) {
	char file[256];
	printf("Please, input the name of file with database: ");
	scanf("%s", file);
	*f = fopen(file, "wb+");
	if (*f == NULL) {
		printf("File open error!\n");
		return false;
	}
	else return true;
}