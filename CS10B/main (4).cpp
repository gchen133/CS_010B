#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int fileSum(const string &filename);

int main () {
   
   string filename;
   int sum = 0;
   
   cin >> filename;
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}
//--------------------------------------------------

int fileSum(const string &filename) {
    
    ofstream outFS();
    ifstream inFS(filename.c_str());
    int sum = 0;
    int single;
    
    cout << filename << endl;
    inFS.open(filename);
    
    if (filename.fail()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    else () {
	cout << "Enter the name of the input file: ";
        cout << endl;
	inFS >> filename;
    //while (!inFS.fail()) {
    //   inFS >> single;
    //  single = ;
    //   sum = sum + single;
    }
    }
    return sum;
}