#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int fileSum(string filename);

int main () {
   
   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}
//--------------------------------------------------

int fileSum(string filename) {
    
    int sum = 0;
    int single;
    ifstream inFS;
    
    inFS.open(filename);
    
    if (!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    while (inFS >> single) {
       sum = sum + single;
    }
    return sum;
}