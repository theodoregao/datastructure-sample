#include <LinkedList.h>

#include <iostream>
#include <iomanip>
#include <fstream>

#define FILENAME_SIZE 64

void printMenu()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << "Please input your command:" << std::endl;
    std::cout << "[a]   add:             add a new book" << std::endl;
    std::cout << "[dn]  delete_by_isbn:  delete a book by isbn" << std::endl;
    std::cout << "[di]  delete_by_index: delete a book by index" << std::endl;
    std::cout << "[l]   list:            list all the books" << std::endl;
    std::cout << "[s]   search_by_isbn:  search a book by isbn" << std::endl;
    std::cout << "[u]   update_by_isbn:  update a book by isbn" << std::endl;
    std::cout << "[sp]  sort_by_price:   sort by price" << std::endl;
    std::cout << "[spd] sort_by_price_d: sort by price descend" << std::endl;
    std::cout << "[sn]  sort_by_isbn:    sort by isbn" << std::endl;
    std::cout << "[snd] sort_by_isbn_d:  sort by isbn descend" << std::endl;
    std::cout << "[sd]  sort_by_date:    sort by date" << std::endl;
    std::cout << "[sdd] sort_by_date_d:  sort by date descend" << std::endl;
    std::cout << "[sv]  save:            save contents to file" << std::endl;
    std::cout << "[r]   read:            read contents from file" << std::endl;
    std::cout << "[q]   quit:            quit" << std::endl;

    std::cout << "====================================================" << std::endl;
}

Book getBook()
{
    Book book;
    std::cout << "Please input isbn: ";
    std::cin.ignore(1024, '\n');
    std::cin.getline(book.isbn, 32);
    std::cout << "Please input title: ";
    std::cin.getline(book.title, 64);
    std::cout << "Please input price: ";
    std::cin >> book.price;
    std::cout << "Please input publisher: ";
    std::cin.ignore(1024, '\n');
    std::cin.getline(book.publisher, 64);
    std::cout << "Please input year month date: ";
    std::cin >> book.publishDate.year >> book.publishDate.month;
    return book;
}

void printBook(Book book)
{
    std::cout << book.isbn << " "
              << std::setw(40) << std::left << book.title
              << "$" << std::fixed << std::setprecision(2) << std::setw(8) << book.price
              << " " << std::setw(32) << book.publisher
              << " " << std::setw(4) << book.publishDate.year
              << "-" << std::setw(2) << book.publishDate.month
              << std::endl;
}

void initialize(LinkedList &list)
{
    list.insert(Book{"978-7-121-12332-0", "Effective C++", 65.00, "Publisher", {2011, 1}});
    list.insert(Book{"978-7-121-15535-2", "C++ Primer", 128.00, "Publisher", {2019, 3}});
    list.insert(Book{"978-7-111-40701-0", "Introduction to Algorithm", 128.00, "Publisher", {2020, 1}});
    list.insert(Book{"978-7-115-29380-0", "Algorithm", 99.00, "Publisher", {2012, 10}});
    list.insert(Book{"978-0-960-01098-1", "Android Stuio 3.4 Devepment Essential", 0.01, "Neil Smyth / Payload Media, Inc", {2019, 6}});
}

void add(LinkedList &list)
{
    std::cout << "******** add a new book ********" << std::endl;
    list.insert(getBook());
}

void deleteByIsbn(LinkedList &list)
{
    std::cout << "******** delete a book by isbn ********" << std::endl;
    std::cout << "Please input isbn you want to delete: ";
    char isbn[32];
    std::cin >> isbn;
    list.remove(isbn);
}

void deleteByIndex(LinkedList &list)
{
    std::cout << "******** delete a book by index ********" << std::endl;
    std::cout << "Please input index you want to delete: ";
    int index;
    std::cin >> index;
    list.remove(index);
}

void listBooks(LinkedList &list)
{
    std::cout << "******** list all the books ********" << std::endl;
    if (list.size() == 0)
    {
        std::cout << "We have 0 books in the list" << std::endl;
        return;
    }
    std::cout << "We have total " << list.size() << " books available" << std::endl;
    for (int i = 0; i < list.size(); i++)
    {
        printBook(*list.getAt(i));
    }
}

void searchByIsbn(LinkedList &list)
{
    std::cout << "******** search a book by isbn ********" << std::endl;
    std::cout << "Please input isbn you want to search: ";
    char isbn[32];
    std::cin >> isbn;
    Book *pbook = list.search(isbn);
    if (pbook != NULL)
    {
        printBook(*pbook);
    }
    else
    {
        std::cout << "Book with isbn " << isbn << " not found" << std::endl;
    }
}

