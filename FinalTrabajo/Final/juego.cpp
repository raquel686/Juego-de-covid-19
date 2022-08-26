#include "pch.h"
juego::juego() {
	vidajugador = 0;
	nivel = 1;
	puntaje = 0;
	numbasura = 0;
}
juego::~juego() {}
void juego::generarenem() {
	Random f;
	for (int i = 0; i < 1; i++) {
		arren.push_back(new enemigo(f.Next(5, 470), f.Next(5, 50)));
	}
}
void  juego::generasalu() {
	Random f;
	for (int i = 0; i < 1; i++) {
		arrsalu.push_back(new enemigo2(f.Next(5, 470), f.Next(5, 50)));
	}
}
void juego::generarjugador() {
	objjug = new cjugador();
}

void juego::generarpolicia() {
	Random t;
	for (int i = 0; i < 1; i++) {
		objpol.push_back(new policia(t.Next(5, 470), t.Next(5, 50)));
	}
}
void juego::generarenfermera() {
	Random t;
	for (int i = 0; i < 1; i++) {
		objenfer.push_back(new ambulancia(t.Next(5, 470), t.Next(5, 50)));
	}
}
void  juego::generabasura(){
	Random t;
	for (int i = 0; i < 1; i++) {
		arrbas.push_back(new basura(t.Next(5, 650), t.Next(5, 300)));
	}
}
void juego::dibujarenem(Graphics^ g) {
	objjug->dibujarmensaje(g);
	for each (policia * obj in objpol)
		obj->dibujar(g);
	for each (ambulancia * obj in objenfer)
		obj->dibujar(g);
	for each (enemigo * obj in arren)
		obj->dibujarbala(g);

	for each (enemigo * obj in arren)
		obj->dibujar(g);
	for each (enemigo2 * obj in arrsalu)
		obj->dibujarbala(g);
	for each (enemigo2 * obj in arrsalu)
		obj->dibujar(g);
	for each (basura * obj in arrbas)
		obj->dibujar(g);
}
void juego::moverenem(Graphics^ g) {
	for each (policia * obj in objpol)
		obj->mover(g);
	for each (ambulancia * obj in objenfer)
		obj->mover(g);
	objjug->movermensajes(g);
	for each (enemigo * obj in arren)
		obj->mover(g);
	for each (enemigo * obj in arren)
		obj->moverbala(g);
	for each (enemigo2 * obj in arrsalu)
		obj->mover(g);
	for each (enemigo2 * obj in arrsalu)
		obj->moverbala(g);
}
void juego::dibujarjugador(Graphics^ g) {
	objjug->dibujar(g);
}
void juego::moverjug(Graphics^ g, Keys key) {
	if (key == Keys::Right)
		objjug->mover(g, direccion::derecha);
	if (key == Keys::Left)
		objjug->mover(g, direccion::izquierda);
	if (key == Keys::Up)
		objjug->mover(g, direccion::arriba);
	if (key == Keys::Down)
		objjug->mover(g, direccion::abajo);
}

