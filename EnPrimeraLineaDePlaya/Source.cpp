
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

struct tEdificio{
    int ini;
    int fin;
};

bool operator <(const tEdificio &e1, const tEdificio &e2){
    return (e1.fin < e2.fin);
}

int sol(const int &nEdificios, vector<tEdificio> edificios){
    int nTuneles = 1;
    tEdificio aux = edificios[0];

    for(int i = 1; i < nEdificios; ++i){
        if(aux.fin <= edificios[i].ini){
            aux = edificios[i];
            nTuneles++;
        }
    }

    return nTuneles;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int nEdificios;
   std::cin >> nEdificios;
   if (nEdificios == 0)
      return false;
   
    std::vector<tEdificio> edificios;
    int ini, fin;
    for(int i = 0; i < nEdificios; ++i){
        std::cin >> ini >> fin;
        edificios.push_back({ini, fin});
    }
    sort(edificios.begin(), edificios.end());

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución

    cout << sol(nEdificios, edificios) << "\n";

   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