void update(LinkedList &list)
{
    std::cout << "******** update a book by isbn ********" << std::endl;
    std::cout << "Please input isbn you want to update: ";
    char isbn[32];
    std::cin >> isbn;
    if (list.search(isbn) != NULL)
    {
        list.update(isbn, getBook());
    }
    else
    {
        std::cout << "the book is not exist" << std::endl;
    }
}

void sortByPrice(LinkedList &list)
{
    std::cout << "******** sort by price ********" << std::endl;
    list.sortByPrice();
}

void sortByPriceDescend(LinkedList &list)
{
    std::cout << "******** sort by price descend ********" << std::endl;
    list.sortByPriceDescend();
}

void sortByIsbn(LinkedList &list)
{
    std::cout << "******** sort by isbn ********" << std::endl;
    list.sortByIsbn();
}

void sortByIsbnDescend(LinkedList &list)
{
    std::cout << "******** sort by isbn descend ********" << std::endl;
    list.sortByIsbnDescend();
}

void sortByDate(LinkedList &list)
{
    std::cout << "******** sort by date ********" << std::endl;
    list.sortByDate();
}

void sortByDateDescend(LinkedList &list)
{
    std::cout << "******** sort by date descend ********" << std::endl;
    list.sortByDateDescend();
}

void save(LinkedList &list)
{
    std::cout << "******** save contents to file ********" << std::endl;
    std::cout << "Please input the filename: ";
    char filename[FILENAME_SIZE];
    std::cin >> filename;
    std::ofstream out(filename, std::ios::out | std::ios::binary);

    for (int i = 0; i < list.size(); i++)
    {
        out.write((char *)list.getAt(i), sizeof(Book));
    }
}

void read(LinkedList &list)
{
    std::cout << "******** read contents to file ********" << std::endl;
    std::cout << "Please input the filename: ";
    char filename[FILENAME_SIZE];
    std::cin >> filename;
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in.fail())
    {
        std::cout << "File " << filename << " not exist." << std::endl;
        return;
    }
    list.clear();
    Book book;
    while (in.read((char *)&book, sizeof(Book)))
    {
        list.insert(book);
    }
}

bool isCommand(const char *p, const char *q)
{
    return strcmp(p, q) == 0;
}

int main()
{
    LinkedList linkList;
    char command[1024];

    initialize(linkList);

    do
    {
        printMenu();
        std::cin >> command;
        if (isCommand(command, "add") || isCommand(command, "a"))
        {
            add(linkList);
        }
        else if (isCommand(command, "delete_by_isbn") || isCommand(command, "dn"))
        {
            deleteByIsbn(linkList);
        }
        else if (isCommand(command, "delete_by_index") || isCommand(command, "di"))
        {
            deleteByIndex(linkList);
        }
        else if (isCommand(command, "list") || isCommand(command, "l"))
        {
            listBooks(linkList);
        }
        else if (isCommand(command, "search_by_isbn") || isCommand(command, "s"))
        {
            searchByIsbn(linkList);
        }
        else if (isCommand(command, "update_by_isbn") || isCommand(command, "u"))
        {
            update(linkList);
        }
        else if (isCommand(command, "sort_by_price") || isCommand(command, "sp"))
        {
            sortByPrice(linkList);
        }
        else if (isCommand(command, "sort_by_price_d") || isCommand(command, "spd"))
        {
            sortByPriceDescend(linkList);
        }
        else if (isCommand(command, "sort_by_isbn") || isCommand(command, "sn"))
        {
            sortByIsbn(linkList);
        }
        else if (isCommand(command, "sort_by_isbn_d") || isCommand(command, "snd"))
        {
            sortByIsbnDescend(linkList);
        }
        else if (isCommand(command, "sort_by_date") || isCommand(command, "sd"))
        {
            sortByDate(linkList);
        }
        else if (isCommand(command, "sort_by_date_d") || isCommand(command, "sdd"))
        {
            sortByDateDescend(linkList);
        }
        else if (isCommand(command, "save") || isCommand(command, "sv"))
        {
            save(linkList);
        }
        else if (isCommand(command, "read") || isCommand(command, "r"))
        {
            read(linkList);
        }
        std::cin.ignore(1024, '\n');
    } while (!isCommand(command, "quit") && !isCommand(command, "q"));

    return 0;
}
