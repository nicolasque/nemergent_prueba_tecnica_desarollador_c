#include "../includes/thread_args.h"

static void add_number(NumberList *list, int number)
{
	pthread_mutex_lock(&list->mutex);
	if (list->count >= list->capacity)
	{
		size_t new_capacity = list->capacity * 1.2;
		int *new_data = realloc(list->data, new_capacity * sizeof(int));

		if (!new_data)
		{
			fprintf(stderr, "Error: Fallo fatal en realloc.\n");
			pthread_mutex_unlock(&list->mutex);
			exit(EXIT_FAILURE);
		}

		list->data = new_data;
		list->capacity = new_capacity;
	}
	list->data[list->count] = number;
	list->count++;
	pthread_mutex_unlock(&list->mutex);
}

void *thread_routine(void *arg)
{
	ThreadArgs *args = (ThreadArgs *)arg;
	unsigned int seed = args->seed_time;
	int num;

	for (int i = 0; i < args->items_to_produce; i++)
	{
		num = (int)rand_r(&seed);

		if (rand_r(&seed) % 2 != 0)
		{
			num = -num;
		}
		if (num >= 0)
		{
			add_number(args->pos_list, num);
		}
		else
		{
			add_number(args->neg_list, num);
		}
	}

	free(args);
	return NULL;
}

void launch_threads(int n_threads, int n_items, NumberList *pos_list, NumberList *neg_list)
{
	pthread_t *threads = malloc(n_threads * sizeof(pthread_t));
	if (!threads)
	{
		fprintf(stderr, "Error: No se pudo asignar memoria para los hilos.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n_threads; i++)
	{
		ThreadArgs *args = malloc(sizeof(ThreadArgs));
		if (!args)
		{
			fprintf(stderr, "Error: Fallo al crear argumentos para hilo.\n");
			exit(EXIT_FAILURE);
		}

		args->index = i;
		args->pos_list = pos_list;
		args->neg_list = neg_list;
		args->items_to_produce = n_items;
		args->seed_time = time(NULL) + i * 100;

		if (pthread_create(&threads[i], NULL, thread_routine, args) != 0)
		{
			fprintf(stderr, "Error: Fallo al crear el hilo %d.\n", i);
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i < n_threads; i++)
	{
		pthread_join(threads[i], NULL);
	}

	free(threads);
}