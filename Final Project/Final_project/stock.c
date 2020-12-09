#include <stdio.h>
#include <string.h>
#include "stock.h"
char* categories[NUM_CATS] = { "produce", "bakery", "meat", "dairy", "baking", "house wares", "miscellaneous" };



int readStockItems(struct StockRecord *current_stock, int entries, int stock)
{
	int amount, category, byweight;
	double price;
	char name[80];
	int index = 1;
	int flag = 1;
	while (flag && index < entries && scanf("%d", &amount) !=-1)
	{
		
		if (amount == 0)
		{
			flag = 0;
		}
		else
		{
			//ID                       Product        Category    Price Quantity
			scanf(" , %d , %lf , %d , %[^\n]", &category, &price, &byweight, name);

			while ((category < 1) || (category > 7))
			{
				printf("Invalid Category - Enter a number between 1 and 7 : ");
				scanf(" %d , %lf , %d , %[^\n]", &category, &price, &byweight, name);
			}
			while ((byweight != 0) && (byweight != 1))
			{
				printf("Invalid soldByWeight - Enter a number between 0 and 1 : ");
				scanf(" %d , %[^\n]", &byweight, name);
			}

			current_stock[index].items.amount = amount;
			current_stock[index].items.category = category;
			current_stock[index].items.byWeight = byweight;
			current_stock[index].items.price = price;

			current_stock[index].productname = calloc(strlen(name), sizeof(char));  //calloc
			strcpy(current_stock[index].productname, name);
			current_stock[index].sales = 0.0;
			index++;  
		}
		
	}

	return index;
}

void centreText(int num, char symbol, char* title)
{
	int len = 0;
	len = strlen(title);
	for (int i = 0; i < (num - len) / 2; i++)
	{
		printf("%c", symbol);
	}
	printf("%s", title);
	for (int i = 0; i < (num - len) / 2; i++)
	{
		printf("%c", symbol);
	}
}


void printStockReport(struct StockRecord *storeStock, int numStockItems)
{
	int i;
	printf("ID                       Product        Category    Price Quantity\n");
	for (i = 1; i < numStockItems; i++)
	{
		printf("%d %30s %14s %9.2lf %8d\n", i, storeStock[i].productname, categories[storeStock[i].items.category-1], storeStock[i].items.price, storeStock[i].items.amount);
		
	}
}

int readSale(struct StockRecord* storeStock, int numStockItems, struct SalesRecord* saleItems)
{
	int purchaseID = 0;
	int purchaseQty = 0;
	int index = 0;
	int flag = 1;

	printf("Enter a product ID to purchase, and the quantity(0 to stop) : ");
	//printf("%d", numStockItems);
	//printf("%d", flag && index < numStockItems);
	while (flag && index < numStockItems && scanf(" %d", &purchaseID) != -1)
	{
		
		//printf("%d", purchaseID);
		if (purchaseID == 0)
		{
			flag = 0;
		}
		else
		{
			scanf(" , %d", &purchaseQty);
			while ((purchaseID < 0) || (purchaseID > numStockItems-1))
			{
				printf("Invalid Product - Enter a number between 0 and %d : ", numStockItems - 1);
				scanf(" %d , %d", &purchaseID, &purchaseQty);
			}
			while ((purchaseQty < 0.10) || (purchaseQty > 100.00))
			{
				printf("Invalid quantity - Enter a number between 0.10 and 100.00 : ");
				scanf(" %d , %d", &purchaseID, &purchaseQty);
			}
			if (purchaseQty > storeStock[purchaseID].items.amount)
			{
				purchaseQty = storeStock[purchaseID].items.amount;    //庫存的輛
			}
			saleItems[index].id = purchaseID;
			saleItems[index].amount = purchaseQty;

			storeStock[purchaseID].items.amount -= purchaseQty;
			storeStock[purchaseID].sales += purchaseQty;  //銷量
			index++;
		

			printf("Enter a product ID to purchase, and the quantity(0 to stop) : ");
		}
		
	} 
	
	return index;
}

double printSalesReport(struct StockRecord* storeStock, struct SalesRecord* saleItems, int numSaleItems)
{
	int i;
	double sum = 0;
	double tax = 0;
	centreText(70, '*', " Seneca Groceries ");
	printf("\n");
	centreText(70, '=', "");
	printf("\n");
	for (i = 0; i < numSaleItems; i++)
	{
		printf("%s %lf %lf\n", storeStock[saleItems[i].id].productname, storeStock[saleItems[i].id].items.price, saleItems[i].amount * storeStock[saleItems[i].id].items.price);

		sum += saleItems[i].amount * storeStock[saleItems[i].id].items.price;	

		if ((storeStock[saleItems[i].id].items.category == 6) || (storeStock[saleItems[i].id].items.category == 7))
		{
			tax += storeStock[saleItems[i].id].items.price * 0.13 * saleItems[i].amount;
		}


	}
	//printf("Purchase Total                            %lf\n", sum);
	//printf("Tax                                        %lf\n", tax);
	//printf("Total                                     %lf\n", sum + tax);
	return sum;
}

void getTopSellers(struct StockRecord* storeStock, int numStockItems, struct SalesRecord* topSeller, int topk, int category)
{
	int filterIndex = 0;
	int i;
	struct SalesRecord* filter = calloc(numStockItems, sizeof(struct SalesRecord));
	
	// 篩選category 商品
	for (i = 1; i < numStockItems; i++)
	{
		if (storeStock[i].items.category == category+1 && storeStock[i].sales > 0)    
		{
			filter[filterIndex].id = i;
			filter[filterIndex].amount = (int)storeStock[i].sales;
			filterIndex++;
		}
	}
	// 商品排序
	qsort(filter, filterIndex, sizeof(struct SalesRecord), compare);
	for (i = 0; i < topk; i++)
	{
		if (i < filterIndex)
		{
			memcpy(&topSeller[i], &filter[i], sizeof(struct SalesRecord));      // 複製 sizeof(struct SalesRecord) 給 topSeller[i]
		}
		else
		{
			topSeller[i].id = 0;
			topSeller[i].amount = 0;
		}
		
	}
	free(filter);
}
//Sort
int compare(const struct SalesRecord* left, const struct SalesRecord* right)
{
	if (left->amount < right->amount)
		return 1;
	else if (left->amount > right->amount)
		return -1;
	else
		return 0;
}

void printTopSellers(struct StockRecord* storeStock, struct SalesRecord* topSeller, int topk, int category)
{

	int i;
	printf("---------- Top %d sellers in %s ----------\n", topk, categories[category]);
	for (i = 0; i < topk; i++)
	{
		//printf("%d %s %lf\n", i + 1, storeStock[topSeller[i].id].productname, topSeller[i].amount);
		if (topSeller[i].id > 0)
		{
			printf("%d %s %lf\n", i + 1, storeStock[topSeller[i].id].productname, (double)topSeller[i].amount);
		}
		else
		{
			printf("%d %s %lf\n", i + 1, "<none>", (double)topSeller[i].amount);
		}
	}
}