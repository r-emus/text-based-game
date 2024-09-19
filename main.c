#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static char INPUT[16] = "Look around";

struct object{
    int id;
    char *name;
    char *desc;
    struct object *location;
};
struct object objs[] = {
    {0, "NOWHERE", "EVERYWHERE.", NULL},
    {1, "MYSELF", "YOURSELF.", &objs[0]},
    {2, "SOMEWHERE", "A PLACE?", NULL}
};

int totalobjs = sizeof(objs)/sizeof(objs[0]);

bool prompt(){
    printf("\n--> ");
    return fgets(INPUT, sizeof(INPUT), stdin) != NULL;
}

void action_look(char *target){
    if(strcmp(target, "AROUND") == 0){
                printf("You are %s.", objs[1].location->name);
            }
            else{
                for(int i = 0; i < totalobjs; i++){
                    if(strcmp(target, objs[i].name) == 0){
                        printf("%s", objs[i].desc);
                    }
                }
            }
}

void action_move(char *target){
    if(strcmp(target, objs[1].location->name) == 0){
        printf("Already there.");
    }
    else{
        for(int i = 0; i < totalobjs; i++){
            if(strcmp(target, objs[i].name) == 0){
                printf("Moving to %s", objs[i].name);
                objs[1].location = &objs[i];
            }
        }
    }
}
bool outcome(char *INPUT){
    char *action = strtok(INPUT, " \n");
    char *target = strtok(NULL, " \n");
    if(action != NULL){
        if(strcmp(action, "quit") == 0){
            return false;
        }
        if(strcmp(action, "look") == 0){
            action_look(target);
        }
        if(strcmp(action, "move") == 0){
            action_move(target);
        }
    }
    return true;
}

int main(){
    printf("WELCOME.\n");
    while(prompt()&&outcome(INPUT));
    printf("BYE.\n");
}