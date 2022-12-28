#include <iostream>

using namespace std;

struct TQueueElement
{
    int value;
    TQueueElement *next;
};

struct Queue
{
    TQueueElement *start;
    TQueueElement *end;
};

void init(Queue &q)
{
    q.start = NULL;
    q.end = NULL;
    return;
}

bool isEmpty(Queue q)
{
    return (q.start == NULL || q.end == NULL);
}

void push(Queue &q, int value)
{
    if (q.start == NULL)
    {
        TQueueElement *newQueueElement = new TQueueElement;
        newQueueElement->value = value;
        newQueueElement->next = NULL;

        q.start = newQueueElement;
        q.end = newQueueElement;

        return;
    }

    TQueueElement *newQueueElement = new TQueueElement;
    newQueueElement->value = value;
    newQueueElement->next = NULL;
    q.end->next = newQueueElement;
    q.end = newQueueElement;
    return;
}

int pop(Queue &q)
{

    if (isEmpty(q))
        return 0;

    if (q.start == q.end)
    {
        int valueToReturn = q.start->value;
        delete q.start;
        q.start = NULL;
        q.end = NULL;
        return valueToReturn;
    }
    else
    {
        int valueToReturn = q.start->value;
        TQueueElement *queueElement = q.start;
        q.start = q.start->next;
        delete queueElement;
        return valueToReturn;
    }
}

void destroyQueue(Queue &q)
{
    while (!isEmpty(q))
        pop(q);
}

void print(Queue q) {
    TQueueElement *current = q.start;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
}

int main() {

    Queue q;
    init(q);

    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    push(q, 10);
    push(q, -10);

    print(q);
    cout << endl;

    int product = 1;

    while (!isEmpty(q)) {
        product *= pop(q);
    }



    cout << "Product of all elements: " << product;

    return 0;
}
