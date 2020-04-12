#include <iostream>
#include "linked_list.cpp"
#include <cassert>
#include <string>

int main() {
    utec::linked_list_t<int> ll;

    for(int i = 1; i < 10; i++){
        ll.push_front(i);
    }
    assert(ll.get_size() == 9);

    std::string result = {};
    for(int i = 0; i < ll.get_size(); i++){
        result += std::to_string(ll.item(i)) + " ";
    }

    assert(result == "9 8 7 6 5 4 3 2 1 ");

     for(int i = 0; i < 5; i++){
        ll.pop_front();
     }
     result = {};

    for(int i = 0; i < ll.get_size();++i){
        result += std::to_string(ll.item(i)) + " ";
    }
    assert(result == "4 3 2 1 ");
    ll.pop_back();

    result = {};
    for(int i = 0; i < ll.get_size();++i){
        result += std::to_string(ll.item(i)) + " ";
    }
    assert(result == "4 3 2 ");
    ll.erase(0);
    ll.insert(2,5);
    utec::linked_list_t<int> A(ll);
    utec::linked_list_t<int> temp = ll;

    return 0;
}