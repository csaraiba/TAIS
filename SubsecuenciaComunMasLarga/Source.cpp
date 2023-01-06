
/*@ <answer>
 *
 * Nombre y Apellidos: Cristóbal Saraiba Torres
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Tenemos dos palabras, s1 y s2 siendo s1[0....i] y s2[0....j], calculamos la 
 longitud de la subSecuencia tal que si la última letra es común debe estar 
 en la subsecuencia y si no lo es, puede estar o no (Si s1[i-1] y s2[j-1] son 
 iguales entonces sumamos 1 a esa posición de la matriz, si no son iguales 
 entonces tomamos el máximo de entre matrizSec[i-1][j] y matrizSec[i][j-1]). Tras eso si los caracteres 
 de i, j coinciden los añadimos a la solución y en caso contrario relocalizamos.

 Casos base: subSecuencia(0, j) = 0; subSecuencia(i, 0) = 0


 Coste del problema: O(n*m) donde n es el tamaño de la primera secuencia y m
 el tamaño de la segunda
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

string subSecuencia(const string &s1, const string &s2){
    string palabra = "";

    int n = s1.size();
    int m = s2.size();
    Matriz<int> matrizSec(n + 1, m + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                matrizSec[i][j] = matrizSec[i-1][j-1] + 1;
            }
            else{
                matrizSec[i][j] = max(matrizSec[i-1][j], matrizSec[i][j-1]);
            }
        }
    }

    int tam = matrizSec[n][m];
    string subSec = "", aux = "";
    int i = n, j = m;

    while(tam > 0){
        if(s1[i-1] == s2[j-1]){
            subSec += s1[i-1];
            tam--;
            i--;
            j--;
        }else{
            if(matrizSec[i][j] == matrizSec[i][j-1]){
                j--;
            }else{
                i--;
            }
        }
    }

    for(int i = subSec.size(); i > 0; i--){
        palabra += subSec[i-1];
    }

    return palabra;
}

bool resuelveCaso() {
   
   // leer los datos de la entrada
   string s1, s2;
   std::cin >> s1 >> s2;
   if (!std::cin)  // fin de la entrada
      return false;
   
   // resolver el caso posiblemente llamando a otras funciones
   // escribir la solución
   std::cout << subSecuencia(s1, s2) << "\n";

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
