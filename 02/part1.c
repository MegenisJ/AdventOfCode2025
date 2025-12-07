#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int isInvalid(long ID){
    char str[50];
    sprintf(str, "%ld",ID);
    int len = strlen(str);
    if(len % 2 != 0){ return 0;}
    int mid = len / 2;
    if(strncmp(str,str+mid,mid) == 0){
        return 1;
    }
    return 0;
}

long CountInvalidIdsInRange(long start, long finish){
    long countValid = 0;
    long i;
    for(i = start; i <= finish; ++i){
        if(isInvalid(i)){

            countValid += i;
        }
    } 
    printf("valid: %ld \n",countValid);
    return countValid;
}

int main(int argc, char * argv[]){
    long countValid = 0;
    FILE *fp = fopen(argv[1], "r");    
    assert(fp != NULL);
    char line[1000]; 
    fgets(line, sizeof(line), fp); 

    const char outer_delimiters[] = ",";
    const char inner_delimiters[] = "-";

    char* token;
    char* outer_saveptr = NULL;
    char* inner_saveptr = NULL;

    token = strtok_r(line, outer_delimiters, &outer_saveptr);

    while (token != NULL) {

        char* start = strtok_r(
                token, "-", &inner_saveptr);

        char* finish = strtok_r(NULL, "-",
                &inner_saveptr);
        char * end;
        countValid += CountInvalidIdsInRange(strtol(start, &end, 10),strtol(finish,&end,10));
        token = strtok_r(NULL, outer_delimiters,
                &outer_saveptr);
    }
    printf("%ld\n",countValid);
    return 0;
}
