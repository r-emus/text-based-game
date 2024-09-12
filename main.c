#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static char INPUT[16] = "Look around";

bool prompt(){
    printf("--> \n");
    return fgets(INPUT, sizeof(INPUT), stdin) != NULL;
}

bool outcome(char *INPUT){
    char *action = strtok(INPUT, " \n");
//    char *target = strtok(NULL, " \n");
    if(action != NULL){
        if(strcmp(action, "quit") == 0){
            return false;
        }
        if(strcmp(action, "look") == 0){
            printf("Looked.");
        }
    }
    return true;
}

int main(){
    printf("WELCOME.\n");
    while(prompt()&&outcome(INPUT));
    printf("BYE.\n");
}