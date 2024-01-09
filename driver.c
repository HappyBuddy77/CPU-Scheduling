/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include <errno.h>

#define SIZE    100

int main(int argc, char *argv[])
{
    //printf("error -1\n");
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    //printf("error -2\n");
    in = fopen(argv[1],"r");
    
    //printf("[%d]\n", errno);
    while (fgets(task,SIZE,in) != NULL) {
        //printf("error -3\n");
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));
        //printf("error -4\n");
        // add the task to the scheduler's list of tasks
        add(name,priority,burst);
        //printf("error -5\n");
        free(temp);
    }

    fclose(in);
    //printf("error -6\n");
    // invoke the scheduler
    schedule();

    return 0;
}
