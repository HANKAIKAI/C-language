#ifndef STOCK_H_
#define STOCK_H_

#define MAX_ITEMS_IN_SALE 100
#define NUM_CATS 7
struct Items
{
	int amount;
	int category;
	float price;
	int byWeight;
};

struct StockRecord
{
	struct Items items;
	char productname;
	float sales;
};

struct SalesRecord
{
	struct Items items;
	char productname;
	float sales;
};

#endif // !STOCK_H_