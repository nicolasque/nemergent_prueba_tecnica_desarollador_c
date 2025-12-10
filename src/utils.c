#include "../includes/thread_args.h"

void print_list(NumberList *list)
{
	for (size_t i = 0; i < list->count; i++)
	{
		printf("%zu: %d\n", i, list->data[i]);
	}
}

static int compare_number(const void *a, const void *b)
{
	int int_a = *((int *)a);
	int int_b = *((int *)b);

	if (int_a > int_b)
		return 1;
	if (int_a < int_b)
		return -1;
	return 0;
}

void order_list(NumberList *list)
{
	if (list->count > 1)
	{
		qsort(list->data, list->count, sizeof(int), compare_number);
	}
}
