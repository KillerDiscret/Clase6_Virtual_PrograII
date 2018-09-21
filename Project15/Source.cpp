#include <conio.h>
#include <iostream>
using namespace std;
using namespace System;
class Barquito
{
private:
	int x, y, dx, dy;
	int cont, aux, color;
public:
	Barquito(int x, int y, int dx, int dy);
	~Barquito();
	void Pintar();
	void Borrar();
	void Mover();
};
Barquito::Barquito(int X, int Y, int DX, int DY)
{
	x = X;
	y = Y;
	dx = DX;
	dy = DY;
	cont = 0;
	aux = 1;
	color = 0;
}
void Barquito::Pintar()
{
	Console::ForegroundColor = System::ConsoleColor(6);
	Console::SetCursorPosition(x, y);
	cout << "   _||_";
	Console::SetCursorPosition(x, y + 1);
	cout << "  _,...,";
	Console::SetCursorPosition(x, y+2);
	cout << " _, .....=,_";
	Console::SetCursorPosition(x, y + 3);
	cout << "\\__o_o_o__/";
	Console::ForegroundColor = System::ConsoleColor(color);
	Console::SetCursorPosition(x, y + 4);
	cout << "~~~~~~~~~~~";
}
void Barquito::Borrar()
{
	Console::SetCursorPosition(x,y);
	cout << "             ";
	Console::SetCursorPosition(x, y+1);
	cout << "             ";
	Console::SetCursorPosition(x, y+2);
	cout << "             ";
	Console::SetCursorPosition(x, y+3);
	cout << "            ";
	Console::SetCursorPosition(x, y+4);
	cout << "            ";
}
void Barquito::Mover()
{
	if (x+dx<0||x+dx+11>79)
	{
		dx *= -1;
	}
	x += dx;
	cont= cont+1;
	if (cont>=2)
	{
		if (aux>0)
		{
			y++;
			color = 13;
		}
		else
		{
			y--;
			color = 9;
		}
		aux *= -1;
		cont = 0;
	}
}
Barquito::~Barquito()
{

}
int main() 
{
	Console::Title = "ASCII ART";
	int linea;
	cout << "Ingrese linea: ";
	cin >> linea;
	Console::CursorVisible = false;
	Barquito *obj = new Barquito(1,linea,1,1);
	obj->Pintar();
	while (1)
	{
		obj->Borrar();
		obj->Mover();
		obj->Pintar();
		_sleep(60);
	}
	_getch();
}