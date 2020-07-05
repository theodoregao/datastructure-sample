#pragma once

#include "BobbleSort.h"
#include "Book.h"

typedef struct _Node
{
    Book book;
    _Node *next;
} Node;

class LinkedList : public BobbleSort
{
public:
    LinkedList();
    ~LinkedList();
    void insert(Book book);
    void remove(char *isbn);
    void remove(int index);
    Book *search(char *isbn);
    void update(char *isbn, Book book);
    Book *getAt(int index);
    int size();
    bool isEmpty();
    void clear();

private:
    Node _head;
    int _size;

    void remove(Node *pre, Node *p);
    void internalSearch(Node *&p, Node *&pre, char *isbn);
    void swap(Node *pre, Node *&q, Node *&p);
    void sortInternal(bool pFuncLess(Book, Book)) override;
};
