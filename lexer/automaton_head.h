#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*** header for char_rec ***/
#define STAT_FLETTER 1
#define STAT_OLETTER 2
#define STAT_NOTLETTER 3

/*** header for float_rec/int_rec ***/
#define STAT_ENTRY 1
#define STAT_DOT 2
#define STAT_NUM 3
#define STAT_OTHER 4

/*** header for main ***/
#define INT_MODE 1
#define NAME_MODE 2
#define FLOAT_MODE 3
#define CHAR_MODE 4
#define NORM_MODE 5

/*** header for all ***/
#define BUFLEN 256

#define TRUE 1
#define FALSE 0

#define ERR -1

struct variable_list{
    int var_type;
    int stops;
    char var_name[BUFLEN];
    char var_content[BUFLEN];
    struct variable_list *next;
} head;