void juego::disparo() {
	objjug->agregarmensaje();
}
void  juego::disparoasin() {
	for each (enemigo * obj in arren)
		obj->agregarbala();
}
void juego::disparosalu() {
	for each (enemigo2 * obj in arrsalu)
		obj->agregarbala();
}
int  juego::getvidajugador() { return vidajugador; }
void  juego::setvidajugador(int v) { vidajugador = v; }
void juego::colision() {
	mensaje* MEN;
	balaenem* BALASI;
	balasalu* BALASALU;
	if (arren.size() > 0) {
		for (int m = 0; m < objjug->getcantmen(); m++) {
			MEN = objjug->getmensaje(m);
			for (int e = 0; e < arren.size(); e++) {
				Rectangle area1 = MEN->getarea();
				Rectangle area2 = arren[e]->getarea();
				if (area1.IntersectsWith(area2)) {
					/*vector<enemigo*>::iterator it = arren.begin();
					arren.erase(it + e);*/
					objjug->eliminarmen(m);
					if (arren[e]->getcambio() == 0) {
						arren[e]->setcambio(1);
						puntaje = puntaje + 10;
					}
				}

			}
		}
		for each (enemigo * obj in arren) {
			for (int b = 0; b < obj->getcantbal(); b++) {
				BALASI = obj->getbala(b);
				Rectangle area1 = BALASI->getarea();
				Rectangle area2 = objjug->getarea();
				if (area1.IntersectsWith(area2)) {
					obj->eliminarbalaporpos(b);
					vidajugador--;

				}
			}
		}
		if (objpol.size() > 0) {
			for (int i = 0; i < arren.size(); i++) {
				for (int j = 0; j < objpol.size(); j++) {
					Rectangle area1 = objpol[j]->getarea();
					Rectangle area2 = arren[i]->getarea();
					if (area1.IntersectsWith(area2) && arren[i]->getcambio() == 1) {
						vector<enemigo*>::iterator it = arren.begin();
						arren.erase(it + i);

					}
				}
			}
		}
		for (int i = 0; i < arren.size(); i++) {
				Rectangle area1 = objjug->getarea();
				Rectangle area2 = arren[i]->getarea();
				if (area1.IntersectsWith(area2)) {
					vidajugador--;
					arren[i]->setdireccion();

				}
			
		}
	}

	if (arrsalu.size() > 0) {
		for (int m = 0; m < objjug->getcantmen(); m++) {
			MEN = objjug->getmensaje(m);
			for (int e = 0; e < arrsalu.size(); e++) {
				Rectangle area1 = MEN->getarea();
				Rectangle area2 = arrsalu[e]->getarea();
				if (area1.IntersectsWith(area2)) {
					objjug->eliminarmen(m);
					if (arrsalu[e]->getcambio() == 0) {
						arrsalu[e]->setcambio(1);
						puntaje = puntaje + 10;
					}
				}

			}
		}
		for each (enemigo2 * obj in arrsalu) {
			for (int b = 0; b < obj->getcantbal(); b++) {
				BALASALU = obj->getbala(b);
				Rectangle area1 = BALASALU->getarea();
				Rectangle area2 = objjug->getarea();
				if (area1.IntersectsWith(area2)) {
					obj->eliminarbalaporpos(b);
					vidajugador--;
				}
			}
		}
		if (objenfer.size() > 0) {
			for (int i = 0; i < arrsalu.size(); i++) {
				for (int j = 0; j < objenfer.size(); j++) {
					Rectangle area1 = objenfer[j]->getarea();
					Rectangle area2 = arrsalu[i]->getarea();
					if (area1.IntersectsWith(area2) && arrsalu[i]->getcambio() == 1) {
						vector<enemigo2*>::iterator it = arrsalu.begin();
						arrsalu.erase(it + i);

					}
				}
			}
		}
		for (int i = 0; i < arrsalu.size(); i++) {
			Rectangle area1 = objjug->getarea();
			Rectangle area2 = arrsalu[i]->getarea();
			if (area1.IntersectsWith(area2)) {
				vidajugador--;
				arrsalu[i]->setdireccion();
			}

		}

	}
	if (arrbas.size() > 0) {
		for (int i = 0; i < arrbas.size(); i++) {
			Rectangle area1 = objjug->getarea();
			Rectangle area2 = arrbas[i]->getarea();
			if (area1.IntersectsWith(area2)) {
				numbasura++;
				vector<basura*>::iterator it = arrbas.begin();
				arrbas.erase(it + i);
			}
		}
	}
	if (numbasura >= 3) {
		puntaje = puntaje + 10;
		numbasura = 0;
	}
}
void juego::eliminarmen(Graphics^ g) {
	objjug->eliminarmens(g);
	for each (enemigo * obj in arren)
		obj->eliminarbala(g);
	for each (enemigo2 * obj in arrsalu)
		obj->eliminarbala(g);
}
int juego::getcantasin() { return arren.size(); }
int juego::getcantsalu() { return arrsalu.size(); }
int juego::getpuntaje() { return puntaje; }
void juego::setpuntaje(int p) { puntaje = p; }
int juego::gettiempo() { return tiempo; }
void juego::settiempo(int t) { tiempo = t; }
int juego::getnivel() { return nivel; }
int  juego::getbolsasreco() { return numbasura; }
void juego::pasarnivel(Timer^ t,Timer^t2, Timer^ t3, Timer^ t4, int time,int cantotal){	
	if ( puntaje>=cantotal*5 && puntaje>0) {
		nivel = nivel + 1;
		puntaje = 0;
		t->Enabled = true;
		t2->Enabled = true;
		t3->Enabled = true;
		t4->Enabled = true;
		arren.clear();
		arrsalu.clear();
		arrbas.clear();
		objpol.clear();
		objenfer.clear();
		settiempo(time);
		for each (enemigo * obj in arren)
			obj->limpiarbala();
		for each (enemigo2 * obj in arrsalu)
			obj->limpiarbala();
		objjug->limpiarbala();
	}
}

