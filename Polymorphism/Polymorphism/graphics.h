#ifndef _GRAPHICS_
#define _GRAPHICS_

#include <objidl.h>
#include <gdiplus.h>
#include <memory>

namespace Grfx
{

    class Graphics
    {
        HWND hWnd;
        HDC hDC;
        Gdiplus::Color color, color2;
        Gdiplus::Graphics* gr;
        //std::unique_ptr<Graphics> gr;
        ULONG_PTR           gdiplusToken;
        Gdiplus::Size sz;
    public:

        Graphics();
        ~Graphics();
        void setcolor(int c);
        void line(int x, int y, int x2, int y2);
        void circle(int x, int y, int r);
        void circle2(int x, int y, int r);
        void rectangle(int x, int y, int x2, int y2);
        void triangle(int x, int y, int d);
        void ellipse(int x, int y, int r);
        void star(int x, int y, int d, int f, int g);
        void cls();
        void windowSize();
        int hSize();
        int vSize();

    }; // class Graphics

}; // namespace Grfx

#endif