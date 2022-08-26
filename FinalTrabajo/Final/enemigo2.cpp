#include "pch.h"
enemigo2::enemigo2(int px, int py) :celemento() {
	Random s;
	int d[2] = { 0,8 };
	Bitmap^ img = gcnew Bitmap("saludable.png");
	x = px;
	y = py;
	dx = d[s.Next(0, 2)];
	dy = d[s.Next(0, 2)];
	if (dx == 0 && dy == 0) { dx = 10; dy = 0; }
	ancho = img->Width / 4;
	alto = img->Height / 8;
	cambio = 0;
	delete img;
}
enemigo2::~enemigo2() {}
void enemigo2::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("saludable.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(img, x, y, porcion, GraphicsUnit::Pixel);
	indx++;
	if (indx == 4)
		indx = 0;
	delete img;
}
void enemigo2::mover(Graphics^ g) {
	if (x + dx + ancho > g->VisibleClipBounds.Width || x + dx < 0)
		dx = dx * -1;
	if (y + dy + alto > g->VisibleClipBounds.Height || y + dy < 0)
		dy = dy * -1;
	x = x + dx;
	y = y + dy;
	if (cambio == 0) {
		if (dx > 0 && dy > 0 || dx == 0 && dy > 0 || dx < 0 && dy > 0) { indy = 0; diresalu = direccion::abajo; }
		if (dx == 0 && dy < 0 || dx < 0 && dy < 0 || dx > 0 && dy < 0) { indy = 1; diresalu = direccion::arriba; }
		if (dx > 0 && dy == 0) { indy = 3; diresalu = direccion::derecha; }
		if (dx < 0 && dy == 0) { indy = 2;  diresalu = direccion::izquierda; }
	}
	else {
		if (dx > 0 && dy > 0 || dx == 0 && dy > 0 || dx < 0 && dy > 0) { indy = 4; diresalu = direccion::abajo; }
		if (dx == 0 && dy < 0 || dx < 0 && dy < 0 || dx > 0 && dy < 0) { indy = 5; diresalu = direccion::arriba; }
		if (dx > 0 && dy == 0) { indy = 7; diresalu = direccion::derecha; }
		if (dx < 0 && dy == 0) { indy = 6; diresalu = direccion::izquierda; }
	}
}
void enemigo2::setcambio(int _c) {
	cambio = _c;
}
int enemigo2::getcambio() { return cambio; }
void enemigo2::agregarbala() {
	int pdx, pdy;
	switch (diresalu)
	{
	case direccion::arriba:    pdx = 0;  pdy = -15; break;
	case direccion::abajo:		pdx = 0;  pdy = 15; break;
	case direccion::izquierda: pdx = -15; pdy = 0; break;
	case direccion::derecha:   pdx = 15;  pdy = 0; break;
	case direccion::ninguno:   pdx = 0;  pdy = 15; break;
	}
	balasalu* obj = new balasalu(x + 3, y + 3, pdx, pdy);
	arrbal.push_back(obj);
}
void enemigo2::dibujarbala(Graphics^ g) {
	for each (balasalu * obj in arrbal)
		obj->dibujar(g);
}
void enemigo2::moverbala(Graphics^ g) {
	for each (balasalu * obj in arrbal)
		obj->mover(g);
}
void enemigo2::eliminarbalaporpos(int pos) {
	vector<balasalu*>::iterator it = arrbal.begin();
	arrbal.erase(it + pos);
}
void enemigo2::eliminarbala(Graphics^ g) {
	int maxan = g->VisibleClipBounds.Width;
	int maxal = g->VisibleClipBounds.Height;
	for (int i = 0; i < arrbal.size(); i++) {
		if (arrbal[i]->getx() < 1 || arrbal[i]->getx() + arrbal[i]->getancho() > maxan - 1 ||
			arrbal[i]->gety() < 1 || arrbal[i]->gety() + arrbal[i]->getalto() > maxal - 1) {
			arrbal.erase(arrbal.begin() + i);
		}
	}
}
balasalu* enemigo2::getbala(int i) { return arrbal[i]; }
int enemigo2::getcantbal() { return arrbal.size(); }
void enemigo2::limpiarbala() { arrbal.clear(); }

