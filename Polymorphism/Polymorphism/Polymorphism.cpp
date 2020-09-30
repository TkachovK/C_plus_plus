#include "pch.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "graphics.h"
#include <vector>
using namespace std;
Grfx::Graphics console_graphics;

const char LARROW = 'K';
const char RARROW = 'M';
const char UARROW = 'H';
const char DARROW = 'P';
const char ClearScreen = 'c';
const char Deformation = 'w';
const char ChangeColor = 'x';
const char Trajectory = 't';
const char Default = 'd';
const char Invisible = 'z';
const char Agregation = 'a';
const char Agregation_2 = 'q';
const char Trail = 'e';
const char Switch = 's';
const int  BGCOLOR = 0;
const int  COLOR = 2;
const int  STEP = 10;

class Shape
{
protected:
    int x, y, color;

public:
    Shape() {}
    Shape(int a, int b, int c) : x(a), y(b), color(c) {}
    virtual
        void draw(int c) = 0;
    void show() { draw(color); }
    void hide() { draw(BGCOLOR); }
    void move(int dx, int dy)
    {
        hide();
        x += dx;
        y += dy;
        show();
    }
    void move_wt(int dx, int dy)
    {
        hide();
        show();
        x += dx;
        y += dy;
        hide();
        show();
    }
    void ChangeColor(int c)
    {
        color = c;
        draw(c);
    }
    void Default(int dx, int dy, int c)
    {
        x = dx;
        y = dy;
        color = c;
        draw(c);
    }
    virtual void Deformation(int dx, int dy, int c, int R) {}
};

class Segment : public Shape
{
    int dx, dy;
public:
    Segment() {}
    Segment(int a, int b, int da, int db, int c) : Shape(a, b, c), dx(da), dy(db) { show(); }
    void draw(int c)
    {
        console_graphics.setcolor(c); console_graphics.line(x, y, x + dx, y + dy);
    }
    void Deformation(int dx, int dy, int dx_1, int dy_1, int c)
    {
        this->dx = dx_1;
        this->dy = dy_1;
        x = dx; y = dy;
        color = c;
        draw(c);
    }

};

class Circle : public Shape
{
protected:
    int r;
public:
    Circle() {}
    Circle(int a, int b, int t, int c) : Shape(a, b, c), r(t) { show(); }
    void draw(int c)
    {
        console_graphics.setcolor(c); console_graphics.circle(x, y, r);
    }
    void Deformation(int dx, int dy, int R, int c)
    {
        x = dx;
        y = dy;
        color = c;
        r = R;
        draw(c);
    }

};

class Circle2 : public Shape
{
    int r;
public:
    Circle2(int a, int b, int t, int c) : Shape(a, b, c), r(t) { show(); }
    void draw(int c)
    {
        console_graphics.setcolor(c); console_graphics.circle2(x, y, r);
    }

};

class Elipse : public Shape
{
    int r;
public:
    Elipse(int a, int b, int t, int c) : Shape(a, b, c), r(t) { show(); }
    void draw(int c)
    {
        console_graphics.setcolor(c); console_graphics.ellipse(x, y, r);
    }

};

class Triangle : public Shape
{
    int z;
public:
    Triangle(int a, int b, int d, int c) : Shape(a, b, c), z(d) { show(); }
    void draw(int c)
    {
        console_graphics.setcolor(c); console_graphics.triangle(x, y, z);
    }

};

class RRectangle : public Shape
{
    int x2, y2;
public:
    RRectangle() {}
    RRectangle(int a, int b, int d, int f, int c) : Shape(a, b, c), x2(d), y2(f) { show(); }
    void draw(int c) {
        console_graphics.setcolor(c); console_graphics.rectangle(x, y, x2, y2);
    }
    void Deformation(int dx, int dy, int dx_1, int dy_1, int c)
    {
        this->x2 = dx_1;
        this->y2 = dy_1;
        x = dx;
        y = dy;
        color = c;
        draw(c);
    }
};

class Star : public Shape
{
    int z, w, p, u;
public:
    Star(int a, int b, int d, int f, int g, int c) : Shape(a, b, c), z(d), w(f), p(g) { show(); }
    void draw(int c)
    {
        console_graphics.setcolor(c); console_graphics.star(x, y, z, w, p);
    }

};

