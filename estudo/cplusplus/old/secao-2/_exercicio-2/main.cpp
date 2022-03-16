/**
 * In this exercise you will write a statement using cout  and the insertion operator <<  to display how many dogs Sally has.  
 * The variable x  represents the number of dogs. 
 * x  has already been declared and initialized for you.
 * The output should read "Sally has 3 dogs.". 
 * For this exercise there is NO need to use the '\n '  character or endl  to create a new line after the output statement.
 */
#include <iostream>

using namespace std;

int main()
{
    int x { 3 };

    cout << "Sally has " << x << " dogs.";

    return 0;
}