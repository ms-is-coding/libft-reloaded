/* ************************************************************************** */
/*                                                                            */
/*                                                         ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   */
/*   vector.cpp                                            ⠀⠀⠀⠀⢀⣴⣿⠟⠁ ⣿⠟⢹⣿⣿⠀   */
/*                                                         ⠀⠀⢀⣴⣿⠟⠁⠀⠀⠀⠁⢀⣼⣿⠟⠀   */
/*   By: smamalig <smamalig@student.42.fr>                 ⠀⣴⣿⣟⣁⣀⣀⣀⡀⠀⣴⣿⡟⠁⢀⠀   */
/*                                                         ⠀⠿⠿⠿⠿⠿⣿⣿⡇⠀⣿⣿⣇⣴⣿⠀   */
/*   Created: 2025/06/04 15:41:54 by smamalig              ⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀   */
/*   Updated: 2025/06/04 18:00:52 by smamalig              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <signal.h>
extern "C" {
#include "libft.h"
}

void print_value(t_value value) {
	if (value.type == TYPE_UNDEFINED) {
		printf("undefined\n");
		return ;
	}
	printf("%lu\n", value.value.u64);
}

void print_internal(t_vector *vec) {
	printf("=== Vector { length = %zu, capacity = %zu, offset = %zu } ===\n",
		vec->length, vec->capacity, vec->offset);
	for (size_t i = 0; i < vec->capacity; i++) {
		printf("- ");
		print_value(vec->data[i]);
	}
	printf("=== === ===\n");
}

void at_value(t_vector *vec, ssize_t idx) {
	printf("vec[%li] = ", idx);
	t_value value = ft_vector_at(vec, idx);
	print_value(value);
}

void pop_value(t_vector *vec) {
	printf("pop = ");
	t_value value = ft_vector_pop(vec);
	print_value(value);
}

void shift_value(t_vector *vec) {
	printf("shift = ");
	t_value value = ft_vector_shift(vec);
	print_value(value);
}

void test_vector() {
	describe("vector");
	
	t_vector vec;
	t_vector *ptr = &vec;
	if (ft_vector_init(ptr, 4) != RESULT_OK)
		exit(SIGSEGV);
	at_value(ptr, 0);
	printf("---\n");
	ft_vector_push(ptr, ft_gen_val(TYPE_OTHER, { .u64 = 1 }));
	ft_vector_push(ptr, ft_gen_val(TYPE_OTHER, { .u64 = 2 }));
	ft_vector_push(ptr, ft_gen_val(TYPE_OTHER, { .u64 = 3 }));
	printf("---\n");
	pop_value(ptr);
	printf("---\n");
	shift_value(ptr);
	ft_vector_push(ptr, ft_gen_val(TYPE_OTHER, { .u64 = 42 }));
	ft_vector_unshift(ptr, ft_gen_val(TYPE_OTHER, { .u64 = 123 }));
	ft_vector_unshift(ptr, ft_gen_val(TYPE_OTHER, { .u64 = 21 }));
}
