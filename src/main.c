#include "../includes/thread_args.h"

int main(int argc, char **argv)
{
	int n_threads;
	int n_items;
	NumberList positive_list;
	NumberList negative_list;

	parse_and_validate_args(argc, argv, &n_threads, &n_items);


	printf("Numero de threads %d\n", n_threads);
	printf("Numero de items %d\n", n_items);

	init_list(&positive_list, n_items, n_threads);
	init_list(&negative_list, n_items, n_threads);

	launch_threads(n_threads, n_items, &positive_list, &negative_list);


	order_list(&positive_list);
	order_list(&negative_list);

	printf("======Lista de numeros positivos========\n");
	print_list(&positive_list);
	printf("======Lista de numeros negativos========\n");
	print_list(&negative_list);

	return 0;
}
