#pragma once

#include <vector>
#include <stdio.h>

template <typename T>
int vec_to_bFile(FILE ** file, std::vector<T> * source) {
	if (*file == NULL) return 0;
	else {
		int size = source->size();
		fwrite(&size, sizeof(int), 1, *file);
		fwrite(source->data(), sizeof(T)*size, 1, *file);
		return 1;
	}
}
template <typename T>
std::vector<T> * vec_from_bFile(FILE ** file, 
								std::vector<T> * destination) {
	if (*file == NULL) return NULL;
	else {
		if (destination == NULL) destination = new std::vector<T>();
		int size;
		fread(&size, sizeof(int), 1, *file);
		T * data = (T *)malloc(sizeof(T)*size);
		fread(data, sizeof(T)*size, 1, *file);
		for (int i = 0; i < size; i++)
			destination->push_back(data[i]);
		free(data);
		return destination;
	}
}
