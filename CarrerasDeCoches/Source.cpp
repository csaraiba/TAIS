
/*@ <answer>
 *
 * Nombre y Apellidos: Cristóbal Saraiba Torres
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Problema de tipo: Algoritmo voraz
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int sol(const int &minVoltaje, vector<int> pilas){
    int nCoches = 0, posIni = 0, posFin = pilas.size() - 1;

    while (posIni < posFin){
        if(pilas[posIni] + pilas[posFin] >= minVoltaje){
            nCoches++;
            posIni++;
        }
        posFin--;
    }


    return nCoches;
}

void resuelveCaso() {
   // leer los datos de la entrada
   int nPilas, minVoltaje;
   std::cin >> nPilas >> minVoltaje;
   std::vector<int> pilas;
   int pila;
   for(int i = 0; i < nPilas; i++){
    std::cin >> pila;
    pilas.push_back(pila);
   }
   sort(pilas.begin(), pilas.end(), std::greater<int>());

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   std::cout << sol(minVoltaje, pilas) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
