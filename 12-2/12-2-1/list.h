#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
class Node {
    public:
    T data;
    Node<T> *next;
};

template <class T>
class List {
    private:
    Node<T> *head;
    public:
    List() : head(NULL) {
    };
    ~List(); //free resources
    List(T *arr, int n_nodes); //create a list with n_nodes
    void insert_at(int idx, const T &data);
    void remove_at(int idx);
    void pop_back();
    void push_back(const T &val);
    void pop_front();
    void push_front(const T &val);

    friend ostream &operator<<(ostream &out, List<T> &rhs) {
        Node<T> *tmp = rhs.head;

        out << tmp->data;

        while(tmp->next) {
            out << ','<< tmp->next->data;
            tmp = tmp->next;
        }

        return out;
    } //print out nodes
};

template <class T>
List<T>::~List() {
    Node<T> *next = head;
    Node<T> *cur = NULL;

    while(next != NULL) {
        cur = next;
        next = next->next;
        delete cur;
    }
    delete next;
}

template <class T>
List<T>::List(T *arr, int n_nodes) {
    head = new Node<T>;
    Node<T> *now = this->head;

    for(int i = 0; i < n_nodes - 1; i++) {
        now->data = arr[i];
        now->next = new Node<T>;
        now = now->next;
    }

    now->data = arr[n_nodes - 1];
    now->next = NULL;
}

template <class T>
void List<T>::insert_at(int idx, const T &data) {
    Node<T> *node = this->head;
    int cur = 0;

    for(int i = 0; i < idx - 1; i++) {
        node = node->next;
    }

    Node<T> *tmp = new Node<T>;

    tmp->data = data;
    tmp->next = node->next;
    node->next = tmp;
}

template <class T>
void List<T>::remove_at(int idx) {
    Node<T> *node = this->head;

    for(int i=0;i<idx-1;i++) {
        node = node->next;
    }

    Node<T> *tmp = node->next;

    node->next = tmp->next;

    delete tmp;
}

template <class T>
void List<T>::pop_back() {
    Node<T> *node = this->head;

    if(node == NULL) delete this->head;

    else {
        while(node->next->next) node = node->next;

        delete node->next;
        node->next = NULL;
    }
}

template <class T>
void List<T>::push_back(const T &val) {
    Node<T> *node = this->head;

    if(node == NULL) {
        node = new Node<T>;
        node->data = val;
        node->next = NULL;
        this->head = node;
    }

    else {
        while(node->next) node = node->next;
        node->next = new Node<T>;
        node->next->data = val;
        node->next->next = NULL;
    }
}

template <class T>
void List<T>::pop_front() {
    if(this->head == NULL) return;

    Node<T> *tmp = this->head;
    this->head = this->head->next;

    delete tmp;
}

template <class T>
void List<T>::push_front(const T &val) {
    Node<T> *node = new Node<T>;

    if(this->head == NULL) {
        node = new Node<T>;
        node->data = val;
        node->next = NULL;
        this->head = node;
    }

    else {
        node->data = val;
        node->next = this->head;
        this->head = node;
    }
}
