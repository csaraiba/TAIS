
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

class grafoLibre {
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    int contVisitado;
    bool ciclo;
    
    void dfs(Grafo const& G, int v) {
        visit[v] = true;
        contVisitado++;
        for (int w : G.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(G, w);
            }else{
                if(ant[v] != w) ciclo = true;
            }
        }
    }
public:
    grafoLibre(Grafo const& g) : visit(g.V(), false), contVisitado(0), ant(g.V()), ciclo(false) {
            dfs(g, 0);
    }

    bool esLibre(){
        return (contVisitado == visit.size() && !ciclo);
    }
};

bool resuelveCaso() {
   
   // leer los datos de la entrada
   Grafo g(std::cin);
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   grafoLibre sol(g);
   // escribir la solución
   std::cout << (sol.esLibre() ? "SI\n" : "NO\n");

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
