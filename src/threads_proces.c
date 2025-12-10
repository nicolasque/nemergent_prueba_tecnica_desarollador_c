#include "../includes/thread_args.h"

void *thread_routine(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;

	printf("Hola soy el proceso:  %d\n", args->index);

    return NULL;
}


void launch_threads(int n_threads, int n_items, NumberList *pos_list, NumberList *neg_list) {
    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));
    if (!threads) {
        fprintf(stderr, "Error: No se pudo asignar memoria para los hilos.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n_threads; i++) {
        ThreadArgs *args = malloc(sizeof(ThreadArgs));
        if (!args) {
            fprintf(stderr, "Error: Fallo al crear argumentos para hilo.\n");
            exit(EXIT_FAILURE);
        }

		args->index = i;
        args->pos_list =  pos_list;
        args->neg_list = neg_list;
        args->items_to_produce = n_items;

        if (pthread_create(&threads[i], NULL, thread_routine, args) != 0) {
            fprintf(stderr, "Error: Fallo al crear el hilo %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
}