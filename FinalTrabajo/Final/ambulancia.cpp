#include "pch.h"
ambulancia::ambulancia(int _x, int _y) :celemento() {
	Random e;
	/*int d[3] = { 0,10 };*/
	Bitmap^ img = gcnew Bitmap("enfermera.png");
	x = _x;
	y = _y;
	dx = e.Next(5, 10);
	dy = e.Next(5, 10);
	/*dx = d[s.Next(0, 2)];
	dy = d[s.Next(0, 2)];*/
	if (dx == 0 && dy == 0)
		dx = 12;
	ancho = img->Width / 4;
	alto = img->Height / 4;
	delete img;
}
ambulancia::~ambulancia() {}
void ambulancia::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("enfermera.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(img, x, y, porcion, GraphicsUnit::Pixel);
	indx++;
	if (indx == 4)
		indx = 0;
	delete img;
}
void ambulancia::mover(Graphics^ g) {
	if (x + dx + ancho > g->VisibleClipBounds.Width || x + dx < 0)
		dx = dx * -1;
	if (y + dy + alto > g->VisibleClipBounds.Height || y + dy < 0)
		dy = dy * -1;
	x = x + dx;
	y = y + dy;
	if (dx > 0 && dy > 0 || dx == 0 && dy > 0 || dx < 0 && dy > 0) { indy = 0; }
	if (dx == 0 && dy < 0 || dx < 0 && dy < 0 || dx > 0 && dy < 0) { indy = 3; }
	if (dx > 0 && dy == 0) { indy = 2; }
	if (dx < 0 && dy == 0) { indy = 1; }

}