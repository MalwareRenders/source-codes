#include <windows.h>

int main()
{
	HDC hdc = GetDC(0);
	RECT wRect;
	POINT wPt[3];
	while (1)
	{
		hdc = GetDC(0);
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left + 120;
		wPt[0].y = wRect.top - 0;
		wPt[1].x = wRect.right + 0;
		wPt[2].y = wRect.top + 10;
		wPt[3].x = wRect.left - 35;
		wPt[2].y = wRect.bottom + 10;
		PlgBlt(hdc, wPt, hdc, wRect.left, wRect.top, wRect.right + wRect.left, wRect.bottom + wRect.top, 0, 0, 0);
		ReleaseDC(0, hdc);
		Sleep(10);
	}
}
