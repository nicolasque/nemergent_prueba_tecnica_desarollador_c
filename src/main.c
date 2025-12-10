#include "../includes/number_list.h"

int main(int argc, char **argv)
{
	int n_threads;
	int n_items;
	// NumberList positive_list;
	// NumberList negative_list;

	parse_and_validate_args(argc, argv, &n_threads, &n_items);

	printf("Thread number: %d\n",n_threads);
	printf("Item number: %d\n",n_items);

	return 0;
}
