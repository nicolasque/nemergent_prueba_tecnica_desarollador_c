#include "../includes/thread_args.h"

void print_list(NumberList *list)
{
	for (size_t i = 0; i < list->count; i++)
	{
		printf("%zu: %d\n", i, list->data[i]);
	}
}