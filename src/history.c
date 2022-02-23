#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List *list  = (List*) calloc(1, sizeof(List));
  //make a list of at least lenght 1
  if (!list)
    {
      fprintf(stderr, "method init_history\nError memory allocation error");
      exit(EXIT_FAILURE);
    }
  return list;
}
int str_len(char *str)
{
  char *ptr = str;
  while(*ptr != '\0'){
    ptr++;
  }
  return ptr - str;
}

void add_history(List *list, char *str)
{
  Item *newNode = (Item*) malloc(sizeof(Item));
  Item *item = list->root;
  Item *previous_item;
  int index;
  int str_length = str_len(str);

  newNode-> str = copy_str(str, str_length);
  //its the first item in our list
  if(!newNode)
    {
      fprintf(stderr,"method: add_history\n merrory allocation error");
      exit(EXIT_FAILURE);
    }
  if(item == NULL)
    {
      list->root = newNode;
      newNode->id =1;
    }
  //put it at the end of the list
  else
    {
      index =0;
      while(item)
	{
	  previous_item  = item;
	  item = item->next;
	  index++;
	}
      previous_item->next = newNode;
      newNode->id = index +1;
    }
}

char *get_history(List *list, int id)
{
  Item* current_item = list->root;
  while(current_item){
    if(current_item->id == id){
      return current_item->str;
    }
    current_item = current_item->next;
  }
}

void print_history(List *list){
  Item* curr_item = list->root;
  while(curr_item){
    if(curr_item->id == 1){
      printf("[%d] - %s", curr_item->id, curr_item->str);
    }
    else
      {
	printf("[%d] -%s", curr_item->id, curr_item->str);
      }
    curr_item = curr_item->next;
  }
}

void free_history(List *list)
{

  Item *item = list->root;
  Item *previous_item;
  
  while(item)
    {
      previous_item = item;
      item = item->next;
      // free the string and the node
      free(previous_item->str);
      free(previous_item);
    }
  //free the linked list
  free(list);
}
