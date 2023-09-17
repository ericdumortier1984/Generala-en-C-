#include <iostream>
#include <ctime>

using namespace std;

int valoresAlazar();
void tirarDados(int valores[5]);
int puntuacion(const int valores[5]);
int maximo(const int valores[5]);
void ordenar(int valores[5]);
int caraDado(const int valores[5], int valor);
bool full(const int valores[5]);
bool poker(const int valores[5]);
bool escalera(const int valores[5]);
bool generala(const int valores[5]);

int valoresAlazar()
{
	return rand() % 6 + 1;
}

void tirarDados(int valores[5])
{
	for (int i = 0; i < 5; i++)
		valores[i] = valoresAlazar();
	
	ordenar(valores);
	
	for (int i = 0; i < 5; i++)
		cout << valores[i] << " ";
}

int puntuacion(const int valores[5])
{
	int puntos[6];
	
	puntos[0] = caraDado(valores, 1);
	puntos[1] = caraDado(valores, 2);
	puntos[2] = caraDado(valores, 3);
	puntos[3] = caraDado(valores, 4);
	puntos[4] = caraDado(valores, 5);
	puntos[5] = caraDado(valores, 6);
	
	cout << endl;
	cout << "Todo al 1: " << puntos[0] << endl;
	cout << "Todo al 2: " << puntos[1] << endl;
	cout << "Todo al 3: " << puntos[2] << endl;
	cout << "Todo al 4: " << puntos[3] << endl;
	cout << "Todo al 5: " << puntos[4] << endl;
	cout << "Todo al 6: " << puntos[5] << endl;
	
	if (generala(valores))
	{
		cout << "Generala: 60" << endl;
		return 60;
	}
	else if (escalera(valores))
	{
		cout << "Escalera: 50" << endl;
		return 50;
	}
	else if (poker(valores))
	{
		cout << "Poker: 40" << endl;
		return 40;
	}
	else if (full(valores))
	{
		cout << "Full: 30" << endl;
		return 30;
	}
	else
		return maximo(puntos);
	
}

int maximo(const int valores[6])
{
	int max;
	
	for (int i = 0; i < 6; i++)
	{
		if (i == 0 || valores[i] > max)
			max = valores[i];
	}
	return max;
}

int caraDado(const int valores[5], int valor)
{
	int suma = 0;
	
	for (int i = 0; i < 5; i++)
	{
		if (valores[i] == valor)
			suma += valores[i];
	}
	return suma;
}

void ordenar(int valores[5])
{
	int valor;
	int j;
	
	for (int i = 1; i < 6; i++) {
		valor = valores[i];
		j = i;
		while (j > 0 && valor < valores[j-1]) {
			valores[j] = valores[j-1];
			j--;
		}
		valores[j] = valor;
	}
}

bool full(const int valores[5])
{
	int numero1, numero2 = 0, contador1 = 1, contador2 = 0;
	
	numero1 = valores[0];
	for (int i = 1; i < 5; i++)
	{
		if (numero1 == valores[i])
			contador1++;
		else if (numero2 == 0)
		{
			numero2 = valores[i];
			contador2++;
		}
		else if (numero2 == valores[i])
			contador2++;
	}
	
	return ((contador1 == 3 && contador2 == 2) || (contador2 == 3 && contador1 == 2));
}

bool poker(const int valores[5])
{
	int numero1, numero2 = 0, contador1 = 1, contador2 = 0;
	
	numero1 = valores[0];
	for (int i = 1; i < 5; i++)
	{
		if (numero1 == valores[i])
			contador1++;
		else if (numero2 == 0)
		{
			numero2 = valores[i];
			contador2++;
		}
		else if (numero2 == valores[i])
			contador2++;
	}
	
	return (contador1 == 4 || contador2 == 4);
}

bool escalera(const int valores[5])
{
	if (valores[0] == 1 || valores[0] == 2)
	{
		for (int i = 1; i < 5; i++)
		{
			if (valores[i] != valores[i - 1] + 1)
				return false;
		}
	}
	else
		return false;
	
	return true;
}
bool generala(const int valores[5])
{
	for (int i = 1; i < 5; i++)
	{
		if (valores[i] != valores[i - 1])
			return false;
	}
	
	return true;
}


int main(int argc, char *argv[]) {
{
	int jugador, pc;
	int dadosJugador[5];
	int dadosPc[5];
	
	srand(time(NULL));
	
	cout << "Tirada del Jugador: ";
	tirarDados(dadosJugador);
	jugador = puntuacion(dadosJugador);
	cout << "=================" << endl;
	cout << "Puntuacion maxima: " << jugador << endl;
	
	cout << "=================" << endl;
	cout << endl << "Tirada del PC: ";
	tirarDados(dadosPc);
	pc = puntuacion(dadosPc);
	cout << "=================" << endl;
	cout << "Puntuacion maxima: " << pc << endl;
	cout << "=================" << endl;
	
	cout << endl << "=================";
	cout << endl << "Ganador: ";
	if (pc < jugador)
		cout << "Jugador";
	else if (pc > jugador)
		cout << "Pc";
	else
		cout << "Empate";
	
	cout << endl;
	cout << "=================";
	
	return 0;
}
}

