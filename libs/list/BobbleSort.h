#pragma once

#include "Book.h"

class BobbleSort
{
public:
    void sortByPrice();
    void sortByPriceDescend();
    void sortByIsbn();
    void sortByIsbnDescend();
    void sortByDate();
    void sortByDateDescend();

protected:
    virtual void sortInternal(bool pFuncLess(Book, Book)) = 0;
};