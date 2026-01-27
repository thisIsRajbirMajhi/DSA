
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}node;

node *head = NULL;

void display(){
    if(head == NULL) return;
    node *temp = head;
    while(temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node *create_node(int value){
    node *newNode = (node *)malloc(sizeof(node));
    if(!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;   
}

void insert_beginning(int value){
    node *newNode = create_node(value);
    if(!newNode) exit(1);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head; 
    head = newNode;
}

void insert_end(int value){
    node *newNode = create_node(value);;
    if(!newNode) exit(1);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_position(int value, int position){
    // if position is negative
    if(position < 0) return;
    // insert at beginning or empty list
    if(position == 0 || head == NULL){
        insert_beginning(value);
        return;
    }
    node *newNode = create_node(value);
    if(!newNode) exit(1);
    node *temp = head;
    int i = 0;
    // move untile the correct position is reached
    while(temp != NULL && i < position - 1){
        temp = temp->next;
        i++;
    }
    // if position is out of bounds
    if(temp == NULL){
        free(newNode);
        return;
    }
    // after position is reached
    newNode->next = temp->next; // points new node to the node that was at position
    temp->next = newNode; // link previous node to new node
}

void insert_after(int value, int target){
    node *temp = head;
    while(temp != NULL && temp->data != target){
        temp = temp->next;
    }
    if(temp == NULL){
        return;        
    }
    node *newNode = create_node(value);
    if(!newNode) exit(1);
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_beginning(){
    if(head == NULL) return;
    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end(){
    if(head == NULL) return;
    // if one node exists
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    // traverse to the end
    node *temp = head;
    node *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_position(int pos){
    if(head == NULL || pos < 0) return;
    if(pos == 0){
        delete_beginning(); 
        return;
    }
    node *current = head; 
    node *previous = NULL;
    for(int i = 0; i < pos && current != NULL; i++){
        previous = current;
        current = current->next;
    }
    if(current == NULL) return;
    previous->next = current->next;
    free(current);
}

// returns position
int linear_search(int value){
    if(head == NULL) return;
    node *temp = head;
    int pos = 0;
    while(temp != NULL){
        if(temp->data == value){
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

// returns node itself
node *search_node(int value){
    node *temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Merge by simple concat (append list 2 at end of list1)
node *merge_concat(node *head1, node *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    node *temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

// Merge two sorted lists
/*
    --> Look at the first element of both lists
    --> Whoever is smaller goes into the new merged list
    --> Move forward in that list
    --> Again comapre the two new fronts
    --> Pick the smaller one
    --> Repeat this intil one list becomes empty
    --> Finally attach whatever is left from the non empty list
*/
node *merge_sorted(node *head1, node *head2){
    // handle empty lists
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    node *result = NULL;
    // comapre front element of both lists
    if(head1->data < head2->data){
        result = head1;
        head1 = head1->next;
    }
    else {
        result = head2;
        head2 = head2->next;
    }

    // points to the last node of the merged list
    node *tail = result;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            tail->next = head1; // attach smaller node
            head1 = head1->next; // move forward
        }
        else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // attach remaining nodes
    if(head1 != NULL){
        tail->next = head1;
    }
    else {
        tail->next = head2;
    }
    return result;
}

void update_value(int oldValue, int newValue){
    node *temp = head;
    while(temp != NULL){
        if(temp->data == oldValue){
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    }
}

void update_position(int pos, int value){
    if(pos < 0) return;
    node *temp = head;
    int i = 0;
    while(temp != NULL & i < pos){
        temp = temp->next;
        i++;
    }
    if(temp == NULL) return;
    temp->data = value;
}

int main(){

    return 0;
}