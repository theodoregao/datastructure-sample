#pragma once

#include "LinkedList.h"

#include <cstdlib>
#include <cstring>

LinkedList::LinkedList()
{
    _head.next = NULL;
    _size = 0;
}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::insert(Book book)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->book = book;
    node->next = _head.next;
    _head.next = node;
    _size++;
}

void LinkedList::remove(char *isbn)
{
    Node *p = _head.next;
    Node *pre = &_head;
    internalSearch(p, pre, isbn);
    remove(pre, p);
}

void LinkedList::remove(int index)
{
    if (index < 0 || index >= _size)
    {
        return;
    }
    Node *p = _head.next;
    Node *pre = &_head;
    while (p != NULL && index > 0)
    {
        pre = p;
        p = p->next;
        index--;
    }
    if (p == NULL)
    {
        return;
    }
    remove(pre, p);
}

Book *LinkedList::search(char *isbn)
{
    Node *p = _head.next;
    Node *pre = &_head;
    internalSearch(p, pre, isbn);
    if (p == NULL)
    {
        return NULL;
    }
    return &p->book;
}

void LinkedList::update(char *isbn, Book book)
{
    Book *foundBook = search(isbn);
    if (foundBook != NULL)
    {
        *foundBook = book;
    }
}

Book *LinkedList::getAt(int index)
{
    Node *p = _head.next;
    while (p != NULL && index > 0)
    {
        p = p->next;
        index--;
    }
    if (p == NULL)
    {
        return NULL;
    }
    return &p->book;
}

int LinkedList::size()
{
    return _size;
    /*
		// slow implementation with O(size)
		int size = 0;
		Node* p = _head.next;
		while (p != NULL) {
			size++;
			p = p->next;
		}
		return size;*/
}

bool LinkedList::isEmpty()
{
    return _size == 0;
}

void LinkedList::clear()
{
    Node *p = _head.next;
    Node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    _head.next = NULL;
    _size = 0;
}

void LinkedList::sortByPrice()
{
    sortInternal(lowPrice);
}

void LinkedList::sortByPriceDescend()
{
    sortInternal(highPrice);
}

void LinkedList::sortByIsbn()
{
    sortInternal(lowIsbn);
}

void LinkedList::sortByIsbnDescend()
{
    sortInternal(highIsbn);
}

void LinkedList::sortByDate()
{
    sortInternal(lowDate);
}

void LinkedList::sortByDateDescend()
{
    sortInternal(highDate);
}

void LinkedList::remove(Node *pre, Node *p)
{
    if (pre == NULL || p == NULL)
    {
        return;
    }
    pre->next = p->next;
    free(p);
    _size--;
}

void LinkedList::internalSearch(Node *&p, Node *&pre, char *isbn)
{
    while (p != NULL)
    {
        if (strcmp(p->book.isbn, isbn) == 0)
        {
            return;
        }
        pre = p;
        p = p->next;
    }
}

void LinkedList::swap(Node *pre, Node *&q, Node *&p)
{
    pre->next = p;
    q->next = p->next;
    p->next = q;

    pre = q;
    q = p;
    p = pre;
}

void LinkedList::sortInternal(bool pFuncLess(Book, Book))
{
    Node *p, *q, *pre;
    for (int i = 0; i < _size; i++)
    {
        pre = &_head;
        q = _head.next;
        p = q->next;
        for (int j = 0; j < _size - i - 1; j++)
        {
            if (!pFuncLess(q->book, p->book))
            {
                swap(pre, q, p);
            }
            pre = q;
            q = p;
            p = p->next;
        }
    }
}
