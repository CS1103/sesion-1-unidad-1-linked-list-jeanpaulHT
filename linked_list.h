//
// Created by Jean on 11/04/2020.
//

#ifndef WEEK_2_LINKED_LIST_H
#define WEEK_2_LINKED_LIST_H


namespace utec {
    template <typename T>
    struct node {
        T data = {};
        node *next = nullptr;
    };

    inline namespace first{
        template <typename T>
        class linked_list_t {
        private:
            utec::node<T> *head = nullptr;
            utec::node<T> *tail = nullptr;
            int size = {};
        public:
            //constructor
            linked_list_t() = default;
            linked_list_t (const linked_list_t& other);
            linked_list_t &operator =(const linked_list_t &other);
            linked_list_t (linked_list_t&& other) noexcept ;
            linked_list_t &operator =(linked_list_t&& other) noexcept ;

            //destructor
            ~linked_list_t();

            //add operations
            void push_front(T item);
            void push_back(T item);
            void insert(int index, T item);

            //remove operations
            void pop_front();
            void pop_back();
            void erase(int index);

            //transversal
            void transverse_list();
            T &item(int index);
            const T&item(int index) const;

            //get size
            int get_size();
        };
    }
}

#endif //WEEK_2_LINKED_LIST_H
