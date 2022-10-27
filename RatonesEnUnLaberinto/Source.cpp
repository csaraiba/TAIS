/*@ <answer>
 *
 * Nombre y Apellidos: Cristóbal Saraiba Torres
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#include "DigrafoValorado.h" // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Para este ejercicio utilizaremos el algoritmo de Dijkstra, inicialmente tomaremos las variables necesarias que nos darán de entrada y que nos servirán para 
 construir el grafo y determinar cual es el origen (la salida para los ratones). Tras construir el grafo utilizaremos la función "inverso" del digrafo valorado 
 para así convertir lo que sería la salida de los ratones en nuestro origen para el algoritmo de Dijkstra y solo tener que comprobar si (además de ser alcanzable) 
 el coste para llegar a al vértice (que no sea el propio de origen/salida) es menor al tiempo límite que nos permiten y en ese caso añadir un ratón más que podrá 
 llegar a la salida.

 El coste de la solución es el del algoritmo de Dijsktra, O(A log V) con un espacio adicional en O(V) siendo V los vérices y A las aristas
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class Dijkstra {

private:
    const int INF = std::numeric_limits<int>::max();
	std::vector<int> dist;
	IndexPQ<int> pq;
    int origen;

	void relajar(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()){
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}

public:
	Dijkstra(DigrafoValorado<int> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto e : g.ady(v)) {
				relajar(e);
			}
		}
	}

	bool hayCamino(int v) const {
		return dist[v] != INF;
	}

	int valor(int v) const {
		return dist[v];
	}
};

bool resuelveCaso() {


   // leer los datos de la entrada
   	int N,S,T, P; //N es el número de celdas del laberinto, S es el número de la celda donde se encuentra la salida, T es el número de segundos, P es el número de pasadizos
	cin >> N >> S >> T >> P;
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   
   // escribir la solución
	
	DigrafoValorado<int> g(N);

    for(int i = 0; i < P; i++){
        int v, w, coste;
        std::cin >> v >> w >> coste;
        g.ponArista(AristaDirigida<int>(v-1, w-1, coste));
    }
	Dijkstra dij(g.inverso(), S - 1);

	int ratones = 0;
	for (int i = 0; i < N; i++) {
		if (dij.hayCamino(i) && dij.valor(i) <= T && i != S - 1) {
			ratones++;
		}
	}

	cout << ratones << "\n";
    
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