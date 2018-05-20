#include "automaton_head.h"

int isInt(char *);
int isFloat(char *);
int isChar(char *, int);
int isName(char *);

int isInt(char * buf){
    int stat;

    stat = STAT_ENTRY;
    while(*buf != 0 && *buf != ';'){
        if(*buf >= '9' || *buf <='0'){
            stat = STAT_OTHER;
            break;
        }
        buf++;
    }

    if(stat == STAT_ENTRY)
        return TRUE;
    return FALSE;
}

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
