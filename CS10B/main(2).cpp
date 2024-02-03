#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here