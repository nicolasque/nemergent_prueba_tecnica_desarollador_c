#ifndef THREAD_ARGS_H
#define THREAD_ARGS_H

#include "number_list.h"

typedef struct {
	int index;
    NumberList *pos_list;
    NumberList *neg_list;
    int items_to_produce;
    unsigned int seed_time;
} ThreadArgs;

void launch_threads(int n_threads, int n_items, NumberList *pos_list, NumberList *neg_list);
#endif // THREAD_ARGS_H