#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Car {
    string model;
    int max_speed;
    int fuel;
    int consumption;
};


struct TListItem{
    Car value;
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

Car getValue(const TListIterator &it){
    if(isValid(it)){
        return it.pointer->value;
    }
    return Car();
}

void setValue(const TListIterator &it, Car newValue){
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

void addListItem(TList &list, Car value){
    if(list.first == NULL){
        list.first = new TListItem;
        list.first->value = value;
        list.first->next = NULL;
        list.first->prev = NULL;
        list.last = list.first;
    }else{
        TListItem* newItem = new TListItem;
        newItem->value = value;
        newItem->next = NULL;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
    }
    
}

void destroyList(TList &list){
    TListItem* itemToDelete = list.first;
    TListItem* tmp;
    while( itemToDelete != NULL){
        tmp = itemToDelete->next;
        delete itemToDelete;
        itemToDelete = tmp;
    }
    list.first = NULL;
    list.last = NULL;
}


int main()
{

    Car lada_proira, bmw_x5, lamborgini, bugatti;

    lada_proira.model = "Lada Priora 2002";
    lada_proira.max_speed = 100;
    lada_proira.consumption = 15;
    lada_proira.fuel = 25;

    bmw_x5.model = "BMW X5";
    bmw_x5.max_speed = 280;
    bmw_x5.consumption = 5;
    bmw_x5.fuel = 40;

    lamborgini.model = "Lamborgini";
    lamborgini.max_speed = 380;
    lamborgini.consumption = 20;
    lamborgini.fuel = 100;

    bugatti.model = "Bugatti Veyron";
    bugatti.max_speed = 407;
    bugatti.consumption = 35;
    bugatti.fuel = 200;

    TList cars = initList();

    addListItem(cars, lada_proira);
    addListItem(cars, bmw_x5);
    addListItem(cars, lamborgini);
    addListItem(cars, bugatti);

    float t;
    std::cin >> t;

    float max_dist = 0;
    string model;
    
    TListItem *current = cars.first;
    while (current != NULL) {
        Car car = current->value;
        float max_possible_dist = (float)car.fuel / car.consumption * 100; 
                                                                          
        float dist = t * car.max_speed;   

        dist = dist > max_possible_dist ? max_possible_dist : dist;

        if (dist > max_dist) {
            max_dist = dist;
            model = car.model;
        }

        current = current->next;
    }

    std::cout << "За заданний час далі проїде " << model << " (" << max_dist << "km)" << std::endl;

    destroyList(cars);

    return 0;
}
