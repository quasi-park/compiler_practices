#include "automaton_head.h"

extern int isInt(char * buf);

int main(int argc, char *argv[])
{
    char buf[BUFLEN];
    int ret;

    // fgets(buf, BUFLEN, stdin);
    scanf("%s", buf);
    ret = isInt(buf);
    printf("%s is %s\n", buf, ret ? "Int":"Not Int");
    return 0;
}

// int isInt(char * buf){
//     int stat;

//     stat = STAT_ENTRY;
//     while(*buf != 0 && *buf != ';'){
//         if(*buf >= '9' || *buf <='0'){
//             stat = STAT_OTHER;
//             break;
//         }
//         buf++;
//     }

//     if(stat == STAT_ENTRY)
//         return TRUE;
//     return FALSE;
// }
