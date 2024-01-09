/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp = *head;

    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

void insertBegining(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));

    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}

// delete the selected task from the list
void delete(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        //printf("1name %s\n", task->name);
        //printf("2name %s\n", temp->task->name);
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            //printf("3name %s\n", task->name);
            //printf("4name %s\n", temp->task->name);
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
struct node* traverseSJF(struct node *head) {
    struct node *temp = malloc(sizeof(struct node));
    struct node *returnNode;
    temp = head;
    returnNode = head;
    //printf("error 2\n");
    while (temp != NULL) {
        //printf("error 3\n");
        if(temp->task->burst < returnNode->task->burst) {
            returnNode = temp;
            //printf("error 4\n");
        }
        else {
            //insert(&temp, temp->task);
            //printf("error 5\n");
        }
        temp = temp->next;
        

    }
    return returnNode;
    //printf("error 6\n");
}

struct node* traversePriority(struct node *head) {
    struct node *temp = malloc(sizeof(struct node));
    struct node *returnNode;
    temp = head;
    returnNode = head;
    //printf("error 2\n");
    while (temp != NULL) {
        //printf("error 3\n");
        if(temp->task->priority > returnNode->task->priority && temp->task->priority < 11 && temp->task->priority > 0) {
            returnNode = temp;
            //printf("error 4\n");
        }
        else {
            //insert(&temp, temp->task);
            //printf("error 5\n");
        }
        temp = temp->next;
        

    }
    return returnNode;
    //printf("error 6\n");
}

// traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}

void traverseInsert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp = *head;    

    newNode->task = newTask;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        while (strcmp(newTask->name,temp->task->name) != 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


// traverse the list
struct node* traverseFind(struct node *head, Task *newTask) {
    struct node *temp;
    temp = head;
    // if(temp->task->name != NULL) {
    //     traverse(head);
    // }
    while (!strcmp(temp->task->name, newTask->name) == 0) {
        //printf("error 12\n");
        // printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
    // printf("error 13\n");
    return temp;
}


int traversePriorityRR(struct node *head) {
    struct node *temp = malloc(sizeof(struct node));
    struct node *returnNode;
    temp = head;
    returnNode = head;
    int max = 0;
    int countMax = 0;
    //printf("error 2\n");
    while (temp != NULL) {
        //printf("error 3\n");
        // if(temp->task->priority > returnNode->task->priority) {
        //     returnNode = temp;
        //     //printf("error 4\n");
        // }
        if(temp->task->priority > max) {
            max = temp->task->priority;
            //printf("error 4\n");
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (temp->task->priority == max) {
            ++ countMax;
        }
        temp = temp->next;
    }
    return countMax;
    //printf("error 6\n");
}