//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NOO
// Date:           
//==============================================
// Final Assessment     
//==============================================
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

int readStockItems(struct StockRecord* current_stock, int entries, int stock);

void printStockReport(struct StockRecord* storeStock, int numStockItems);

int readSale(struct StockRecord* storeStock, int numStockItems, struct SalesRecord* saleItems);

double printSalesReport(struct StockRecord* storeStock, struct SalesRecord* saleItems, int numSaleItems);

void getTopSellers(struct StockRecord* storeStock, int numStockItems, struct SalesRecord* topSeller, int topk, int category);

void printTopSellers(struct StockRecord* storeStock, struct SalesRecord* topSeller, int topk, int category);

int compare(const struct SalesRecord* left, const struct SalesRecord* right);

#endif // !STOCK_H_