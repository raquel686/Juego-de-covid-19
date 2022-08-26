#include "pch.h"
celemento::celemento() {
	indx = 0; indy = 0;
}
celemento::~celemento() {}

Rectangle celemento::getarea() {
	return Rectangle(x, y, ancho, alto);
}
int celemento::getx() { return x; }
int celemento::gety() { return y; }
int celemento::getancho() { return ancho; }
int celemento::getalto() { return alto; }
int celemento::getindx() { return indx; }
void celemento::setdireccion() { dx = dx * -1; dy = dy * -1; }
