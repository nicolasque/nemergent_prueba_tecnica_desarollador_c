

#ifndef NUMBER_STRUCT_H
#define NUMBER_STRUCT_H

#include "libs.h"


typedef struct
{
	int *data;
	size_t count;
	size_t capacity;
	pthread_mutex_t mutex;
} NumberList;

void parse_and_validate_args(int argc, char **argv, int *n_threads, int *n_items);


#endif // NUMBER_STRUCT_H