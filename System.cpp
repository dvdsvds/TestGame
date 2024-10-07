#include "system.h"

#ifdef max
#undef max
#endif

void SetConsoleFont(int fontSize) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

	cfi.dwFontSize.Y = fontSize;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"NSimSun");

	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

int getValidIntegerInput() {
	int choice;
	while (true) {
		std::cout << "> ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invaild input. Please try again" << std::endl;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return choice;
		}
	}
}
