#include "graphics.h"
//#include<iostream>
using namespace Grfx;

Graphics::Graphics()
{

     // Initialize GDI+.
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    hWnd = GetConsoleWindow();
    hDC = GetDC(hWnd);
    gr = new Gdiplus::Graphics(hDC);

    Gdiplus::Color blackColor(255, 0, 0, 0);
    gr->Clear(blackColor);
    windowSize();

}
Graphics::~Graphics()
{
    delete gr;
    Gdiplus::GdiplusShutdown(gdiplusToken);
    ReleaseDC(hWnd, hDC);
}

void Graphics::setcolor(int c)
{
    BYTE byRed = 0, byGreen = 0, byBlue = 0;
    byRed = 255 * (c & 0x4);
    byGreen = 255 * (c & 0x2);
    byBlue = 255 * (c & 0x1);
    color = Gdiplus::Color(255, byRed, byGreen, byBlue);
    color2 = Gdiplus::Color(255, 0, 0, 0);
}

void Graphics::line(int x, int y, int x2, int y2)
{
    Gdiplus::Pen      pen(color);
    gr->DrawLine(&pen, x, y, x2, y2);
}

void Graphics::circle(int x, int y, int r)
{
    Gdiplus::Pen      pen(color);
    gr->DrawEllipse(&pen, x - r, y - r, r, r);
}

void Graphics::circle2(int x, int y, int r)
{
    Gdiplus::SolidBrush         mySolidBrush(color);
    gr->FillEllipse(&mySolidBrush, x - r, y - r, r, r);
}

void Graphics::ellipse(int x, int y, int r)
{
    Gdiplus::Pen      pen(color);
    gr->DrawEllipse(&pen, x, y, r, r / 2);
}

void Graphics::rectangle(int x, int y, int x2, int y2)
{
    Gdiplus::Pen      pen(color);
    gr->DrawLine(&pen, x, y, x, y + y2);
    gr->DrawLine(&pen, x, y, x + x2, y);
    gr->DrawLine(&pen, x + x2, y, x + x2, y + y2);
    gr->DrawLine(&pen, x, y + y2, x + x2, y + y2);
}
void Graphics::triangle(int x, int y, int d)
{
    int d2 = d * 0.66;
    Gdiplus::Pen      pen(color);
    gr->DrawLine(&pen, x - d2, y, x + d2, y);
    gr->DrawLine(&pen, x, y - d, x + d2, y);
    gr->DrawLine(&pen, x - d2, y, x, y - d);
}
void Graphics::star(int x, int y, int d, int f, int g)
{
    Gdiplus::Pen      pen(color);
    gr->DrawLine(&pen, x, y, x - d, g + y);
    gr->DrawLine(&pen, x - d, g + y, x + f, y + d);
    gr->DrawLine(&pen, x + f, y + d, x - f, y + d);
    gr->DrawLine(&pen, x - f, y + d, x + d, g + y);
    gr->DrawLine(&pen, x + d, g + y, x, y);
}
void Graphics::cls()
{
    gr->Clear(Gdiplus::Color(0, 0, 0, 0));
}
void Graphics::windowSize()
{
    // Get a bounding rectangle for the clipping region.
    Gdiplus::Rect boundRect;
    gr->GetVisibleClipBounds(&boundRect);
    boundRect.GetSize(&sz);
}
int Graphics::hSize() { return sz.Width; }
int Graphics::vSize() { return sz.Height; }