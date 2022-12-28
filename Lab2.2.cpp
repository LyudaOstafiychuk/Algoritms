#include <iostream>

using namespace std;

struct Node {
    char value;
    Node *next;
};

bool isEmpty(Node *stack){
    return (stack == NULL);
}

void push(Node* &stack, char value){
    if (isEmpty(stack)) {
        stack = new Node;
        stack->value = value;
        stack->next = NULL;
    } else {
        Node *current = stack;
        stack = new Node;
        stack->value = value;
        stack->next = current;
    }
}

char pop(Node *&stack){
    if(isEmpty(stack)){
        return '\0';
    }else{
        char tmp = stack->value;
        Node *next = stack->next;
        delete stack;
        stack = next;
        return tmp;
    }
}

void print(const Node *stack) {
    
    while (stack) 
    {
        cout << stack->value << " ";
        stack = stack->next;
    }
    cout << endl;
}
void destroyStack(Node *stack){
    if(!isEmpty(stack)){
        destroyStack(stack->next);
        delete stack;
        stack = NULL;
    }
}

int main(){
    
    Node *stack = NULL;
    
    int n;
    cout << "Кількість літер у стеці: ";
    cin >> n;

    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        push(stack, ch);
    }

    print(stack);
    cout << endl;

    char charToLook;
    cout << "Яку літеру шукати?" << endl;
    cin >> charToLook;

    int count = 0;
    while (!isEmpty(stack)) {
        ch = pop(stack);
        if (ch == charToLook) {
            count++;
        }
    }

    cout << "Літера " << charToLook << " попалась " << count << " раз.";

    return 0;
}