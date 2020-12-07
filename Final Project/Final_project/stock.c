#include <stdio.h>
#include <string.h>
#include "stock.h"


int readStockItems(struct StockRecord current_stock[], int entries, int stock)
{

	return;
}

void centreText(int num, char symbol, char* title)
{
	int len = 0;
	len = strlen(&title);

}

void printStockReport(struct StockRecord *storeStock, int numStockItems)
{
	int i;
	printf("ID                       Product        Category    Price Quantity\n");
	for (i = 0; i < numStockItems; i++)
	{
		printf("%d %s %s %.2f %d\n", i + 1, storeStock[i].productname, storeStock[i].items.category, storeStock[i].items.price, storeStock[i].items.amount);
	}
}

int readSale(struct StockRecord* storeStock, int numStockItems, struct SalesRecord* saleItems)
{
	int purchaseID = 0;
	int purchaseQty = 0;

	printf("Enter a product ID to purchase, and the quantity(0 to stop) : ");
	scanf("%d, %d", &purchaseID, &purchaseQty);
	for (i = 0; i < numStockItems; i++)
	{

	}
	return;
}

double printSalesReport()
{
	return;
}

void getTopSellers()
{

}

void printTopSellers()
{

}