/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:30:45 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/11 14:52:57 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
extern "C" {
#include "libft.h"
}

void test_file() {
	describe("file");
	t_file file;
	int fd[2];

	pipe(fd);
	dprintf(fd[1], "12 -42 -2147483648    -2147483649 2147483647 2147483648 "
		 "12371928739102783918237120938170923871029387 21-15");
	ft_file_init(&file, fd[0]);
	close(fd[1]);
	test<int, const char *>("atoi", [&](auto &res){
		int ret;
		t_result result;
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq(12, ret, "12"));
		res.add(expect_eq((int)RESULT_OK, (int)result, "12 result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq(-42, ret, "-42"));
		res.add(expect_eq((int)RESULT_OK, (int)result, "-42 result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq(INT_MIN, ret, "INT_MIN"));
		res.add(expect_eq((int)RESULT_OK, (int)result, "INT_MIN"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq((int)RESULT_OVERFLOW, (int)result, "INT_MIN-1 result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq(INT_MAX, ret, "INT_MAX"));
		res.add(expect_eq((int)RESULT_OK, (int)result, "INT_MAX result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq((int)RESULT_OVERFLOW, (int)result, "INT_MAX+1 result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq((int)RESULT_OVERFLOW, (int)result, "whatever this is"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq(21, ret, "21"));
		res.add(expect_eq((int)RESULT_OK, (int)result, "21 result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq(-15, ret, "-15"));
		res.add(expect_eq((int)RESULT_OK, (int)result, "-15 result"));
		result = ft_file_atoi32(&file, &ret);
		res.add(expect_eq((int)RESULT_EOF, (int)result, "next result"));
	});
	close(fd[0]);
}

