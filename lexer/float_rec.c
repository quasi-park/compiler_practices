#include "automaton_head.h"

int isFloat(char * buf);

// int main(int argc, char *argv[])
// {
//     char buf[BUFLEN];
//     int ret;

//     // fgets(buf, BUFLEN, stdin);
//     scanf("%s", buf);
//     ret = isFloat(buf);
//     printf("%s is %s\n", buf, ret ? "Float":"Not Float");
//     return 0;
// }

int isFloat(char * buf){
    int stat;
 
    stat = STAT_ENTRY;

    while(*buf != 0 && *buf != ';'){
        if(*buf >= '9' || *buf <='0'){
            if(*buf == '.' && stat == STAT_ENTRY){
                stat = STAT_DOT;
            }else{
                stat = STAT_OTHER;
                break;
            }
        }else{
            if(stat == STAT_DOT){
                stat = STAT_NUM;
            }
        }
        buf++;
    }

    if(stat == STAT_ENTRY || stat == STAT_NUM)
        return TRUE;
    return FALSE;
}
