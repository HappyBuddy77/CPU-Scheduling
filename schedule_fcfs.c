#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "schedulers.h"
#include "task.h"
#include "list.h"

struct node *head = NULL;
int counter = 0;

struct node* pickNextTask(struct node **currentNode) {
    //printf("error 9\n");
    //printf("%d\n", (*head)->task->tid);
    //printf("%d\n", (*head)->task->priority);
    //printf("%d\n", (*head)->task->burst);
    if (*currentNode != NULL && (*currentNode)->task != NULL) {
        struct node *temp = *currentNode;
        run((*currentNode)->task, (*currentNode)->task->burst);
        return temp;
    }

    // struct node temp = **currentNode;
    // run((*currentNode)->task, (*currentNode)->task->burst);
    // return temp;
    //printf("error 10\n");
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
    turnaround = head->task->burst;
    response = 0;
    tempWait = 0;
    tempTurn = head->task->burst;
    tempResponse = 0;


    //printf("error 7\n");
    while (head != NULL) {
        
        struct node *newNode = pickNextTask(&head);
        if (newNode->next != NULL) {

            // waiting time
            tempWait += newNode->task->burst;
            waiting += tempWait;

            // turnaround time
            tempTurn += newNode->next->task->burst;
            turnaround += tempTurn;

            tempResponse += newNode->task->burst;
            response += tempResponse;
            //printf("turnaround time = %.2f\n", turnaround);
        }
        
        head = newNode->next;
    }   
    waiting = waiting / counter;
    turnaround = turnaround / counter;
    response = response / counter;

    printf("\nAverage waiting time = %.2f\n", waiting);
    printf("Average turnaround time = %.2f\n", turnaround);
    printf("Average response time = %.2f\n", response);

}