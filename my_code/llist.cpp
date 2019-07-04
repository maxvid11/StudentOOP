#include <iostream>
#include "llist.h"

using namespace std;


ostream& operator<<(ostream& os, const Node* nd) {
    os << nd->data << "\t";
    return os;
}


void add_at_end(Node*& head, int d) {
    if (!head->next){
        head->next = new Node(d);
    }
    else{
        add_at_end(head->next, d);
    }
}



void print_list(ostream& os, const Node* head) {
    if(head == nullptr){
        os << "The List is Empty" << endl;;
        return;
    }
    os << head->data;
    if(head->next != nullptr){
        os << " -> ";
        print_list(os, head->next);
    }
    os << endl;
}



void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}



bool del_head(Node*& head) {
    if(!head){
        return false;
    }
    else{
        Node* old_head = head;
        head = head->next;
        delete old_head;
        return true;
    }
}



bool del_tail(Node*& curr) {
    if(!curr){
        return false;
    }
    else{
        if(curr->next == nullptr){
            delete curr;
            curr = nullptr;
            return true;
        }
        else{
            return del_tail(curr->next);
        }
    }
}



Node* reverse(Node* curr, Node* new_next){
    if(!curr){
        return new_next;
    }
    else{
        return reverse(curr->next, new Node(curr->data, new_next));
    }
}


Node* duplicate(Node* head){
    if (!head){
        return head;
    }
    else {
        Node* new_head = new Node(head->data, duplicate(head->next));
        return new_head;
    }
}


Node* join(Node*& list1, Node* list2) {
    Node* lastNode = last(list1);
    lastNode -> next = list2;
    return list1;
}


Node* last(Node* head) {
    if (!head->next){
        return head;
    }
    else{
        return last(head->next);
    }
}
