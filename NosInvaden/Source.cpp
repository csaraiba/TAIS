
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
 Para este ejercicio utilizaremos dos vectores que almacenarán los equipos enemigos y defensa, recorremos los enemigos de menor a mayor 
 y la solución voraz V selecciona la defensa más pequeña de las que quedan que le permite ganar (si hay alguna). Las derrotas da igual 
 cómo se asignen. Por tanto, el aspecto de la solución voraz es una secuencia creciente de índices de defensas (que permiten ganar) y 
 luego el resto son derrotas que en realidad da igual cómo se asignen.

 El coste es de O(N log N) donde N es el número de ciudades a defender (La parte de log N corresponde a la ordenación).
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int sol(const int &ciudades, vector<int> enemigos, vector<int> defensa){
    int victorias = 0, posE = 0, posA = 0; //Victorias corresponde al número de veces que el equipo aliado supera al enemigo
    //posE será la posición en el vector de enemigos y posA la posición en el vector de aliados
    
    while(posA < ciudades){ //Mientras no hayamos comprobado todas las defensas (Que serán iguales al número de ciudades)
        if(enemigos[posE] <= defensa[posA]){ //Si los aliados superan a los enemigos aumentamos las victorias y la posición para comprobar la siguiente ciudad atacada
            victorias++;
            posE++;
        }
        posA++; //En cualquier caso o usamos o descartamos la defensa
    }
    
    return victorias;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
    int ciudades;
    std::cin >> ciudades;
   if (!std::cin)  // fin de la entrada
      return false;
   
    std::vector<int> enemigos;
    std::vector<int> defensa;

    //Metemos los equipos enemigos y aliados cada uno en su vector propio y los ordenamos para ir sacando el menor primero
    int efectivos;
    for(int i = 0; i < ciudades; i++){
        cin >> efectivos;
        enemigos.push_back(efectivos);
    }
    sort(enemigos.begin(), enemigos.end(), less<int>());

    for(int i = 0; i < ciudades; i++){
        cin >> efectivos;
        defensa.push_back(efectivos);
    }
    sort(defensa.begin(), defensa.end(), less<int>());

   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   cout << sol(ciudades, enemigos, defensa) << "\n";

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
