// for 437 again
//

#include <windows.h>

int main()
{
	HDC hdc = NULL;
	while (true) {
		hdc = GetWindowDC(GetDesktopWindow());
		int sx = GetSystemMetrics(SM_CXSCREEN);
		int sy = GetSystemMetrics(SM_CYSCREEN);
		
		HBRUSH brush = CreateHatchBrush(rand() % 7, RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
		BitBlt(hdc, rand() % 5, rand() % 5, sx, sy, hdc, rand() % 5, rand() % 5, SRCCOPY);
		PatBlt(hdc, 0, 0, sx, sy, PATINVERT);
		DeleteObject(brush);
		
		ReleaseDC(NULL, hdc);
		Sleep(10);
	}
	return 0x00;
}
