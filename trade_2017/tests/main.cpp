//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// 
//

#include "../include/arg.hpp"
#include "../include/output.hpp"
#include "../include/get.hpp"
#include <unistd.h>
#include "../include/stats.hpp"

int	should_buy(Output clac, float val)
{
	if (val < (clac.getMa()))
		return 1;
	return 0;
}

int	should_sell(Output clac, float val)
{
	if (val > (clac.getMa()))
		return 1;
	return 0;
}

Stats	buy_crypto(std::vector<float> list, Arg info, std::string crypto, Stats account)
{
	int	ammount = 1;
	float	money;
	Output calc(info, list);

	if (should_buy(calc, list[0]) == 1)
	{
		money = account.update_money();
		if (money < list[0])
			return account;
		while ((ammount * list[0]) < money)
			ammount++;
		if ((ammount * list[0]) > money)
			ammount--;
		market_op(0, crypto, ammount);
	}
	return account;
}

Stats	sell_crypto(std::vector<float> list, Arg info, std::string crypto, Stats account)
{
	int	ammount;
	Output calc(info, list);
	
	if (should_sell(calc, list[0]) == 1)
	{
		account.update_share();
		if ((ammount = account.get_share(crypto)) == 0)
			return account;
		market_op(1, crypto, ammount);
	}
	return account;
}
