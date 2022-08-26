#include "pch.h"
cjugador::cjugador() :celemento() {
	Bitmap^ img = gcnew Bitmap("jugador.png");
	x = 40; y = 150;
	ancho = img->Width / 3;
	alto = img->Height / 4;
	direcjug = direccion::ninguno;
	dx = 0;
	dy = 0;
	delete img;
}
cjugador::~cjugador() {}
void cjugador::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("jugador.png");
	img->MakeTransparent(img->GetPixel(1, 1));
	Rectangle porcion = Rectangle(ancho * indx, alto * indy, ancho, alto);
	g->DrawImage(img, x, y, porcion, GraphicsUnit::Pixel);
	indx++;
	if (indx == 3)
		indx = 0;
	delete img;
}
void cjugador::mover(Graphics^ g, direccion dir) {
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
	switch (dir)
	{
	case arriba:    dx = 0;  dy = -10; direcjug = direccion::arriba; indy = 3; break;
	case abajo:		dx = 0;  dy = 10; direcjug = direccion::abajo; indy = 0; break;
	case izquierda: dx = -10; dy = 0; direcjug = direccion::izquierda; indy = 2;	break;
	case derecha:   dx = 10;  dy = 0; direcjug = direccion::derecha; indy = 1;	break;
	case ninguno:   dx = 0;  dy = 0; direcjug = direccion::ninguno; break;
	}
}
void cjugador::agregarmensaje() {
	int pdx, pdy;
	switch (direcjug)
	{
	case direccion::arriba:    pdx = 0;  pdy = -10; break;
	case direccion::abajo:		pdx = 0;  pdy = 10; break;
	case direccion::izquierda: pdx = -10; pdy = 0; break;
	case direccion::derecha:   pdx = 10;  pdy = 0; break;
	case direccion::ninguno:   pdx = 0;  pdy = 10; break;
	}
	mensaje* obj = new mensaje(x + 5, y + 5, pdx, pdy);
	arrm.push_back(obj);
}
void cjugador::dibujarmensaje(Graphics^ g) {
	for each (mensaje * obj in arrm)
		obj->dibujar(g);
}
void cjugador::movermensajes(Graphics^ g) {
	for each (mensaje * obj in arrm)
		obj->mover(g);
}
mensaje* cjugador::getmensaje(int i) {
	return arrm[i];
}
int cjugador::getcantmen() {
	return arrm.size();
}
void cjugador::eliminarmen(int pos) {
	vector<mensaje*>::iterator it = arrm.begin();
	arrm.erase(it + pos);
}
void cjugador::eliminarmens(Graphics^ g) {
	int maxan = g->VisibleClipBounds.Width;
	int maxal = g->VisibleClipBounds.Height;
	for (int i = 0; i < arrm.size(); i++) {
		if (arrm[i]->getx() < 1 || arrm[i]->getx() + arrm[i]->getancho() > maxan - 1 ||
			arrm[i]->gety() < 1 || arrm[i]->gety() + arrm[i]->getalto() > maxal - 1) {
			arrm.erase(arrm.begin() + i);
		}
	}

}
void cjugador::limpiarbala() { arrm.clear(); }
