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
    struct nodes *left, *right, *parent; //pointer for tree
    struct nodes *stack_next, *stack_prev;
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
int get_priority(char c);

int main(int argc, char *argv[])
{
    char c, buf[BUFSIZE];
    int i, prevtype;
    struct nodes head, tail, *new_node, *loop_node;
    struct nodes opp_stack, *cur_sp;
//    scanf("%s", buf);
    fgets(buf, BUFSIZE, stdin);

    /*Initialize header*/
    head.numCount = 0;
    *head.dat = '(';
    head.next = head.prev = &tail;

    /*Initialize tail*/
    tail.numCount = 0;
    *tail.dat = ')';
    tail.next = tail.prev = &head;

    /*Initialize stack*/
    opp_stack.numCount = 0;
    *opp_stack.dat = 0;
    opp_stack.stack_next = opp_stack.stack_prev = &opp_stack;
    cur_sp = &opp_stack;

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
                (tail.prev)->next = new_node;
                new_node->prev = tail.prev;
                new_node->next = &tail;
                tail.prev = new_node;
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
                (tail.prev)->next = new_node;
                new_node->prev = tail.prev;
                new_node->next = &tail;
                tail.prev = new_node;
                prevtype = OPERATION;
                break;
            case SPACE:
                printf("space\n");
                break;
            case OTHERS:
                fprintf(stderr, "found invalid experssion %c. Unable to continue.\n Exiting\n", buf[i]);
                exit(1);
            default:
                break;
        }
    }

    /*debug loop*/
    for(loop_node = head.next;loop_node != &tail; loop_node = loop_node->next){
        printf("%s [%s]\n", loop_node->dat, loop_node->numCount > 0 ? "num":"opp");
    }

    for(loop_node = head.next;loop_node != &head; loop_node = loop_node->next){
        if(loop_node->numCount > 0){
            printf("%s ", loop_node->dat);
        }else{
            while(get_priority(cur_sp->dat[0]) >= get_priority(loop_node->dat[0])){
                printf("%c ", cur_sp->dat[0]);
                (cur_sp->stack_prev)->stack_next = cur_sp->stack_next;
                (cur_sp->stack_next)->stack_prev = cur_sp->stack_prev;
                cur_sp = cur_sp->stack_prev;
            }
            (cur_sp->stack_next)->stack_prev = loop_node;
            loop_node->stack_next = cur_sp->stack_next;
            cur_sp->stack_next = loop_node;
            loop_node->stack_prev = cur_sp;
            cur_sp = loop_node;
        }
    }
    printf("\n");
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
    while('0' <= buf[i] && buf[i] <= '9'){
        tgt->dat[tgt->numCount++] = buf[i];
        i++;
    }
    tgt->dat[tgt->numCount] = '\0';
    return i - 1;
}

int get_priority(char c){
    struct opp * p;
    for (p = opp_ary; p->op_char != 0; p++) {
        if(p->op_char == c){
            return p->priority;
        }
    }
    return -1;
}
