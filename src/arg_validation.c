#include "../includes/number_list.h"

static int is_numeric(const char *str)
{
	if (!str || *str == '\0')
		return 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return 0;
		str++;
	}
	return 1;
}

void parse_and_validate_args(int argc, char **argv, int *n_threads, int *n_items)
{
	if (argc != 3)
	{
		fprintf(stderr, "Error: Número de argumentos incorrecto.\n");
		fprintf(stderr, "Uso correcto: %s <n_hilos> <items_por_hilo>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (!is_numeric(argv[1]) || !is_numeric(argv[2]))
	{
		fprintf(stderr, "Error: Los parámetros deben ser numéricos.\n");
		exit(EXIT_FAILURE);
	}

	*n_threads = atoi(argv[1]);
	*n_items = atoi(argv[2]);

	if (*n_threads <= 0 || *n_items <= 0)
	{
		fprintf(stderr, "Error: El número de hilos y items debe ser mayor que 0.\n");
		exit(EXIT_FAILURE);
	}
}