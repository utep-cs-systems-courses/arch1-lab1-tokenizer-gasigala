#include <stdio.h>

int main()
{
  puts("hello");
  fputs("type something bro... idgaf whatever is cool\n",stdout);
  int input;
  input = getchar();
  switch(input){
  case 'p':
    puts("you are pushing p!....");
    puts("you a playa\n");
    break;
  default:
    puts("you NOT P");
  }
}
