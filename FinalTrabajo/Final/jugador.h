#pragma once
enum direccion { izquierda, derecha, ninguno, arriba, abajo };
class cjugador :public celemento
{
private:
	vector<mensaje*>arrm;
	direccion direcjug;
	
public:
	cjugador();
	~cjugador();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g, direccion dir);
	void agregarmensaje();
	void dibujarmensaje(Graphics^ g);
	void movermensajes(Graphics^ g);
	void eliminarmen(int pos);
	void eliminarmens(Graphics^ g);
	mensaje* getmensaje(int i);
	int getcantmen();
	void limpiarbala();
};



