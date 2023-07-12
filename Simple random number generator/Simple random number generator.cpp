#include <iostream>
#include <random>
#include <cctype>
using namespace std;

int setUpperLimit();
int setLowerLimit();
bool checkLimits(int lowerlimit, int upperlimit);
void prompt();

int main()
{
    prompt();
    return 0;
}

int setLowerLimit() { // Fucntion to allow the user to set the lowerlimit
    int lowerlimit;
    cout << "Please enter a lower limit: ";
    cin >> lowerlimit;
    if (cin.fail()) { // Checks for error in matching data type, if true, recursively triggers the function
        cin.clear();
        cin.ignore(10, '\n');
        lowerlimit = setLowerLimit();
    }
    else {
        return lowerlimit;
    }
}

int setUpperLimit() { // Fucntion to allow the user to set the upperlimit
    int upperlimit;
    cout << "Please enter a upper limit: ";
    cin >> upperlimit;
    if (cin.fail()) { // Checks for error in matching data type, if true, recursively triggers the function
        cin.clear();
        cin.ignore(10, '\n');
        return setUpperLimit();
    }
    else {
        return upperlimit;
    }
}

bool checkLimits(int lowerlimit, int upperlimit) { // This makes sure that the lower and upper limit aren't arroneously set
    if (lowerlimit < upperlimit) {
        return true;
    }
    else {
        return false;
    }
}

void prompt() { // prompts the user about options before choosing a random value
    char option;
    int lowerlimit = 0;
    int upperlimit = 100;

    do {
        cout << "Would you like to set an lower and upper limit(n - no, y - yes)? ";
        cin >> option;
        option = tolower(option);
    } while (option != 'y' && option != 'n');

    if (option == 'y') {
        do {
            lowerlimit = setLowerLimit();
            upperlimit = setUpperLimit();
        } while (!checkLimits(lowerlimit, upperlimit));
    }

    srand(time(0));
    cout << "The random number is: " << (rand() % (upperlimit - lowerlimit + 1)) + lowerlimit;
}