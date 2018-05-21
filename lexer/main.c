#include "automaton_head.h"

extern int isInt(char *);
extern int isFloat(char *);
extern int isName(char *);
extern int char_check(char *);

struct mode_selecter {
    char DEBUG_NAME[BUFLEN];
    int mode_des;
    int (* func_name)(char *);
} mode_ary[] = {
    {"integer mode", INT_MODE, isInt},
    {"name mode", NAME_MODE, isName},
    {"float mode", FLOAT_MODE, isFloat},
    {"char mode", CHAR_MODE, char_check},
//    {"normal mode", NORM_MODE, 0},
    {"fall through", 0, 0}
};

int main(int argc, char *argv[])
{
    int mode, mode_flag, rec;
    struct mode_selecter *p;
    char buf[BUFLEN];

    printf("===\n");
    printf("1: Integer mode\n");
    printf("2: Name Mode\n");
    printf("3: Float Mode\n");
    printf("4: Char Mode\n");
    printf("5: Norm Mode(Under construction)\n");
    printf("All the other mode will terminate this app\n");
    printf("===\n");

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
        printf("%s\n", p->DEBUG_NAME);
        scanf("%s", buf);
//        fgets(buf, BUFLEN, stdin);
        rec = p->func_name(buf);
        printf("type: %s\n", rec == TRUE ? "OK":"Not OK");
    }
    return 0;
}
