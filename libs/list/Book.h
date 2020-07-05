#pragma once

struct Date
{
    int year, month;
};

struct Book
{
    char isbn[32];
    char title[64];
    double price;
    char publisher[64];
    Date publishDate;
};

bool lowPrice(Book thisBook, Book thatBook);

bool highPrice(Book thisBook, Book thatBook);

bool lowIsbn(Book thisBook, Book thatBook);

bool highIsbn(Book thisBook, Book thatBook);

bool lowDate(Book thisBook, Book thatBook);

bool highDate(Book thisBook, Book thatBook);
