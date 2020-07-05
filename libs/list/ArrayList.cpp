#pragma once

#include "ArrayList.h"

#include <cstdlib>
#include <cstring>

ArrayList::ArrayList() : _size(0), _capacity(DEFAULT_SIZE), _books((Book *)malloc(_capacity * sizeof(Book)))
{
}

ArrayList::~ArrayList()
{
    free(_books);
}

void ArrayList::insert(Book book)
{
    if (_size >= _capacity)
    {
        resize();
    }
    _books[_size++] = book;
}

void ArrayList::remove(char *isbn)
{
    int index = searchIndex(isbn);
    remove(index);
}

void ArrayList::remove(int index)
{
    if (index >= 0 && index < _size)
    {
        _books[index] = _books[--_size];
    }
}

Book *ArrayList::search(char *isbn)
{
    return getAt(searchIndex(isbn));
}

void ArrayList::update(char *isbn, Book book)
{
    Book *foundBook = search(isbn);
    if (foundBook != NULL)
    {
        *foundBook = book;
    }
}

Book *ArrayList::getAt(int index)
{
    if (_size <= index)
    {
        return NULL;
    }
    if (index >= 0)
    {
        return _books + index;
    }
    return NULL;
}

int ArrayList::size()
{
    return _size;
}

bool ArrayList::isEmpty()
{
    return _size == 0;
}

void ArrayList::clear()
{
    free(_books);
    _size = 0;
    _capacity = DEFAULT_SIZE;
    _books = (Book *)malloc(_capacity * sizeof(Book));
}

void ArrayList::resize()
{
    Book *books = (Book *)realloc(_books, _capacity * 2 * sizeof(Book));
    if (books == NULL)
    {
        exit(1);
    }
    _books = books;
    _capacity *= 2;
}

int ArrayList::searchIndex(char *isbn)
{
    for (int i = 0; i < _size; i++)
    {
        if (strcmp(_books[i].isbn, isbn) == 0)
        {
            return i;
        }
    }
    return -1;
}

void ArrayList::swap(int i, int j)
{
    Book temp = _books[i];
    _books[i] = _books[j];
    _books[j] = temp;
}

void ArrayList::sortInternal(bool pFuncLess(Book, Book))
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size - i - 1; j++)
        {
            if (!pFuncLess(_books[j], _books[j + 1]))
            {
                swap(j, j + 1);
            }
        }
    }
}
