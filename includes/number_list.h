

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
void init_list(NumberList *list, int n_items, int n_threads);
void print_list(NumberList *list);
void order_list(NumberList *list);




#endif // NUMBER_STRUCT_H