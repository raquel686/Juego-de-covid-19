#include "pch.h"

balaenem::balaenem(int _x, int _y, int _dx, int _dy) {
	Bitmap^ img = gcnew Bitmap("balaenemigo.png");
	x = _x; y = _y;
	dy = _dy;
	dx = _dx;
	ancho = img->Width;
	alto = img->Height;
	delete img;
}
balaenem::~balaenem() {}
void balaenem::dibujar(Graphics^ g) {
	Bitmap^ imgtranspa = gcnew Bitmap("balaenemigo.png");
	imgtranspa->MakeTransparent(imgtranspa->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(imgtranspa, x, y, porcion, GraphicsUnit::Pixel);
	delete imgtranspa;
}
void balaenem::mover(Graphics^ g) {
	x = x + dx;
	y = y + dy;
	if (x + dx < 0)
		x = 0;
	if (x + dx + ancho > g->VisibleClipBounds.Width)
		x = g->VisibleClipBounds.Width - ancho;
	if (y + dy < 0)
		y = 0;
	if (y + dy + alto > g->VisibleClipBounds.Height)
		y = g->VisibleClipBounds.Height - alto;
}
