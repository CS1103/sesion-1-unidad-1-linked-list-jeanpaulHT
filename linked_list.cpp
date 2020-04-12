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
        size = other.size; //asigno el size del other
        if(this == &other) return *this; // si ambos son iguales regresar el mismo objeto

        //recorriendo el linked list para eliminar todos los nodes
        auto temp = head; //para recorrer
        auto pivot = temp; // para eliminar
        while(temp != tail && !temp){
            pivot = temp;
            temp = temp->next;
            delete[] pivot;
        }
        delete []tail;// eliminando el tail ya que no fue eliminado en el while loop

        head = new node<T> {other.head->data, nullptr};// creando un nuevo head
        tail = new node<T> {other.tail->data, nullptr};// creando un nuevo tail

        //creando una nueva lista
        pivot = head; // para crear nodos en el list
        temp = other.head->next; // para recorrer el other

        //en el while loop sucede el segmentation fault
        while(temp != other.tail){
            pivot->next = new node<T> {temp->data, nullptr}; //esta linea, especificamente
            pivot = pivot->next;
            temp = temp->next;
        }
        return *this;
    }
template <typename T>
utec::first::linked_list_t<T>::linked_list_t(utec::linked_list_t<T> &&other) noexcept : size(other.size){
    if(this != nullptr)
        delete [] this;
    auto temp = other.head_pointer;
    auto pivot = head;
    head = (move(other.head));

    return *this;
}
template <typename T>
utec::linked_list_t<T> &utec::first::linked_list_t<T>::operator=(utec::linked_list_t<T> &&other) noexcept{
    return *this;
}
template <typename T>
utec::first::linked_list_t<T>::~linked_list_t() {
    auto temp = head;
    auto pivot = temp;
    while(temp != tail && !temp){
        pivot = temp;
        temp = temp->next;
        delete[] pivot;
    }
    delete []tail;
    tail = head = nullptr;
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
    if(head == nullptr) head = tail;
    size++;
}
template <typename T>
void utec::first::linked_list_t<T>::insert(int index, T item) {
    if(!index){
        head = new node<T>{item,head};
    }
    else{
        auto temp = head;
        while(--index != 0)
            temp = temp->next;
        temp->next = new node<T>{item,temp->next};
        size++;
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
        size--;
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