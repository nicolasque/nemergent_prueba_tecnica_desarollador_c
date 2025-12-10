#include "../includes/number_list.h"

void init_list(NumberList *list, int n_items)
{
	if (!list)
	{
		fprintf(stderr, "Error: No se ha dado ninguna lista.\n");
        exit(EXIT_FAILURE);
	}

	(void)n_items;
	list->data = NULL;
	list->capacity = 0;
	list->count = 0;

}