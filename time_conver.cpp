#include <cstring>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#define BUFFER_SIZE 1024

const std::string SEPARATORS = ": \t";

void PrintMenu()
{
    std::cout << "a - 12 to 24" << std::endl;
    std::cout << "b - 24 to 12" << std::endl;
    std::cout << "q - quit" << std::endl;
}

std::string trim(std::string str)
{
    const char *buffer = str.c_str();
    int s = 0, e = str.length() - 1;
    while (isspace(buffer[s]))
        s++;
    while (isspace(buffer[e]))
        e--;
    return str.substr(s, e - s + 1);
}

std::vector<std::string> split(std::string str)
{
    std::vector<std::string> vec;
    const char *cstr = str.c_str();
    int s, e;
    for (s = 0, e = 0; s < str.length() && e < str.length();)
    {
        while (SEPARATORS.find(cstr[s]) != std::string::npos)
            s++;
        e = s + 1;
        while (SEPARATORS.find(cstr[e]) == std::string::npos)
            e++;
        vec.push_back(str.substr(s, e - s));
        s = e;
    }
    return vec;
}

void Handle12To24()
{
    std::string buffer;
    std::cin.ignore(1024, '\n');
    std::getline(std::cin, buffer);
    std::string trimed = trim(buffer);
    std::vector<std::string> items = split(trimed);

    if (items.size() != 4)
    {
        std::cout << "Invalid input, the valid input should with format hh:mm:ss am" << std::endl;
        return;
    }

    int hh, mm, ss;
    try
    {
        hh = std::stoi(items[0]);
        mm = std::stoi(items[1]);
        ss = std::stoi(items[2]);
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Invalid input, cannot convert to int value" << std::endl;
        return;
    }

    std::locale loc;
    std::string ampm = std::toupper(items[3], loc);
    if (ampm == "AM")
    {
    }
    else if (ampm == "PM")
    {
    }
    else
    {
        std::cout << "Invalid input, am pm value not recognized" << std::endl;
    }
}

void Handle24To12()
{
}

int main()
{
    char cmd;
    do
    {
        PrintMenu();
        std::cin >> cmd;
        switch (cmd)
        {
        case 'a':
            Handle12To24();
            break;

        case 'b':
            Handle24To12();
            break;

        default:
            break;
        }
        std::cin.ignore(1024, '\n');
    } while (cmd != 'q');
    return 0;
}