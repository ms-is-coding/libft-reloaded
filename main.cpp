/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms <smamalig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:58:26 by ms                #+#    #+#             */
/*   Updated: 2025/02/09 14:30:37 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <cctype>
#include <cstddef>
#include <string.h>

extern "C" {
	#include "libft.h"
}

void test_ft_ctype() {
	describe("ft_ctype");
	it<bool, int>("ft_isalnum", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isalnum(i), !!ft_isalnum(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isalpha", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isalpha(i), !!ft_isalpha(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_iscntrl", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!iscntrl(i), !!ft_iscntrl(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isdigit", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isdigit(i), !!ft_isdigit(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isgraph", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isgraph(i), !!ft_isgraph(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_islower", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!islower(i), !!ft_islower(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isprint", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isprint(i), !!ft_isprint(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_ispunct", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!ispunct(i), !!ft_ispunct(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isspace", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isspace(i), !!ft_isspace(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isupper", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isupper(i), !!ft_isupper(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isxdigit", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isxdigit(i), !!ft_isxdigit(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isascii", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isascii(i), !!ft_isascii(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<bool, int>("ft_isblank", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(!!isblank(i), !!ft_isblank(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<int, int>("ft_toupper", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(toupper(i), ft_toupper(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<int, int>("ft_tolower", [](auto res) {
		for (int i = 0; i < 256; i++) {
			ExpectResult expect = expect_eq(tolower(i), ft_tolower(i), i);
			if (expect.error)
				res.push_back(expect);
		}
	});
}

void test_ft_string() {
	describe("ft_string");
	it<size_t, const char *>("ft_strlen", [](auto res) {
		const char *tests[] = { "Hello", "" };
		for (const auto test : tests) {
			ExpectResult expect = expect_eq(strlen(test), ft_strlen(test), test);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<char *, char *>("ft_memset", [](auto res) {
		char *test1_a = strdup("Hello");
		char *test1_b = strdup("Hello");
		memset(test1_a, ' ', 4);
		ft_memset(test1_b, ' ', 4);
		ExpectResult expect = expect_str_eq(test1_a, test1_b, (char *)"Hello");
		if (expect.error)
			res.push_back(expect);
	});
}

void test_temp() {
	describe("temp section");
	it<int, const char *>("ft_atoi", [](auto res) {
		const char *tests[] = { "42", "-2147483648", "123a", "hello", " \t\n\r\v\f+42", " + 1" };
		for (int i = 0; i < sizeof(tests) / sizeof(char *); i++) {
			ExpectResult expect = expect_eq(atoi(tests[i]), ft_atoi(tests[i]), tests[i]);
			if (expect.error)
				res.push_back(expect);
		}
	});
	it<size_t, const char *>("ft_strnlen", [](auto res) {
		const char *tests[] = { "12345", "42", "abcdefghi" };
		for (int i = 0; i < sizeof(tests) / sizeof(char *); i++) {
			ExpectResult expect = expect_eq(strnlen(tests[i], 6), ft_strnlen(tests[i], 6), tests[i]);
			if (expect.error)
				res.push_back(expect);
		}
	});
}

int main() {
	test_ft_ctype();
	test_ft_string();

	test_temp();
    return 0;
}
