#include <iostream> //not made by me
using namespace std;

typedef struct node{
    char element;
    struct node *next;
}Node;

typedef struct{
    Node *top;
    int size;
}Stack;

Node *createNode(char item, Node *next){
    Node *n =new Node;
    n->element = item;
    n->next = next;
    return n;
}
Stack *createStack(){
    Stack *s = new Stack;
    s->top = NULL;
    s->size = 0;
    return s;
}
void push(Stack *s, char item){
    s->top = createNode(item, s->top);
    s->size++;
}
void pop(Stack *s){
        Node *tmp = s->top;
        s->top = s->top->next;
        s->size--;
        delete(tmp);
}
void clear(Stack *s){
    for(int i=0;i<s->size;i++){
        pop(s);
    }
    delete(s->top);
    delete(s);
}
void printStack(Stack *s){
    Node *tmp = s->top;
    char text[s->size];
    int i=s->size;
    while(tmp!=NULL){
        i--;
        text[i-1] = tmp->element;
        tmp = tmp->next;
    }
    for(int i=0;i<s->size;i++){
        cout << text[i];
    }
}
int main(){
    char c;
    Stack *stack=createStack();
    while(cin>>c){
        push(stack,c);
        if(stack->size>=3 && stack->top->element=='C' && stack->top->next->element=='B' && stack->top->next->next->element=='A'){
            pop(stack);
            pop(stack);
            pop(stack);
        }
    }
    if(stack->size>0){
        printStack(stack);
    }
    clear(stack);
}