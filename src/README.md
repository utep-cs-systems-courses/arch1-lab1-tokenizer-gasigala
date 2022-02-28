Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file...

# C Files

## ui.c

first attemps at this tried to use to use the code from lab one to make a
switch statement what would continually run this however came with some
problems and based on what my classmates were doing I decieded to make a
function to process the input once it was recieved from the user. This logic
relies on using the '!' character followed by a command, otherwise the input
entered by the user will be echoed then added to the history. A command of
'!h' or '!' will print the history of past inputs entered while '!q' will free
this memory that the input is stored in then exit the program.A commond of
'!<i>' where i is an given integer will print the history from that given
point by calling **get_history** once a valid pointer is returned the string
is then tokenized and displayed to the user.

## tokenizer.c

**space_char** as well as **non_space_char** are pretty self
  explanitory. **word_start**. ** word_start** uses a do while as we might
  start on a non space char, we could just increment the pointer at the end of
  a regular while loop but whats the fun in that. **count_words** loops until
  we find the terminating string character, utilizing both word start and word
  terminator. **copy_str** allocates memory the size of the original string
  then uses another pointer to update the individual indexes. **tokenize**
  makes an array of pointers then goes through the string to find the word
  terminator the copies the word from the beggining by setting the teminator
  back by the lenght of the string. **print_tokens** loops through our
  character array then prints it. **free_tokens** deallocates the memory taken
  by the tokens.

## history.c

**init_history** initializes our struc , **add_history** makes a new node
  assings the input to it then if it is the first item in our linked list sets
  it at the root. Other wise we loop through out list till our pointer is null
  and sets it to the end out list and updates the index accordingly. 
