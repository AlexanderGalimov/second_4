#include <iostream>

using namespace std;

struct node {
    int value;
    node* next;

    node(int x) : value(x), next(nullptr) {}

    int getValue(){
        return this->value;
    }
    void setValue(int newValue){
        this->value = newValue;
    }

};

struct list {
    node* first;
    int size = 0;

    list() : first(nullptr) {
    }

    int getSize(){
        return size;
    }

    void addFirst(node* n) {
        n->next = first;
        first = n;
        size++;
    }

    void addLast(node* n) {
        if (first == nullptr) {
            first = n;
            return;
        }
        node* t = first;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = n;
        size++;
    }

    void addByIndex(node* n,int index){
        if(index < 0 || index > size - 1){
            cout << "index not correct" << endl;
            return;
        }
        if(index == 0){
            addFirst(n);
            return;
        }
        if(index == size - 1){
            addLast(n);
            return;
        }
        int cnt = 0;
        node* curr = first;
        node* temp;
        size++;
        while(true){
            if(cnt == index - 2){
                temp = curr->next;
                curr->next = n;
                n->next = temp;
                return;
            }
            curr = curr->next;
            cnt++;
        }
    }

    void deleteFirst(){

        node* old_head = first;

        first = first->next;

        delete old_head;
        size--;
    }

    void deleteByIndex(int index){
        if(index < 0 || index > size - 1){
            cout << "index not correct" << endl;
            return;
        }
        node* curr = first;
        int cnt = 0;
        while (cnt != index - 2) {
            curr = curr->next;
            cnt++;
        }
        node* nodeToDel = curr->next;
        curr->next = curr->next->next;
        delete nodeToDel;
        size--;
    }

    void display() {
        node* t = first;
        cout << "list: ";
        while (t) {
            cout << t->value << " ";
            t = t->next;
        }
    }
};

int main()
{
    list* l = new list();

    l->addLast(new node(1));

    l->addFirst(new node(2));

    l->addFirst(new node(3));

    l->addFirst(new node(4));

    l->addFirst(new node(5));

    // 5 4 3 2 1
    // 5 4 3 2 1 10
    // 5 3 2 1 10

    l->addByIndex(new node(10),l->getSize() - 1);

    l->deleteByIndex(2);

    l->display();

    delete l;

    return 0;
}
