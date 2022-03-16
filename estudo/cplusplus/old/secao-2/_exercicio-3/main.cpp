/*
 * In this exercise you will write code using cin  and the extraction operator >>  to allow a user to enter their date of birth. 
 * The variable m represents the month, d represents the day, and y represents the year. 
 * Assume that the user will enter their date of birth in the order of month, day, year, with each value being separated by a white space.
 * You do not need to prompt the user for any information using cout
 * Our test program will automatically 'pretend' to be the user and enter the values 2  15  and 1993  automatically. 
*/
#include <iostream>

using namespace std;

int main()
{
    int m {};
    int d {};
    int y {};

    cin >> m >> d >> y;

    cout << m << " " << d << " " << y;

    return 0;
}