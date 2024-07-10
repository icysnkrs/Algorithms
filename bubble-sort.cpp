/* ⭐ Bubble Sort ⭐
- este un algoritm de sortare foarte simplu dar cu o eficienta scazuta acesta avand complexitatea de n^2.
*/
 // Exemplu:

#include <iostream>
using namespace std;

int n, a[1001];
void sortare(int a[], int n) { //adaugam ca argumente vectorul si lungimea totala a acestuia
    bool este_sortat = false;
    while (!este_sortat) {
        este_sortat = true; // conditia de oprire a while-ului
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i + 1]) { // in caz ca numarul de pe pozitia "i" este mai mare decat cel de pe pozitia urmatoare
                este_sortat = false;
                swap(a[i], a[i+1]); // efectuam schimbul valorilor in vector
            }
        }
    }
}
