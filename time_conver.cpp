#include <cstring>
<<<<<<< HEAD
=======
#include <iomanip>
>>>>>>> Add time convert sample
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
<<<<<<< HEAD
        while (SEPARATORS.find(cstr[s]) != std::string::npos)
            s++;
        e = s + 1;
        while (SEPARATORS.find(cstr[e]) == std::string::npos)
=======
        while (s < str.length() && SEPARATORS.find(cstr[s]) != std::string::npos)
            s++;
        e = s + 1;
        while (e < str.length() && SEPARATORS.find(cstr[e]) == std::string::npos)
>>>>>>> Add time convert sample
            e++;
        vec.push_back(str.substr(s, e - s));
        s = e;
    }
    return vec;
}

void Handle12To24()
{
<<<<<<< HEAD
=======
    std::cout << "Please input your time with hh:mm:ss am format" << std::endl;

>>>>>>> Add time convert sample
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

<<<<<<< HEAD
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
=======
    std::string ampm = items[3];
    if (ampm == "AM" || ampm == "Am" || ampm == "aM" || ampm == "am")
    {
        if (hh <= 0 || hh > 12)
        {
            std::cout << "Invalid input, 12hr format hh need to between (0, 12]" << std::endl;
        }
        else if (mm < 0 || mm >= 60)
        {
            std::cout << "Invalid input, 12hr format mm need to between [0, 60)" << std::endl;
        }
        else if (ss < 0 || ss >= 60)
        {
            std::cout << "Invalid input, 12hr format ss need to between [0, 60)" << std::endl;
        }
        else
        {
            if (hh == 12)
            {
                hh = 0;
            }
            std::cout.fill('0');
            std::cout << "24hr format of " << buffer << " is "
                      << std::setw(2) << hh << ":"
                      << std::setw(2) << mm << ":"
                      << std::setw(2) << ss << std::endl;
        }
    }
    else if (ampm == "PM" || ampm == "Pm" || ampm == "pM" || ampm == "pm")
    {
        if (hh <= 0 || hh > 12)
        {
            std::cout << "Invalid input, 12hr format hh need to between (0, 12]" << std::endl;
        }
        else if (mm < 0 || mm >= 60)
        {
            std::cout << "Invalid input, 12hr format mm need to between [0, 60)" << std::endl;
        }
        else if (ss < 0 || ss >= 60)
        {
            std::cout << "Invalid input, 12hr format ss need to between [0, 60)" << std::endl;
        }
        else
        {
            if (hh != 12)
            {
                hh += 12;
            }
            std::cout.fill('0');
            std::cout << "24hr format of " << buffer << " is "
                      << std::setw(2) << hh << ":"
                      << std::setw(2) << mm << ":"
                      << std::setw(2) << ss << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input, am/pm value not recognized" << std::endl;
>>>>>>> Add time convert sample
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