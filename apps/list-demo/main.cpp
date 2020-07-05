#include <Book.h>
#include <ArrayList.h>
#include <iostream>

int main()
{
    std::cout << "############################################" << std::endl;
    std::cout << "##                 List Demo              ##" << std::endl;
    std::cout << "############################################" << std::endl;

    Book book{"978-7-121-12332-0", "Effective C++", 65.00, "publisher", {2011, 1}};

    std::cout << book.title << " " << book.price << std::endl;

    return 0;
}
