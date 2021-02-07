// Memory Scanner src by @AnonHexo (anonhexo.github.io)

#include <iostream> // used for basic functions
#include <Windows.h> // used for window functions 

using namespace std; // so you don't have to type std::

int value;
int eValue = 9999; // you can change to anything you want (number)

int main()
{
	HWND hwnd = FindWindowA(NULL, "Minecraft 1.8.8"); // change to your window title
	if (hwnd == NULL) {
		cout << "Cannot find Minecraft process window.\n"; // change to your name
		Sleep(3000);
		exit(-1);
	}
	else
	{
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

		if (procID == NULL) {
			cout << "Cannot obtain process ID.\n";
			Sleep(3000);
			exit(-1);
		}
		else
		{
			cout << "Successfully attached to selected process.\n";
			cout << "Press ARROW_KEY_UP to trigger the WriteProcessMemory function\n";
			while (true)
			{
				if (GetAsyncKeyState(VK_UP)) { // you can change VK_UP to any key you want

					// write eValue (9999) on memory address
					WriteProcessMemory(handle, (LPVOID)0xCE8503AC, &eValue, sizeof(value), 0);
					//               change address here ^^^^^
					Sleep(700);
				}
			};
		};
	};
};