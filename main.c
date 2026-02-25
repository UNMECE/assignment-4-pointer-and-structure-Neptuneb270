#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[]) {
   //Create item list
   int list_size = 5;
   Item *item_list = (Item*) malloc(sizeof(Item)*list_size);
   add_item(item_list, (double) 1, "1234", "baking", "flour", 0);
   add_item(item_list, (double) 2, "1235", "dairy", "milk", 1);
   add_item(item_list, (double) 3, "1236", "grains", "oats", 2);
   add_item(item_list, (double) 4, "1237", "clothes", "shirt", 3);
   add_item(item_list, (double) 5, "1238", "dairy", "cheese", 4);

   //Print stuff
   print_items(item_list, list_size);
   printf("average price of items = %lf\n",
      average_price(item_list, list_size));

   //Find SKU

   int curr = 0;
   while (curr < list_size && strcmp(item_list[curr].sku, argv[1]) != 0) {
      curr++;
   }

   (curr == list_size) ? 
      printf("Couldn't find item with SKU %s\n", argv[1]) : 
      printf("Found item %s\n", item_list[curr].name);

   //Free items
   free_items(item_list, list_size);
}

void print_items(Item *item_list, int size) {
   printf("###############\n");
   for (int i = 0; i < size; i++) {
      printf("item name = %s\n item sku = %s\n item category = %s\n item price = %lf\n", 
      item_list[i].name, item_list[i].sku, 
      item_list[i].category, item_list[i].price);
      
      printf("###############\n");
   }
}

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
   int sku_len = strlen(sku);
   int category_len = strlen(category);
   int name_len = strlen(name);
   
   item_list[index].price = sizeof(double);
   item_list[index].sku = (char*) malloc(sizeof(char)*sku_len);
   item_list[index].category = (char*) malloc(sizeof(char)*category_len);
   item_list[index].name = (char*) malloc(sizeof(char)*name_len);

   item_list[index].price = price;
   strcpy(item_list[index].sku, sku);
   strcpy(item_list[index].category, category);
   strcpy(item_list[index].name, name);
   
}

double average_price(Item *item_list, int size) {
   double sum = 0;
   for (int i = 0; i < size; i++) {
      sum += item_list[i].price;
   }
   return (sum/size);
}

void free_items(Item *item_list, int size) {
   for(int i = 0; i <size; i++) {
      free(item_list[i].sku);
      free(item_list[i].category);
      free(item_list[i].name);
   }
   free(item_list);
}
