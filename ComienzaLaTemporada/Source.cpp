
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
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int sol(vector<int> jugadores, vector<int> equipaciones){
   int camisetas = jugadores.size(), posE = 0, posJ = 0;

   while(posE < equipaciones.size() && posJ < jugadores.size()){ //Comprobamos mientras no nos hayamos pasado de equipaciones ni jugadores en los vectores
      if(jugadores[posJ] == equipaciones[posE] || jugadores[posJ] + 1 == equipaciones[posE]){ //Si el jugador coincide con la talla de camisetas o una mayor, es una camiseta menos que comprar y pasamos al siguiente jugador
         posJ++;
         camisetas--;
      }
      if(jugadores[posJ]+1 < equipaciones[posE]){ //Comprobamos que si la talla le queda demasiado grande no le valdrá el resto que quedan y saltamos al siguiente jugador
         posJ++;
      }else{
         posE++;
      }

   }

   return camisetas;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int nJugadores, nEquipaciones;
   std::cin >> nJugadores >> nEquipaciones;
   if (!std::cin)  // fin de la entrada
      return false;
   
    std::vector<int> jugadores;
    std::vector<int> equipaciones;
    for(int i = 0; i < nJugadores; i++){
        int jugador;
        cin >> jugador;
        jugadores.push_back(jugador);
    }
    for(int i = 0; i < nEquipaciones;i++){
        int equipacion;
        cin >> equipacion;
        equipaciones.push_back(equipacion);
    }
    sort(jugadores.begin(), jugadores.end(), less<int>());
    sort(equipaciones.begin(), equipaciones.end(), less<int>());

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cout << sol(jugadores, equipaciones) << "\n";

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
