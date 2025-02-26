/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:26:23 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/25 14:36:38 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <climits>
extern "C" {
#include "libft.h"
}

void test_math() {
	describe("math");
	test<int, const char *>("nmax", [](auto res) {
		ExpectResult expect = expect_eq(123, ft_nmax(4, 10, 42, INT_MIN, 123), "test1");
		if (expect.error)
			res.push_back(expect);
	});
}

