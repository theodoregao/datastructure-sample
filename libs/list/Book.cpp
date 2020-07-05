#include "Book.h"

#include <cstring>

bool lowPrice(Book thisBook, Book thatBook)
{
    return thisBook.price < thatBook.price;
}

bool highPrice(Book thisBook, Book thatBook)
{
    return thisBook.price > thatBook.price;
}

bool lowIsbn(Book thisBook, Book thatBook)
{
    return strcmp(thisBook.isbn, thatBook.isbn) < 0;
}

bool highIsbn(Book thisBook, Book thatBook)
{
    return strcmp(thisBook.isbn, thatBook.isbn) > 0;
}

bool lowDate(Book thisBook, Book thatBook)
{
    if (thisBook.publishDate.year < thatBook.publishDate.year)
        return true;
    if (thisBook.publishDate.year == thatBook.publishDate.year)
        return thisBook.publishDate.month < thatBook.publishDate.month;
    return false;
}

bool highDate(Book thisBook, Book thatBook)
{
    return lowDate(thatBook, thisBook);
}
