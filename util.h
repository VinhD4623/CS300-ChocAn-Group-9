#include <iostream>
#include <cstring>
//These functions are for validating user input to save time
//Example: char x = read_char("Please eneter a value"); <-this will prompt the user enter a char and validate
//Example: read_string("enter a value: ", somechararry, MAXVAL); <- it will update the char array 
char read_char(const char prompt[]);
char read_cmd(void);
void read_string(const char prompt[], char inputstr[], int maxchar);
int read_int(const char prompt[]);
int read_int_wbounds(const char prompt[], int lower_bound, int upper_bound);
int read_int_maxdigits(const char prompt[], int max_num_digits);
float read_float(const char prompt[]);
bool read_bool(const char prompt[]);
double read_double(const char prompt[]);
