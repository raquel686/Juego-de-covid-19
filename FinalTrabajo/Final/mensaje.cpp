#include "pch.h"
mensaje::mensaje(int _x, int _y, int _dx, int _dy) :celemento() {
	Bitmap^ img = gcnew Bitmap("mensaje.png");
	x = _x; y = _y;
	dy = _dy;
	dx = _dx;
	ancho = img->Width / 4;
	alto = img->Height;
	delete img;
}
mensaje::~mensaje() {}
void mensaje::dibujar(Graphics^ g) {
	Bitmap^ imgtranspa = gcnew Bitmap("mensaje.png");
	imgtranspa->MakeTransparent(imgtranspa->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(imgtranspa, x, y, porcion, GraphicsUnit::Pixel);
	indx++;
	if (indx >= 4) {
		indx = 0;
	}
	delete imgtranspa;
}
void mensaje::mover(Graphics^ g) {
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
//void mensaje::setdireccion(int _dx, int _dy) {
//	dx = _dx; dy = _dy;
//}
