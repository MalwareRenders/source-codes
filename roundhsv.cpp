#include <windows.h>
#include <math.h>

// not my color function
COLORREF COLORHSL(int length) {
    double h = fmod(length, 360.0);
    double s = 1.0;
    double l = 0.5;

    double c = (1.0 - fabs(2.0 * l - 1.0)) * s;
    double x = c * (1.0 - fabs(fmod(h / 60.0, 2.0) - 1.0));
    double m = l - c / 2.0;

    double r1, g1, b1;
    if (h < 60) {
        r1 = c;
        g1 = x;
        b1 = 0;
    }
    else if (h < 120) {
        r1 = x;
        g1 = c;
        b1 = 0;
    }
    else if (h < 180) {
        r1 = 0;
        g1 = c;
        b1 = x;
    }
    else if (h < 240) {
        r1 = 0;
        g1 = x;
        b1 = c;
    }
    else if (h < 300) {
        r1 = x;
        g1 = 0;
        b1 = c;
    }
    else {
        r1 = c;
        g1 = 0;
        b1 = x;
    }

    int red = static_cast<int>((r1 + m) * 255);
    int green = static_cast<int>((g1 + m) * 255);
    int blue = static_cast<int>((b1 + m) * 255);

    return RGB(red, green, blue);
}

int main() {
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);
	double increment = 0.0;
	while (true) {
		HDC hdc = GetDC(0);
		int rand_num_x = rand() % w;
		int rand_num_y = rand() % h;

		int top_x = 0 + rand_num_x; 
		int top_y = 0 + rand_num_y; 

		int bottom_x = 100 + rand_num_x; 
		int bottom_y = 100 + rand_num_y;
		
		HBRUSH hbrush = CreateSolidBrush(COLORHSL(increment));
    SelectObject(hdc, hbrush); 

		RoundRect(hdc, top_x, top_y, bottom_x, bottom_y, 50, 50);
		Sleep(100);
		increment += 1;
	}
	return 0x00;
}