void UI()
{
    system("cls");
    cout << "c -- î÷èñòêà ýêðàíà" << endl;
    cout << "s -- ïåðåêëþ÷åíèå ìåæäó îáúåêòàìè" << endl;
    cout << "x -- ñìåíà öâåòà" << endl;
    cout << "t -- äâèæåíèå îáúåêòà ïî çàäàííîé òðàåêòîðèè" << endl;
    cout << "d -- âîññòàíîâëåíèå íà÷àëüíîãî ñîñòîÿíèÿ îáúåêòà" << endl;
    cout << "z -- ñìåíà ñîñòîÿíèÿ âèäèìûé/íåâèäèìûé" << endl;
    cout << "w -- äåôîðìàöèÿ îáúåêòà" << endl;
    cout << "a -- àãðåãàöèÿ îáúåêòà" << endl;
    cout << "q -- àãðåãàöèÿ àãðåãàòà" << endl;
    cout << "e -- ñìåíà ñîñòîÿíèÿ ïåðåìåùåíèÿ îáúåêòà ñî ñëåäîì è áåç" << endl;
    system("pause");
    system("cls");
}

int switcher(int e)
{
    if (e == 0)
    {
        e = 1;
    }
    else
    {
        e = 0;
    }
    return e;
}

int invisible(int count, int p, int p2, int k, int C,
    vector<Circle> v_circle1, vector<Circle> v_circle2, vector<Segment> v_segment1, vector<Segment> v_segment2, vector<RRectangle> v_rectangle)
{
    if (count == 0)
    {
        if (k == BGCOLOR)
        {
            for (int i = 0; i <= p; i++)
            {
                v_circle1[i].draw(C);
                v_circle2[i].draw(C);
                v_segment1[i].draw(C);
                v_segment2[i].draw(C);
            }
            k = 1;
        }
        else
        {
            for (int i = 0; i <= p; i++)
            {
                v_circle1[i].draw(BGCOLOR);
                v_circle2[i].draw(BGCOLOR);
                v_segment1[i].draw(BGCOLOR);
                v_segment2[i].draw(BGCOLOR);
            }
            k = 0;
        }
    }
    else
    {
        if (k == BGCOLOR)
        {
            for (int i = 0; i <= p2; i++)
            {
                v_rectangle[i].draw(C);
            }
            k = 1;
        }
        else
        {
            for (int i = 0; i <= p2; i++)
            {
                v_rectangle[i].draw(BGCOLOR);
            }
            k = 0;
        }
    }
    return k;
}

int  changecolor(int count, int p, int p2, int C,
    vector<Circle> v_circle1, vector<Circle> v_circle2, vector<Segment> v_segment1, vector<Segment> v_segment2, vector<RRectangle> v_rectangle)
{
    if (count == 0)
    {
        if (C == 2)
        {
            for (int i = 0; i <= p; i++)
            {
                C = 5;
                v_circle1[i].ChangeColor(C);
                v_circle2[i].ChangeColor(C);
                v_segment1[i].ChangeColor(C);
                v_segment2[i].ChangeColor(C);
            }
        }
        else
        {
            for (int i = 0; i <= p; i++)
            {
                C = 2;
                v_circle1[i].ChangeColor(C);
                v_circle2[i].ChangeColor(C);
                v_segment1[i].ChangeColor(C);
                v_segment2[i].ChangeColor(C);
            }
        }
        return C;
    }
    else
    {
        if (C == 2)
        {
            for (int i = 0; i <= p; i++)
            {
                C = 5;
                v_rectangle[i].ChangeColor(C);
            }
        }
        else
        {
            for (int i = 0; i <= p; i++)
            {
                C = 2;
                v_rectangle[i].ChangeColor(C);
            }
        }
    }
    return C;
}

