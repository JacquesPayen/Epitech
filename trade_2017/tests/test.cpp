//
// EPITECH PROJECT, 2018
// test.cpp
// File description:
// 
//

#include "../include/arg.hpp"
#include "../include/output.hpp"
#include "../include/get.hpp"
#include <unistd.h>
#include "../include/stats.hpp"
#include  <criterion/criterion.h>
#include "test.hpp"

std::vector<float>	comp_list()
{
	std::vector<float>	list;

	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	list.push_back(10);
	return list;
}

Test(Arg, getPeriod)
{
	Arg	info(20, 2.00, NULL, 25);

	cr_assert(info.getPeriod() == 20);
}

Test(Arg, getSD)
{
	Arg	info(20, 2.00, NULL, 25);

	cr_assert(info.getSD_Coef() == 2.00);
}

Test(Arg, getIndex)
{
	Arg	info(20, 2.00, NULL, 25);

	cr_assert(info.getIndex() == 25);
}

Test(should, not_buy)
{
	Arg	info(20, 2.00, NULL, 25);
	std::vector<float>	list = comp_list();
	Output	calc(info, list);
	
	cr_assert(should_buy(calc, 11) == 0);
}

Test(should, buy)
{
	Arg	info(20, 2.00, NULL, 25);
	std::vector<float>	list = comp_list();
	Output	calc(info, list);
	
	cr_assert(should_buy(calc, 9) == 1);
}

Test(should, sell)
{
	Arg	info(20, 2.00, NULL, 25);
	std::vector<float>	list = comp_list();
	Output	calc(info, list);
	
	cr_assert(should_sell(calc, 11) == 1);
}

Test(should, not_sell)
{
	Arg	info(20, 2.00, NULL, 25);
	std::vector<float>	list = comp_list();
	Output	calc(info, list);
	
	cr_assert(should_sell(calc, 9) == 0);
}
