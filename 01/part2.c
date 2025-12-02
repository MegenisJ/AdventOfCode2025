#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int interpretMove(char* move){
    char* end;
    long magnitude = strtol(&move[1], &end,10);
    magnitude = magnitude;
    if(move[0] == 'L'){
        return -magnitude;
    }        
    return magnitude;
}

int main(int argc, char * argv[]){
    FILE *fp = fopen(argv[1], "r");    
    assert(fp != NULL);
    char line[256]; 
    int pos = 50;   //starting position = 50
    int countZero = 0;
    while (fgets(line, sizeof(line), fp)) { 

        int move = interpretMove(line); 
        countZero += abs(move)/100;
        move = move %100;
        int next = pos + move;

        if(next > 99){
            next = next - 100;
            countZero++;
        }
        if(next < 0){
            next = next + 100;
            countZero++;
        }

        pos = next;
        printf("position %d",pos);
        //if(pos == 0){
        //    countZero++;
        //}
    } 
    
    printf("%d\n",countZero);

    return countZero;
}