void trajectory(int count, int u, int u2, string t_up, string t_down, string t_left, string t_right, vector<string> t, vector<string> t_1,
    vector<Circle> v_circle1, vector<Circle> v_circle2, vector<Segment> v_segment1, vector<Segment> v_segment2, vector<RRectangle> v_rectangle)
{
    console_graphics.cls();
    if (count == 0)
    {
        for (int i = 0; i < u; i++)
        {
            if (t[i] == t_right)
            {
                v_circle1[0].move(+STEP, 0);
                v_circle2[0].move(+STEP, 0);
                v_segment1[0].move(+STEP, 0);
                v_segment2[0].move(+STEP, 0);
            }
            else if (t[i] == t_down)
            {
                v_circle1[0].move(0, +STEP);
                v_circle2[0].move(0, +STEP);
                v_segment1[0].move(0, +STEP);
                v_segment2[0].move(0, +STEP);
            }
            else if (t[i] == t_left)
            {
                v_circle1[0].move(-STEP, 0);
                v_circle2[0].move(-STEP, 0);
                v_segment1[0].move(-STEP, 0);
                v_segment2[0].move(-STEP, 0);
            }
            else if (t[i] == t_up)
            {
                v_circle1[0].move(0, -STEP);
                v_circle2[0].move(0, -STEP);
                v_segment1[0].move(0, -STEP);
                v_segment2[0].move(0, -STEP);
            }
            else
            {
                ;
            }
        }
    }
    else
    {
        for (int i = 0; i < u2; i++)
        {
            if (t_1[i] == t_right)
            {
                v_rectangle[0].move(+STEP, 0);
            }
            else if (t_1[i] == t_down)
            {
                v_rectangle[0].move(0, +STEP);
            }
            else if (t_1[i] == t_left)
            {
                v_rectangle[0].move(-STEP, 0);
            }
            else if (t_1[i] == t_up)
            {
                v_rectangle[0].move(0, -STEP);
            }
            else
            {
                ;
            }
        }
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count = 0;
    int p = 0, p2 = 0;
    int x, y, x1, y1, x2, y2, C, R, r, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7;
    x = 250; y = 100; x1 = 400; y1 = 400; R = 300; C = COLOR; x2 = 325; y2 = 325; r = 150;
    x3 = 150; y3 = 0; x4 = 300; y4 = 300;
    x5 = 0; y5 = 0; x6 = 420; y6 = 420;
    x7 = 100; y7 = 250;
    Segment s(x, y, y3, y4, C);
    Segment s2(x7, y7, x4, y3, C);
    RRectangle l(x5, y5, x6, y6, C);
    Circle q(x1, y1, R, C);
    Circle q2(x2, y2, r, C);
    Circle* arr_circle1 = new Circle[100];
    Circle* arr_circle2 = new Circle[100];
    Segment* arr_segment1 = new Segment[100];
    Segment* arr_segment2 = new Segment[100];
    RRectangle* arr_rectangle = new RRectangle[100];
    std::vector<Circle> v_circle1;
    std::vector<Circle> v_circle2;
    std::vector<Segment> v_segment1;
    std::vector<Segment> v_segment2;
    std::vector<RRectangle> v_rectangle;
    v_circle1.push_back(q2);
    v_circle2.push_back(q);
    v_segment1.push_back(s);
    v_segment2.push_back(s2);
    v_rectangle.push_back(l);
    std::vector<string> t;
    std::vector<string> t_1;
    char c;
    int k = 1, e = 0, u = 0, u2 = 0;
    string t_left, t_right, t_up, t_down; t_left = 'a'; t_right = 'b'; t_up = 'c'; t_down = 'd';
    while (c = _getch(), c != 27)
    {
        if (c == '\xe0')
        {
            c = _getch();

            switch (c)
            {
            case LARROW:
            {
                if (count == 0)
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move(-STEP, 0);
                            v_circle2[i].move(-STEP, 0);
                            v_segment1[i].move(-STEP, 0);
                            v_segment2[i].move(-STEP, 0);
                            t.push_back(t_left); u++;
                        }
                        x -= 10; x1 -= 10; x7 -= 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move_wt(-STEP, 0);
                            v_circle2[i].move_wt(-STEP, 0);
                            v_segment1[i].move_wt(-STEP, 0);
                            v_segment2[i].move_wt(-STEP, 0);
                        }
                        x -= 10; x1 -= 10; x7 -= 10;
                    }
                }
                else
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move(-STEP, 0);
                            t_1.push_back(t_left); u2++;
                        }
                        x5 -= 10; x6 -= 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move_wt(-STEP, 0);
                        }
                        x5 -= 10; x6 -= 10;
                    }
                }
                break;
            }
            case RARROW:
            {
                if (count == 0)
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move(+STEP, 0);
                            v_circle2[i].move(+STEP, 0);
                            v_segment1[i].move(+STEP, 0);
                            v_segment2[i].move(+STEP, 0);
                            t.push_back(t_right); u++;
                        }
                        x += 10; x1 += 10; x7 += 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move_wt(+STEP, 0);
                            v_circle2[i].move_wt(+STEP, 0);
                            v_segment1[i].move_wt(+STEP, 0);
                            v_segment2[i].move_wt(+STEP, 0);
                        }
                        x += 10; x1 += 10; x7 += 10;
                    }
                }
                else
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move(+STEP, 0);
                            t_1.push_back(t_right); u2++;
                        }
                        x5 += 10; x6 += 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move_wt(+STEP, 0);
                        }
                        x5 += 10; x6 += 10;
                    }
                }
                break;
            }
            case UARROW:
            {
                if (count == 0)
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move(0, -STEP);
                            v_circle2[i].move(0, -STEP);
                            v_segment1[i].move(0, -STEP);
                            v_segment2[i].move(0, -STEP);
                            t.push_back(t_up); u++;
                        }
                        y -= 10; y1 -= 10; y7 -= 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move_wt(0, -STEP);
                            v_circle2[i].move_wt(0, -STEP);
                            v_segment1[i].move_wt(0, -STEP);
                            v_segment2[i].move_wt(0, -STEP);
                        }
                        y -= 10; y1 -= 10; y7 -= 10;
                    }
                }
                else
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move(0, -STEP);
                            t_1.push_back(t_up); u2++;
                        }
                        y5 -= 10; y6 -= 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move_wt(0, -STEP);
                        }
                        y5 -= 10; y6 -= 10;
                    }
                }
                break;
            }
            case DARROW:
            {
                if (count == 0)
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move(0, +STEP);
                            v_circle2[i].move(0, +STEP);
                            v_segment1[i].move(0, +STEP);
                            v_segment2[i].move(0, +STEP);
                            t.push_back(t_down); u++;
                        }
                        y += 10; y1 += 10; y7 += 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p; i++)
                        {
                            v_circle1[i].move_wt(0, +STEP);
                            v_circle2[i].move_wt(0, +STEP);
                            v_segment1[i].move_wt(0, +STEP);
                            v_segment2[i].move_wt(0, +STEP);
                        }
                        y += 10; y1 += 10; y7 += 10;
                    }
                }
                else
                {
                    if (e == 0)
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move(0, +STEP);
                            t_1.push_back(t_down); u2++;
                        }
                        y5 += 10; y6 += 10;
                    }
                    else
                    {
                        for (int i = 0; i <= p2; i++)
                        {
                            v_rectangle[i].move_wt(0, +STEP);
                        }
                        y5 += 10; y6 += 10;
                    }
                }
                break;
            }
            }
            if (x1 == x5 || y1 == y5 || x1 == x6 || y1 == y6 || x7 == x5 || y == y5 || x7 == x6 || y == y6 || x == x5 || x == x6)
            {
                for (int i = 0; i <= p; i++)
                {
                    C = 5;
                    v_circle1[i].ChangeColor(C);
                    v_circle2[i].ChangeColor(C);
                    v_segment1[i].ChangeColor(C);
                    v_segment2[i].ChangeColor(C);
                }
            }
            if (x1 != x5 && y1 != y5 && x1 != x6 && y1 != y6 && x7 != x5 && y != y5 && x7 != x6 && y != y6 && x != x5 && x != x6)
            {
                for (int i = 0; i <= p; i++)
                {
                    C = 2;
                    v_circle1[i].ChangeColor(C);
                    v_circle2[i].ChangeColor(C);
                    v_segment1[i].ChangeColor(C);
                    v_segment2[i].ChangeColor(C);
                }
            }
        }
        else
            switch (c)
            {
            case 59:
            {
                UI();
                break;
            }
            case ClearScreen:
            {
                console_graphics.cls();
                break;
            }
            case Trail:
            {
                e = switcher(e);
                break;
            }
            case Agregation:
            {
                if (count == 0)
                {
                    p++;
                    x1 += 50;
                    y1 += 50;
                    x2 += 50;
                    y2 += 50;
                    arr_circle1[p] = Circle(x1, y1, R, C);
                    arr_circle2[p] = Circle(x2, y2, r, C);
                    v_circle1.push_back(arr_circle2[p]);
                    v_circle2.push_back(arr_circle1[p]);
                    v_segment1.push_back(arr_segment1[p]);
                    v_segment2.push_back(arr_segment2[p]);
                }
                else
                {
                    p2++;
                    x5 += 20;
                    y5 += 20;
                    x6 += 20;
                    y6 += 20;
                    arr_rectangle[p2] = RRectangle(x5, y5, x6, y6, C);
                    v_rectangle.push_back(arr_rectangle[p2]);
                }
                break;
            }
            case Agregation_2:
            {
                p++;
                x1 += 50;
                y1 += 50;
                arr_circle1[p] = Circle(x1, y1, R, C);
                v_circle1.push_back(arr_circle2[p]);
                v_circle2.push_back(arr_circle1[p]);
                v_segment1.push_back(arr_segment1[p]);
                v_segment2.push_back(arr_segment2[p]);
                break;
            }
            case Invisible:
            {
                k = invisible(count, p, p2, k, C, v_circle1, v_circle2, v_segment1, v_segment2, v_rectangle);
                break;
            }
            case ChangeColor:
            {
                C = changecolor(count, p, p2, C, v_circle1, v_circle2, v_segment1, v_segment2, v_rectangle);
                break;
            }
            case Deformation:
            {
                if (count == 0)
                {
                    x = 150 / 2; y = 0 / 2; x1 = 300 / 2; y1 = 300 / 2; R = 300 / 2; C = COLOR; x2 = 225 / 2; y2 = 225 / 2; r = 150 / 2;
                    for (int i = 0; i <= p; i++)
                    {
                        v_circle1[i].draw(BGCOLOR);
                        v_circle2[i].draw(BGCOLOR);
                        v_segment1[i].draw(BGCOLOR);
                        v_segment2[i].draw(BGCOLOR);
                    }
                    v_circle1[0].Deformation(x2, y2, r, C);
                    v_circle2[0].Deformation(x1, y1, R, C);
                    v_segment1[0].Deformation(x, y, y, y1, C);
                    v_segment2[0].Deformation(y, x, x1, y, C);
                }
                else
                {
                    x5 = 0; y5 = 0; x6 = 420 / 2; y6 = 420 / 2;
                    for (int i = 0; i <= p2; i++)
                    {
                        v_rectangle[i].draw(BGCOLOR);
                    }
                    v_rectangle[0].Deformation(x5, y5, x6, y6, C);
                }
                break;
            }
            case Default:
            {
                x = 250; y = 100; x1 = 400; y1 = 400; R = 300; C = COLOR; x2 = 325; y2 = 325; r = 150;
                x3 = 150; y3 = 0; x4 = 300; y4 = 300;
                x5 = 0; y5 = 0; x6 = 420; y6 = 420;
                x7 = 100; y7 = 250;
                console_graphics.cls();
                v_circle1[0].Deformation(x2, y2, r, C);
                v_circle2[0].Deformation(x1, y1, R, C);
                v_segment1[0].Deformation(x, y, y3, y4, C);
                v_segment2[0].Deformation(y, x, x4, y3, C);
                v_rectangle[0].Deformation(x5, y5, x6, y6, C);
                for (int i = 1; i <= p; i++)
                {
                    v_circle1.pop_back();
                    v_circle2.pop_back();
                    v_segment1.pop_back();
                    v_segment2.pop_back();
                }
                for (int i = 1; i <= p2; i++)
                {
                    v_rectangle.pop_back();
                }
                p = 0; p2 = 0;
                break;
            }
            case Trajectory:
            {
                trajectory(count, u, u2, t_up, t_down, t_left, t_right, t, t_1, v_circle1, v_circle2, v_segment1, v_segment2, v_rectangle);
                break;
            }
            case Switch:
            {
                count = switcher(count);
                break;
            }
            }
    }
    return 0;
}