#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "university_t.h"
#include <string.h>
#include <vector>

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
		else rewind(fp);

		/*university_t u;
		u.setUniversity();

		fwrite(&u, sizeof(university_t), 1, fp); 
		fread(&u,sizeof(university_t),1,fp);
		printf("Name: %s", u.name);*/

		/*struct MyStruct
		{
			int a;
			int b;
			std::vector<int> vec;

			void to_file(FILE * f) {
				fwrite(&a, sizeof(int), 1, f);
				fwrite(&b, sizeof(int), 1, f);
				int size = vec.size();
				fwrite(&size, sizeof(int), 1, f);
				fwrite(vec.data(), (sizeof(int)*vec.size()), 1, f);
			}

			void from_file(FILE * f) {
				fread(&a, sizeof(int), 1, f);
				fread(&b, sizeof(int), 1, f);
				int size;
				fread(&size, sizeof(int), 1, f);
				int * data = (int*)malloc(sizeof(int)*size);
				fread(data, (sizeof(int)*size), 1, f);
				for (int i = 0; i < size; i++) {
					vec.push_back(data[i]);
				}
				free(data);
			}
		} ar,ar1;

		ar.a = 5;
		ar.b = 10;
		ar.vec.push_back(5);
		ar.vec.push_back(10);
		ar.vec.push_back(10);
		ar.vec.push_back(10);
		ar.vec.push_back(10);
		ar.to_file(fp);

		//fwrite(&ar, sizeof( MyStruct), 1, fp);
		rewind(fp);
		//fread(&ar1, sizeof(MyStruct), 1, fp);
		ar1.from_file(fp);

		printf("Result: %i, %i\n",ar1.a,ar1.b);*/

		fclose(fp);
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