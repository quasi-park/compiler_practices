#include "automaton_head.h"

/* correct input looks like: int [name] = 1;*/

struct type_list {
    char type_name[BUFLEN];
    int ret_type;
} type_ary[] = {
    {"int", INT_MODE},
    {"float", FLOAT_MODE},
    {"char", CHAR_MODE},
    {0, 0}
};

char * get_type_name(char *, struct variable_list *);
char * get_var_name(char *, struct variable_list *);

char * get_type_name(char *buf, struct variable_list *node){
    char * head;
    int buf_count;
    struct type_list *p_type;

    head = buf;
    buf_count = 0;

    while(*buf != ' ' && *buf != '\0'){
        if(*buf == ';') node->stops = 1;
        buf++;
        buf_count++;
    }
    *buf = 0;
    for(p_type = type_ary; p_type->ret_type != 0; p_type++){
        if(strcmp(head, p_type->type_name) == 0){
            node->var_type = p_type->ret_type;
            return buf;
        }
    }
    node->var_type = ERR;
    return 0;
}

char * get_var_name(char *buf, struct variable_list *node){
    char * head;
    int buf_count;

    head = buf;
    buf_count = 0;

    while(*buf != ' ' && *buf != '\0' && *buf != '='){
        if(*buf == ';') node->stops = 1;
        buf++;
        buf_count++;
    }
    *buf = 0;

    strcpy(node->var_name, head);
    if(buf_count == 0) return 0;
    return buf;
}

char * get_dat_type(char *buf, struct variable_list *node){
    char * head;
    int buf_count;

    head = buf;
    buf_count = 0;

    while(*buf != ' ' && *buf != '\0' && *buf != '='){
        if(*buf == ';') node->stops = 1;
        buf++;
        buf_count++;
    }
    *buf = 0;

    strcpy(node->var_name, head);
    if(buf_count == 0) return 0;
    return buf;
}

int norm_mode(char* buf){
    char *cur_buf, *tail;
    struct variable_list *ret_list;

    cur_buf = buf;
    tail = cur_buf + strlen(buf);

    ret_list = (struct variable_list *)malloc(sizeof(struct variable_list));

    ret_list->stops = 0;

    cur_buf = get_type_name(cur_buf, ret_list);
    if(cur_buf == tail || cur_buf == 0 || ret_list->stops) return FALSE;

    cur_buf = get_var_name(++cur_buf, ret_list);
    if(cur_buf == tail || cur_buf == 0) return FALSE;

    return TRUE;
}
