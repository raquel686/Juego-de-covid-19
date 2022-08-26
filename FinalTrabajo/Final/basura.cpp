#include "pch.h"
basura::basura(int _x, int _y){
	Bitmap^ img = gcnew Bitmap("basuradib.png");
	x = _x; y = _y;
	ancho = img->Width;
	alto = img->Height;
	delete img;
}
basura::~basura(){}
void basura::dibujar(Graphics^ g){
	Bitmap^ img = gcnew Bitmap("basuradib.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(img, x, y, porcion, GraphicsUnit::Pixel);
	delete img;
}
