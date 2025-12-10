#include "../includes/number_list.h"

void init_list(NumberList *list, int n_items, int n_threads)
{
	list->count = 0;
	size_t total_numbers = (size_t)n_threads * (size_t)n_items;
	size_t estimated_capacity = (total_numbers / 2);

	list->capacity = estimated_capacity;

	list->data = malloc(list->capacity * sizeof(int));
	if (!list->data)
	{
		fprintf(stderr, "Error: Fallo fatal al asignar memoria inicial.\n");
		exit(EXIT_FAILURE);
	}

	if (pthread_mutex_init(&list->mutex, NULL) != 0)
	{
		fprintf(stderr, "Error: Fallo al inicializar el mutex.\n");
		free(list->data);
		exit(EXIT_FAILURE);
	}
}


void free_list(NumberList *list) {
    if (list->data) {
        free(list->data);
        list->data = NULL;
    }
    pthread_mutex_destroy(&list->mutex);
}

