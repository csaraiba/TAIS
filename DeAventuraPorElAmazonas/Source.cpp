
/*@ <answer>
 *
 * Nombre y Apellidos: Cristóbal Saraiba Torres
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El coste de la solución es del orden de O(n^3) tanto en espacio como 
 en tiempo donde n es el número de poblados.
 


 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

const int INF = 1000000000;

std::vector<int> resolver(Matriz<int> &v, int nPoblados, int ini) {
    Matriz<int> m(nPoblados, nPoblados + 1, INF);
    m[ini - 1][ini - 1] = 0;
    for (int i = ini; i < nPoblados; ++i) {
        m[ini-1][i] = 0;
        for (int j = ini; j <= nPoblados; ++j) {
            if (i >= j) {
                m[i][j] = m[i - 1][j];
            }
            else {
                int n = m[i-1][i] + v[i - 1][j - i];
                m[i][j] = std::min(m[i-1][i] + v[i-1][j-i], m[i-1][j]);
            }
        }
    }

    return m[nPoblados-1];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nPoblados, coste;
    std::cin >> nPoblados;

    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> entrada(nPoblados, nPoblados, 0);
    for (int i = 0; i < nPoblados-1; ++i) {
        for (int j = 1; j < nPoblados - i; ++j) {
            std::cin >> coste;
            entrada[i][j] = coste;
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 1; i <= nPoblados - 1; ++i) {
        std::vector<int> sol = resolver(entrada, nPoblados, i);
        for (int j = i + 1; j < sol.size(); ++j) {
            std::cout << sol[j] << " ";
        }
        std::cout << "\n";
    }
   
    // escribir la solución
    
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
