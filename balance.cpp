#include <iomanip>
#include <iostream>

using namespace std;

// add one line of comment here
// add more comment
int main()
{
    double beginningBalance;
    int numberOfChecks;
    double fee = 10; // monthly service fee

    cout << "Please input the beginning balance: ";
    cin >> beginningBalance;
    if (beginningBalance < 0)
    {
        cout << "Your account is overdrawn" << endl;
        return 0;
    }
    else if (beginningBalance < 300)
    {
        fee += 25; // low balance fee
    }

    do
    {
        cout << "Please input the number of checks n (n >= 0): ";
        cin >> numberOfChecks;
        if (numberOfChecks >= 0)
        {
            // calculate check fee
            if (numberOfChecks <= 20)
            {
                fee += numberOfChecks * 1.0;
            }
            else if (numberOfChecks < 30)
            {
                fee += numberOfChecks * .75;
            }
            else if (numberOfChecks < 50)
            {
                fee += numberOfChecks * .5;
            }
            else
            {
                fee += numberOfChecks * .25;
            }
        }
        else
        {
            cout << "Invalid number of checks" << endl;
        }
    } while (numberOfChecks < 0);

    cout << "Your total service fee is $" << fixed << setprecision(2) << fee << endl;
    return 0;
}
