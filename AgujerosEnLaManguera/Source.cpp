
/*@ <answer>
 *
 * Nombre y Apellidos: Cristóbal Saraiba Torres
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

int sol(const int &numAgujeros, const int &longParches, vector<int> agujeros){
    int parchesNecesarios = 1, agujeroActual;
    agujeroActual = agujeros[0];

    for(int i = 1; i < numAgujeros; i++){
        if(agujeros[i] - longParches > agujeroActual){
            parchesNecesarios++;
            agujeroActual = agujeros[i];
        }
    }

    return parchesNecesarios;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int numAgujeros, longParches;
   std::cin >> numAgujeros >> longParches;
   if (!std::cin)  // fin de la entrada
      return false;
   
    vector<int> agujeros;
    int agujero;
    for(int i = 0; i < numAgujeros; i++){
        cin >> agujero;
        agujeros.push_back(agujero);
    }

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
    cout << sol(numAgujeros, longParches, agujeros) << "\n";

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
