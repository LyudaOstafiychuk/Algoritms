#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define RAD2DEG 180 / M_PI

using namespace std;

struct Point {
    float x, y;
};

struct TListItem{
    Point value;
    TListItem *next, *prev;
};

struct TList{
    TListItem *first, *last;

};

struct TListIterator{
    TListItem* pointer;
};

TListIterator initTListIterator(){
    TListIterator tmp;
    tmp.pointer = NULL;
    return tmp;
}

int isValid(TListIterator it){
    return it.pointer != NULL;
}

void moveNext(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->next;
    }
    return;
}

void movePrev(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->prev;
    }
    return;
}

Point getValue(const TListIterator &it){
    if(isValid(it)){
        return it.pointer->value;
    }
}

void setValue(const TListIterator &it, Point newValue){
    if(isValid(it)){
        it.pointer->value = newValue;
    }
    return;
}

TListIterator getBegin(TList l){
    TListIterator tmp;
    tmp.pointer = l.first;
    return tmp;
}

TListIterator getEnd(TList l){
    TListIterator tmp;
    tmp.pointer = l.last;
    return tmp;
}

void deleteListItem(TList &l, TListIterator &it){
    if(!isValid(it)){
        return;
    }
    if(it.pointer == l.first){
        l.first = it.pointer->next;
    }
    if(it.pointer == l.last){
        l.last = it.pointer->prev;
    }
    TListItem* next = it.pointer->next;
    TListItem* prev = it.pointer->prev;
    delete it.pointer;
    it.pointer = next;
    if (prev != NULL)
    {
        prev->next = next;
    }
    if(next != NULL){
        next->prev = prev;
    }
    if(l.first == NULL){
        l.last = NULL;
    }
    if (l.last == NULL){
        l.first = NULL;
    }
    return;
    
}

TList initList(){
    TList l;
    l.first = NULL;
    l.last = NULL;
    return l;
}

void addListItem(TList &list, Point value){
    if(list.first == NULL){
        list.first = new TListItem;
        list.first->value = value;
        list.first->next = list.last;
        list.first->prev = list.first;
        list.last = list.first;
    }else{
        TListItem* newItem = new TListItem;
        newItem->value = value;
        newItem->next = list.first;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
        list.first->prev = list.last;
    }
    
}

void destroyList(TList &list){
    TListItem* itemToDelete = list.first;
    TListItem* tmp;
    do{
        tmp = itemToDelete->next;
        delete itemToDelete;
        itemToDelete = tmp;
    }while(itemToDelete != list.first);

    list.first = NULL;
    list.last = NULL;
}


int main()
{

    TList list = initList();

    Point p1, p2, p3, p4;
    p1.x = 10;
    p1.y = 10;

    p2.x = 10;
    p2.y = -10;

    p3.x = -10;
    p3.y = -10;

    p4.x = -10;
    p4.y = 10;

    addListItem(list, p1);
    addListItem(list, p2);
    addListItem(list, p3);
    addListItem(list, p4);

    TListIterator it = getBegin(list);
    if (isValid(it)){
        do {

            Point current_point = getValue(it);
            cout << current_point.x << " " << current_point.y << ": ";
            moveNext(it);
            Point next_dot = getValue(it);
            movePrev(it);
            movePrev(it);
            Point prev_dot = getValue(it);
            moveNext(it);
            float angle1 = atan2(prev_dot.x - current_point.x, prev_dot.y - current_point.y) * RAD2DEG;
            if (angle1 <= 0)
                angle1 += 360;
            
            float angle2 = atan2(next_dot.x - current_point.x, next_dot.y - current_point.y) * RAD2DEG;
            if (angle2 <= 0)
                angle2 += 360;


            float angle = abs(angle1 - angle2);
            angle = angle > 180 ? 360 - angle : angle;

            cout << angle << endl;

            moveNext(it);
        } while (it.pointer != list.first);
    } 

    return 0;
}
