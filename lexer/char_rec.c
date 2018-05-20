#include "automaton_head.h"

int isChar(char * buf, int numAllow);
int isName(char * buf);

// int main(int argc, char *argv[])
// {
//     char buf[BUFLEN];
//     int ret;

//     // fgets(buf, BUFLEN, stdin);
//     scanf("%s", buf);
//     ret = isName(buf);
//     printf("%s is %s\n", buf, ret ? "Name":"Not Name");
//     return 0;
// }

int isName(char * buf){
    int stat, ret;
    stat = STAT_FLETTER;
    while(*buf != 0 && *buf != ';'){
        if(stat == STAT_FLETTER){
            ret = isChar(buf, 0);
            stat = STAT_OLETTER;
        }else{
            ret = isChar(buf, 1);
        }
        if(ret == FALSE){
            stat = STAT_NOTLETTER;
            break;
        }
        buf++;
    }
    if(stat == STAT_OLETTER)
        return TRUE;
    return FALSE;
}

int isChar(char * buf, int numAllow){
    if((*buf >= 'a' && *buf <= 'z') || (*buf >= 'A' && *buf <= 'Z') || *buf == '_'){
        return TRUE;
    }else if(numAllow != 0 && *buf <= '9' && *buf >= '0'){
        return TRUE;
    }
    return FALSE;
}
