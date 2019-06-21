#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    os << nd->data << "\t";
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node * head, int d) {
    if (!head->next){
        head->next = new Node(d);
    }
    else{
        add_at_end(head->next, d);
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
    os << head;
    if (head->next) print_list(os, head->next);
    else os << endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (!head->next){
        return head;
    }
    else{
        return last(head->next);
    }
}
