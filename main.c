/*
 * Serial program for linked list
 */

#include <stdio.h>
#include <stdlib.h>

long MAX_VAL= 65536;

struct node {
    int value;
    struct node *next;
};
int main() {

    int num_nodes;
    struct node *head = NULL;

    printf( "number of nodes for the linked list :");
    scanf("%d", &num_nodes );

    //generate linked list
    int i=0;
    while(i<num_nodes){
        long val=rand()%MAX_VAL;
        if(insert(val,&head)){
            i++;
        }
    }


    return 0;
}


int insert(int value, struct node **head_p) {

    struct node *current_p = *head_p;
    struct node *pedecessor_p = NULL;
    struct node *temp_p = NULL;

    /**At end of this while loop;
     * predecessor_p = predecessor of new node to be added
     * current_p= next node of the new node to be added
    */
    while (current_p != NULL && current_p->value < value) {
        pedecessor_p = current_p;
        current_p = current_p->next;
    }

    //new node with the value and link it.
    if (current_p == NULL || current_p->value > value) {
        temp_p = malloc(sizeof(struct node)); //create new node
        temp_p->value = value;
        temp_p->next = current_p;

        if (pedecessor_p == NULL)
            *head_p = temp_p;
        else
            pedecessor_p->next = temp_p;

        return 1;
    }
    else
        return 0;
}