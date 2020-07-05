#pragma once

#include "BobbleSort.h"
#include "Book.h"

class ArrayList : public BobbleSort
{
public:
    ArrayList();
    ~ArrayList();
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
    const int DEFAULT_SIZE = 1;
    int _size;
    int _capacity;
    Book *_books;

    void resize();
    int searchIndex(char *isbn);
    void swap(int i, int j);
    void sortInternal(bool pFuncLess(Book, Book)) override;
};
