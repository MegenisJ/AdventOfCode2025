#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int getNextValue(int startingpos,int move){
    int simplifiedmove = move % 100;
    int next = startingpos + simplifiedmove;
    if(next > 99){
        next = next - 100;
    }
    if(next < 0){
        next = next + 100;
    }
    return next;
}

int interpretMove(char* move){
    char* end;
    long magnitude = strtol(&move[1], &end,10);
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
        //printf("The next move is %d\n",move);
        pos = getNextValue(pos, interpretMove(line));
        //printf("The dial is pointing at %d\n",pos);
        if(pos == 0){
            countZero++;
        }
    } 
    
    printf("%d\n",countZero);

    return countZero;
}
