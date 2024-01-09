#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int runTime;
    if ((*currentNode)->task->burst > 10) {
        runTime = 10;
    }
    else {
        runTime = (*currentNode)->task->burst;
    }

    //printf("%d\n", runTime);

    if (*currentNode != NULL && (*currentNode)->task != NULL) {
        struct node *temp = *currentNode;
        run((*currentNode)->task, runTime);
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
    int newList;
    int counterArray;

    waiting = 0;
    turnaround = 0;
    response = 0;
    tempWait = 0;
    tempTurn = 0;
    tempResponse = 0;
    newList = 0;
    counterArray = 0;

    //printf("error 1\n");
    struct node *newHead = NULL;
    
    //printf("error 2\n");
    struct node *tempHead = head;
    //printf("error 3\n");
    while (tempHead != NULL) {
        struct task *newTask = malloc(sizeof(struct task));
        //printf("error 4\n");
        newTask->name = tempHead->task->name;
        //printf("name %s\n", newTask->name);
        
        newTask->tid = tempHead->task->tid;
        //printf("name %d\n", newTask->tid);
        
        newTask->priority = tempHead->task->priority;
        //printf("name %d\n", newTask->priority);
        
        newTask->burst = tempHead->task->burst;
        //printf("error 5\n");
        insert(&newHead, newTask);
        ++ newList;
        //printf("error 6\n");
        tempHead = tempHead->next;
    }
    //traverse(newHead);

    char taskNames[newList][5];

    tempHead = head;
    //printf("error 3\n");
    while (tempHead != NULL) {
        
        strcpy(taskNames[counterArray], tempHead->task->name);
        tempHead = tempHead->next;
        ++ counterArray;
        // printf("error %s\n", taskNames[counterArray]);
    }
    //printf("error 7\n");
    while (head != NULL) {
        
        struct node *newNode = pickNextTask(&head);
        
        //if (newNode->next != NULL) {

            // waiting time
            // tempWait += newNode->task->burst;
            // waiting += tempWait;
            
            // turnaround time
            //tempTurn += newNode->next->task->burst;
            //turnaround += tempTurn;
            for (int i = 0; i < newList; ++i) {
                if(strcmp(taskNames[i], newNode->task->name) == 0) {
                    response += tempResponse;
                    //printf("%s = %f\n", taskNames[i], response);
                    strcpy(taskNames[i], "NULL"); 
                }
                
            }
            
            //response += tempResponse;
            //printf("turnaround time = %.2f\n", turnaround);

            if (newNode->task->burst < 11) {
                // printf("error 2\n");
                // printf("%d %f\n", tempWait, waiting);
                //delete(&newNode, newNode->task);
                tempResponse += newNode->task->burst;

                struct node *findNode = traverseFind(newHead, newNode->task);
                // printf("error 2\n");
                tempTurn += newNode->task->burst;
                turnaround += tempTurn;
                waiting += tempTurn - findNode->task->burst;
                // printf("%s %f\n", newNode->task->name, turnaround);
            }
            else {
                //printf("error 3\n");
                tempTurn += 10;
                tempResponse += 10;
                // printf("%s %d\n", newNode->task->name, tempWait);
                newNode->task->burst = newNode->task->burst - 10;
                insert(&head, newNode->task);
                //delete(&head, newNode->task);
            }

        //}
        
        head = head->next;
        ++ counterArray;
    }

    waiting = waiting / counter;
    turnaround = turnaround / counter;
    response = response / counter;

    printf("\nAverage waiting time = %.2f\n", waiting);
    printf("Average turnaround time = %.2f\n", turnaround);
    printf("Average response time = %.2f\n", response);

}