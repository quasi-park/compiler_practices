#include "automaton_head.h"

extern int isInt(char *);
extern int isFloat(char *);
extern int isName(char *);

struct mode_selecter {
    int mode_des;
    int (* func_name)(char *);
} mode_ary[] = {
    {INT_MODE, isInt},
    {NAME_MODE, isName},
    {FLOAT_MODE, isFloat},
//    {CHAR_MODE, 0},
//    {NORM_MODE, 0},
    {0, 0}
};

int main(int argc, char *argv[])
{
    int mode, mode_flag, rec;
    struct mode_selecter *p;
    char buf[BUFLEN];
    while(1){
        printf("Input insert mode :");
        scanf("%d", &mode);
        for(p = mode_ary, mode_flag = 0; p->mode_des != 0; p++){
            if(mode == p->mode_des){
                mode_flag = 1;
                break;
            }
        }
        if(!mode_flag){
            fprintf(stderr, "No mode found\n");
            break;
        }
        scanf("%s", buf);
//        fgets(buf, BUFLEN, stdin);
        rec = p->func_name(buf);
        printf("type: %s\n", rec == TRUE ? "OK":"Not OK");
    }
    return 0;
}
