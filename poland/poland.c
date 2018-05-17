#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUFSIZE 256
#define MAXBUF 16

#define NUMBER 0
#define OPERATION 1
#define SPACE 2
#define OTHERS 3

#define PRY_LOW 0
#define PRY_MID 1
#define PRY_HIGH 2

struct nodes {
    short numCount;
    char dat[MAXBUF];
    struct nodes *next, *prev; //pointer for list
    struct nodes *left, *right; //pointer for tree`
};

struct opp {
    char op_char;
    int priority;
} opp_ary[] = {
    {'(', PRY_LOW},
    {')', PRY_LOW},
    {'+', PRY_MID},
    {'-', PRY_MID},
    {'*', PRY_HIGH},
    {'/', PRY_HIGH},
    {0, 0}
};

int get_type(char *, int);
int num_div(char *, int, struct nodes *);

int main(int argc, char *argv[])
{
    char c, buf[BUFSIZE];
    int i, prevtype;
    struct nodes head, *new_node;
 
//    scanf("%s", buf);
    fgets(buf, BUFSIZE, stdin);

    /*Initialize header*/
    head.numCount = 0;
    *head.dat = '(';
    head.next = head.prev = &head;
    head.left = head.right = 0;

    prevtype = OPERATION;
    for (i = 0; buf[i] != 0; i++) {
        /* TODO: for each buf char, check type. */
        switch(get_type(buf, i)){
            case NUMBER:
                printf("NUM: %c\n", buf[i]);
                if(prevtype == NUMBER){
                    fprintf(stderr, "number came after number. Wrong expression.\nExiting\n");
                    exit(1);
                }
                new_node = (struct nodes *)malloc(sizeof(struct nodes));
                i = num_div(buf, i, new_node);
                (head.prev)->next = new_node;
                new_node->prev = head.prev;
                new_node->next = &head;
                head.prev = new_node;
                prevtype = NUMBER;
                break;
            case OPERATION:
                printf("OPP: %c\n", buf[i]);
                if(prevtype == OPERATION){
                    fprintf(stderr, "operation came after operation. Wrong expression.\nExiting\n");
                    exit(1);
                }
                new_node = (struct nodes *)malloc(sizeof(struct nodes));
                new_node->dat[0] = buf[i];
                new_node->dat[1] = '\0';
                new_node->numCount = 0;
                (head.prev)->next = new_node;
                new_node->prev = head.prev;
                new_node->next = &head;
                head.prev = new_node;
                prevtype = OPERATION;
                break;
            case SPACE:
                printf("space\n");
                break;
            case OTHERS:
                fprintf(stderr, "found invalid experssion %c. Unable to continue.\n Exiting\n", buf[i]);
                free(new_node);
                exit(1);
            default:
                break;
        }
    }

    for(new_node = head.next; new_node != &head; new_node = new_node->next){
        printf("%s\n", new_node->dat);
    }
    return 0;
}

int get_type(char * buf, int i){
    struct opp * p;
    if('0' <= buf[i] && buf[i] <= '9'){
        return NUMBER;
    }else{
        for (p = opp_ary; p->op_char != 0; p++) {
            if(p->op_char == buf[i]){
                return OPERATION;
            }
        }
    }
    if(isspace(buf[i])){
        return SPACE;
    }
    return OTHERS;
}

int num_div(char * buf, int i, struct nodes * tgt){
    int j;
    j = 0;
    while('0' <= buf[i] && buf[i] <= '9' && i <= strlen(buf)){
        tgt->dat[j] = buf[i];
        i++;
        j++;
    }
    tgt->dat[j] = '\0';
    return i - 1;
}
