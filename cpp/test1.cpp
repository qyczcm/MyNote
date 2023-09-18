#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

void GetMemory(char *p){
    p = (char *)malloc(100);
}

void Test(){
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf(str);
}

int main(){
    Test();
    return 0;
}