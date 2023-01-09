
/*@ <answer>
 *
 * Nombre y Apellidos: Cristóbal Saraiba Torres
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

using Mapa = vector<string>;

class Manchas {
public:
   Manchas(Mapa const& M) : F(M.size()), C(M[0].size()), visit(F, vector<bool>(C, false)), num(0), maxim(0) {
      for (int i = 0; i < F; ++i) {
         for (int j = 0; j < C; ++j) {
            if (!visit[i][j] && M[i][j] == '#') { // se recorre una nueva mancha
               ++num;
               int nuevotam = dfs(M, i, j);
               maxim = max(maxim, nuevotam);
            }
         }
      }
   }

   int numero() const { return num; }
   
   int maximo() const { return maxim; }

private:
   int F, C; // tamaño del mapa
   vector<vector<bool>> visit; // visit[i][j] = se ha visitado el píxel <i,j>?
   int num; // número de manchas
   int maxim; // tamaño de la mancha más grande

   bool correcta(int i, int j) const {
      return 0 <= i && i < F && 0 <= j && j < C;
   }

   const vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
   int dfs(Mapa const& M, int i, int j) {
      visit[i][j] = true;
      int tam = 1;
      for (auto d : dirs) {
         int ni = i + d.first, nj = j + d.second;
         if (correcta(ni,nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
            tam += dfs(M, ni, nj);
         }
      }
      return tam;
   }
};

bool resuelveCaso() { // O(F*C)
   int F, C;
   cin >> F >> C; // número de filas y columnas
   if (!cin) return false;
   Mapa mapa(F);
// leemos la imagen
   for (string & linea : mapa)
      cin >> linea;
// la analizamos
   Manchas manchas(mapa);
   cout << manchas.numero() << ' ' << manchas.maximo() << '\n';
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
