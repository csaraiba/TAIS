
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
 Para este ejercicio utilizaremos dos vectores que almacenarán los puntos conseguidos por el rival y por los Broncos, ordenados los del 
 rival de menor a mayor y los de los Broncos de mayor a menor. La solución voraz V selecciona los puntos enemigos menores y los puntos 
 de los Broncos mayores que le permiten así que la diferencia sea mayor. El aspecto de la solución voraz es una secuencia creciente de 
 diferencias de puntos y luego el resto son derrotas (diferencia en negativo) que no las tenemos en cuenta para la suma.

 FALTA DEMOSTRACIÓN DE LA CORRECIÓN DE LA ESTRATEGIA VORAZ


 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int sol(vector<int> puntosRivales, vector<int> puntosBroncos){
    int exito = 0, pos = 0;


    while(pos < puntosRivales.size()){
        int dif = puntosBroncos[pos] - puntosRivales[pos];
        if(dif < 0){ //Si lo que nos queda en el vector ya no nos va a dar victorias salimos del bucle
            pos = puntosRivales.size();
        }else{
            exito += dif;
        }
        pos++;
    }

    return exito;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   int nPartidos;
   cin >> nPartidos;
   if (nPartidos == 0)
      return false;
   

    int puntoAux;
    std::vector<int> puntosRivales;
    for(int i = 0; i < nPartidos; i++){
        std::cin >> puntoAux;
        puntosRivales.push_back(puntoAux);
    }
    sort(puntosRivales.begin(), puntosRivales.end(), less<int>());
    std::vector<int> puntosBroncos;
    for(int i = 0; i < nPartidos; i++){
        std::cin >> puntoAux;
        puntosBroncos.push_back(puntoAux);
    }
    sort(puntosBroncos.begin(), puntosBroncos.end(), greater<int>());
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cout << sol(puntosRivales, puntosBroncos) << "\n";

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
