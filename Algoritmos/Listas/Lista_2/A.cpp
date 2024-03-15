#include <iostream>

using namespace std;  //ta usando biblioteca de lista , fazer sem a biblioteca de lista
#define MAX 100000

typedef struct node{
    char item;
    struct node* next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
    Node *curr;
    int size;
}List;
Node *createNode(char element, Node *next){
    Node *n = new Node;
    n->item = element;
    n->next = next;
    return n;
}
Node *createNode(Node* next){
    Node *n = new Node;
    n->next = next;
    return n;
}

List* createList(){
    List *l = new List;
    l->curr =l->head=l->tail=createNode(NULL);
    l->size = 0;
    return l;
}
void clear(List *l){
    Node *tmp = l->head;
    Node *next;
    while(tmp->next!=NULL){
        next = tmp->next;
        delete(tmp);
        tmp = next;
    }
    delete tmp;
    delete l;
}
void insert(List *l, char item){
    l->curr->next = createNode(item, l->curr->next);
    if(l->curr == l->tail){
        l->tail = l->curr->next;
    }
    l->size++;
    l->curr=l->curr->next;
}
void moveToStart(List *l){
    l->curr = l->head;
}
void moveToEnd(List *l){
    l->curr = l->tail;
}
void printList(const List *l){
    if(l->size>0 && l!=NULL){
        Node *tmp = l->head;
        while(tmp!=NULL){
            cout << tmp->next->item;
            tmp = tmp->next;
        }
    }
    cout<<endl;
}
int main(){
    char c;
    while(cin>>c){
        List *list=createList();
            while(c!='\n'){
                if(c=='['){
                    moveToStart(list);
                }
                else if(c==']'){
                    moveToEnd(list);
                }
                else{
                    insert(list,c);
                }
                cin>>c;
            }
            printList(list);
            clear(list);
    }
}