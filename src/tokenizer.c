#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  return (c == ' '|| c == '\t');
}
int non_space_char(char c)
{
  return c != ' ' && c != '\t' && c != '\0';
}

char *word_start(char *s)
{
  do
    {
    if(non_space_char(*s))
      {
      return s;
    }
  }while(*(++s) != '\0');
  return 0;
}

char *word_terminator(char *word)
{
  while(word != 0)
    {
    if(!non_space_char(*word))
      {
      return word;
    }
    word++;
  }
  return 0;
}

int count_words(char *s){
  int count =0;
  while(*s != '\0')
    {
    s = word_start(s);
    s = word_terminator(s);
    count++;
  }
  return count;
}

char *copy_str(char *in_str, short len)
{
  char *out_str = (char*) malloc(sizeof(char) * len + 1);
  char *c = out_str;
if(!out_str)
  {
    fprintf(stderr, "copy_str: memory allocation error!");
    exit(EXIT_FAILURE);
  }

//loop over the word for the len of characters
 for (short i =0; i <len; i++)
  {
    *c = *in_str;
    if( *c =='\0')
      {
      break;
    }
    c++;
    in_str++;
  }
// make sure the string ends with a terminator
 *c = '\0';
 return out_str;
}

char **tokenize(char* str){
  int words = count_words(str);
  char **tokens = malloc(sizeof(char*) * (words +1));

  if(!tokens)
    {
    fprintf(stderr, "tokenize memory allocation eror");
    exit(EXIT_FAILURE);
  }

  str = word_start(str);
  
  for (int i =0; i< words; i++){
    char* terminator = word_terminator(str);
    tokens[i] = copy_str(str, terminator - str);

    str = word_start(terminator);
  }

  //point the last pointer to nothing
  char** terminator = tokens + words;
  *terminator = 0;
  
  return tokens;

}
void print_tokens(char **tokens)
{
  printf("{\n");
  for (char** token = tokens; *token != 0; token++)
    {
      printf("\t[%ld '%s\n", token - tokens, *token);
      printf("}\n\n");
    }
}

void free_tokens(char **tokens)
{
  char **token = tokens;

  while(*token != 0)
    {
    free(*token);
    token++;
  }
  
  free(*token);
  free(tokens);
}
