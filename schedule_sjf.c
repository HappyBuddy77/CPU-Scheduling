#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "schedulers.h"
#include "task.h"
#include "list.h"
#include <string.h>

struct node *head = NULL;
int counter = 0;

struct node* pickNextTask(struct node **currentNode) {
    //printf("error 11\n");
    struct node *newNode = traverseSJF(*currentNode);
    //printf("error 12\n");
    if (newNode != NULL && (newNode)->task != NULL) {
        struct node *temp = newNode;
        run((newNode)->task, (newNode)->task->burst);
        return temp;
    }
}

void add(char *name, int priority, int burst) {
    //printf("error 1\n");
    struct task *newTask = malloc(sizeof(struct task));
    
    newTask->name = name;
    //printf("name %s\n", newTask->name);
    
    newTask->tid = counter;
    //printf("name %d\n", newTask->tid);
    
    newTask->priority = priority;
    //printf("name %d\n", newTask->priority);
    
    newTask->burst = burst;
    //printf("name %d\n", newTask->burst);

    //printf("error 5\n");
    insert(&head, newTask);

    //printf("error 6\n");
    ++counter;

}
// this is  comment
void schedule() {

    float  waiting;
    float  turnaround;
    float  response;
    int tempWait;
    int tempTurn;
    int tempResponse;
    
    waiting = 0;
    turnaround = 0;
    response = 0;
    tempWait = 0;
    tempTurn = 0;
    tempResponse = 0;

    while (head != NULL) {
        
        struct node *newNode = pickNextTask(&head);

        // if (newNode->next != NULL) {
            
            // waiting time
            tempWait += newNode->task->burst;
            waiting += tempWait;

            //response time
            tempResponse += newNode->task->burst;
            response += tempResponse;

            // turnaround time
            tempTurn += newNode->task->burst;
            turnaround += tempTurn;
            //printf("burst = %d\n", newNode->task->burst);
            //printf("turnaround TEMP = %d\n", tempWait);
            //printf("turnaround time = %.2f\n", waiting);

            // if(newNode->next->next == NULL) {
            // tempTurn += newNode->next->task->burst;
            // turnaround += tempTurn;
            // }
        // }

        if (strcmp(newNode->task->name,head->task->name) == 0) {
            //printf("error 2\n");
            delete(&newNode, newNode->task);
        }
        else {
            //printf("error 3\n");
            delete(&head, newNode->task);
            insertBegining(&head, head->task);
        }
        
        head = head->next;
        //traverse(head);
    }   

    waiting -= tempWait;
    response -= tempResponse;

    waiting = waiting / counter;
    turnaround = turnaround / counter;
    response = response / counter;

    printf("\nAverage waiting time = %.2f\n", waiting);
    printf("Average turnaround time = %.2f\n", turnaround);
    printf("Average response time = %.2f\n", response);

}