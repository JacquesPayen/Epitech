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

int	main()
{
	Stats	account;
	int	i = 0;
	std::vector<std::vector<float>>	list;
	Arg	info(20, 2.00, NULL, 25);

	list = create_list();
	while (i != 3600)
	{
		get_indexes(list);
		if (list[0].size() > 19) {
			account = buy_crypto(list[0], info, "crypto", account);
			account = buy_crypto(list[1], info, "raw_material", account);
			account = buy_crypto(list[2], info, "stock_exchange", account);
			account = buy_crypto(list[3], info, "forex", account);
			account = sell_crypto(list[0], info, "crypto", account);
			account = sell_crypto(list[1], info, "raw_material", account);
			account =sell_crypto(list[2], info, "stock_exchange", account);
			account = sell_crypto(list[3], info, "forex", account);
		}
		usleep(49000);
		i++;
	}
	account.update_share();
	market_op(1, "crypto", account.get_share("crypto"));
	market_op(1, "raw_material", account.get_share("raw_material"));
	market_op(1, "stock_exchange", account.get_share("stock_exchange"));
	market_op(1, "forex", account.get_share("forex"));
	std::cout << "EXIT" << std::endl;
	fflush(stdout);
	return 0;
}
