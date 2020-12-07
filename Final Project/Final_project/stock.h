#ifndef STOCK_H_
#define STOCK_H_

#define MAX_ITEMS_IN_SALE 100
#define NUM_CATS 7
#include <stdlib.h>
struct Items
{
	int amount;
	int category;
	double price;
	int byWeight;
};

struct StockRecord
{
	struct Items items;
	char *productname;
	double sales;
};

struct SalesRecord
{
	int amount;
	int id;
	
};


void centreText(int num, char symbol, char* title);
#endif // !STOCK_H_