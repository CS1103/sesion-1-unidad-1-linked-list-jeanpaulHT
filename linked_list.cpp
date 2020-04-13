//
// Created by Jean on 11/04/2020.
//

#include "linked_list.h"
#include <iostream>
using namespace std;

//Constructors
template <typename T>
utec::first::linked_list_t<T>::linked_list_t(const utec::linked_list_t<T> &other):
head(new node<T> {other.head->data,nullptr}), tail(new node<T> {other.tail->data, nullptr}), size(other.size) {
    auto temp = other.head->next;
    auto pivot = head;
    while(pivot != tail){
        if(temp == nullptr) break;
        pivot->next = new node<T> {temp->data, nullptr};
        pivot = pivot->next;
        temp = temp->next;
    }
}
template <typename T>
    utec::linked_list_t<T> &utec::first::linked_list_t<T>::operator=(const utec::linked_list_t<T> &other){
        if(this == &other) return *this; // si ambos son iguales regresar el mismo objeto

        delete this;

        auto index = other.size;
        while(index--) {
            push_front(other.item(index));
        }
        return *this;
    }

template<typename T>
utec::first::linked_list_t<T>::linked_list_t(utec::linked_list_t<T> &&other) noexcept: size(other.size),
head(move(other.head)), tail(move(other.tail)) {
    other.size = 0;
    other.head=other.tail= nullptr;
}

template <typename T>
utec::linked_list_t<T> &utec::first::linked_list_t<T>::operator=(utec::linked_list_t<T> &&other) noexcept{
    delete this;

    size = other.size;
    head = move(other.head);
    tail = move(other.tail);

    other.head=other.tail= nullptr;
    return *this;
}
template <typename T>
utec::first::linked_list_t<T>::~linked_list_t() {
    while (size != 0){
        pop_front();
    }
    tail = head = nullptr;
    size = 0;
}

// addition
template <typename T>
void utec::first::linked_list_t<T>::push_front(T item) {
    auto *temp = new node<T>{item, head};
    head = temp;
    if(tail == nullptr) tail = head;
    size++;
}
template <typename T>
void utec::first::linked_list_t<T>::push_back(T item) {
        auto *temp = new node<T>{item, nullptr};
        tail->next = temp;
        tail = temp;
        if (head == nullptr) head = tail;
        size++;
}
template <typename T>
void utec::first::linked_list_t<T>::insert(int index, T item) {
    size++;
    if(!index){
        head = new node<T>{item,head};
    }
    else if(index == size - 1){
        tail->next =new node<T>{item, nullptr};
        tail = tail->next;
    }
    else{
        auto temp = head;
        while(--index != 0)
            temp = temp->next;
        temp->next = new node<T>{item,temp->next};
    }
}


// Remover
template <typename T>
void utec::first::linked_list_t<T>::pop_front()  {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size = 0;
    }
    else {
        auto next = head->next;
        delete head;
        head = next;
        size--;
    }
}
template <typename T>
void utec::first::linked_list_t<T>::pop_back()  {
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        size = 0;
    }
    else {
        auto temp = head;
        while(temp->next != tail)
            temp = temp->next;
        temp->next = nullptr;
        delete tail;
        tail = temp;
        size--;
    }

}
template <typename T>
void utec::first::linked_list_t<T>::erase(int index) {
    node<T>* temp = head;
    size--;
    if(head == tail){
        delete head;
        delete tail;
        head=tail= nullptr;
        size = 0;
    }
    else if(!index){
        temp = temp->next;
        delete head;
        head = temp;
    }
    else{
        while(--index != 0){
            temp = temp->next;
        }
        cout<<temp->data<<endl;
        node<T>* pivot = temp->next;
        temp->next=pivot->next;
        delete pivot;
    }
}

//Transversal
template <typename T>
void utec::first::linked_list_t<T>::transverse_list() {
    node<T> *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
template <typename T>
T &utec::first::linked_list_t<T>::item(int index) {
    node<T>* temp = head;
    while(index-- != 0){
        temp = temp->next;
    }
    return temp->data;
}
template <typename T>
const T &utec::first::linked_list_t<T>::item(int index) const {
    node<T>* actual = head;
    while (index--)
        actual = actual->next;
    return actual->data;
}
template <typename T>
int utec::first::linked_list_t<T>::get_size() {
    return size;
}


