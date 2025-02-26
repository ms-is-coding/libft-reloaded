/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:24:31 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/25 14:33:31 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
extern "C" {
#include "libft.h"
}

void test_alloc() {
	describe("alloc");
	test<void *, const char *>("malloc", [](auto res) {
		void *ptr = ft_malloc(10);
		ExpectResult expect = expect_neq((void *)NULL, ptr, "test1");
		if (expect.error)
			res.push_back(expect);
	});
}
