#ifndef FECHA_H_
#define FECHA_H_
class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int = 3, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
	int convierte();
	bool leapyr();
	int masVieja( Fecha &f2);
	int masViejaObj(Fecha f2);
	int masViejaC(Fecha* f2);
};
#endif