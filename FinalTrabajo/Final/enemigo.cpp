#include "pch.h"
enemigo::enemigo(int _x, int _y) :celemento() {
	Random s;
	int d[3] = { 0,8 };
	Bitmap^ img = gcnew Bitmap("asintomatico.png");
	x = _x;
	y = _y;
	//dx = s.Next(0, 10);
	//dy = s.Next(0, 10);
	dx = d[s.Next(0, 2)];
	dy = d[s.Next(0, 2)];
	if (dx == 0 && dy == 0) { dx = 10; dy = 0; }
	ancho = img->Width / 4;
	alto = img->Height / 8;
	cambio = 0;
	delete img;
}
enemigo::~enemigo() {}
void enemigo::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("asintomatico.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(img, x, y, porcion, GraphicsUnit::Pixel);
	indx++;
	if (indx == 4)
		indx = 0;
	delete img;
}
void enemigo::mover(Graphics^ g) {
	if (x + dx + ancho > g->VisibleClipBounds.Width || x + dx < 0)
		dx = dx * -1;
	if (y + dy + alto > g->VisibleClipBounds.Height || y + dy < 0)
		dy = dy * -1;
	x = x + dx;
	y = y + dy;
	if (cambio == 0) {
		if (dx > 0 && dy > 0 || dx == 0 && dy > 0 || dx < 0 && dy > 0) { indy = 0; direnem = direccion::abajo; }
		if (dx == 0 && dy < 0 || dx < 0 && dy < 0 || dx > 0 && dy < 0) { indy = 3; direnem = direccion::arriba; }
		if (dx > 0 && dy == 0) { indy = 1; direnem = direccion::derecha; }
		if (dx < 0 && dy == 0) { indy = 2; direnem = direccion::izquierda; }
	}
	else {
		if (dx > 0 && dy > 0 || dx == 0 && dy > 0 || dx < 0 && dy > 0) { indy = 4; direnem = direccion::abajo; }
		if (dx == 0 && dy < 0 || dx < 0 && dy < 0 || dx > 0 && dy < 0) { indy = 7; direnem = direccion::arriba; }
		if (dx > 0 && dy == 0) { indy = 5;  direnem = direccion::derecha; }
		if (dx < 0 && dy == 0) { indy = 6; direnem = direccion::izquierda; }
	}
}
void enemigo::setcambio(int _c) {
	cambio = _c;
}
void enemigo::agregarbala() {
	int pdx, pdy;
	switch (direnem)
	{
	case direccion::arriba:    pdx = 0;  pdy = -15; break;
	case direccion::abajo:		pdx = 0;  pdy = 15; break;
	case direccion::izquierda: pdx = -15; pdy = 0; break;
	case direccion::derecha:   pdx = 15;  pdy = 0; break;
	case direccion::ninguno:   pdx = 0;  pdy = 15; break;
	}
	balaenem* obj = new balaenem(x + 3, y + 3, pdx, pdy);
	arrbal.push_back(obj);
}
void enemigo::dibujarbala(Graphics^ g) {
	for each (balaenem * obj in arrbal)
		obj->dibujar(g);
}
void enemigo::moverbala(Graphics^ g) {
	for each (balaenem * obj in arrbal)
		obj->mover(g);
}
void enemigo::eliminarbalaporpos(int pos) {
	vector<balaenem*>::iterator it = arrbal.begin();
	arrbal.erase(it + pos);
}
void enemigo::eliminarbala(Graphics^ g) {
	int maxan = g->VisibleClipBounds.Width;
	int maxal = g->VisibleClipBounds.Height;
	for (int i = 0; i < arrbal.size(); i++) {
		if (arrbal[i]->getx() < 1 || arrbal[i]->getx() + arrbal[i]->getancho() > maxan - 1 ||
			arrbal[i]->gety() < 1 || arrbal[i]->gety() + arrbal[i]->getalto() > maxal - 1) {
			arrbal.erase(arrbal.begin() + i);
		}
	}
}
balaenem* enemigo::getbala(int i) { return arrbal[i]; }
int enemigo::getcantbal() { return arrbal.size(); }
int enemigo::getcambio() { return cambio; }
void enemigo::limpiarbala() { arrbal.clear(); }
