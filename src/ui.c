#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define  BUFFERSIZE 300

static void process_command(char *buffer, List *history, int hist_len)
{
  if(buffer[1] == ' '|| buffer[1] == 'h')
    {
    printf("\nHistory\n");
    print_history(history);
  }
  else if(buffer[1]== 'q')
    {
	puts("temination command recieved\n");
	free_history(history);
	exit(EXIT_SUCCESS);
      }
  else
    {
      int id = atoi(buffer + 1);
      if(id >0)
	{
	char *str = get_history(history, hist_len-id +1);
	
	if(!str)
	  {
	  puts("error no history found");
	  return;
	}
	char **tokens = tokenize(str);
	print_tokens(tokens);
	free_tokens(tokens);
      }
      else
	{
	puts("errow invalid index");
	return;
      }
  }
}

int main()
{
  char a[BUFFERSIZE];
  printf("please enter a string\n");
  printf("please select ! to enter a sentance\n please type !<i> to see history from index i\n");
  printf("please select !h to print all the history\n please select !q to exit the program\n");
  
  List *history = init_history();
  char **tokens;
  int history_len =0;
  
  while(1)
    {
    printf("$ ");
    fgets(a, BUFFERSIZE, stdin);

    if(a[0] == '!')
      {
      process_command(a, history, history_len);
    }
    else
      {
      puts(a);
      add_history(history, a);
      history_len++;
    }
  }
}
