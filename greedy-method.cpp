                                                                    🌐 GREEDY METHOD 🌐
/*
- se poate folosi pentru probleme in care se da o multime A si trebuie determinata o multime S reunit cu A care indeplineste anumite conditii.
- o metoda simpla de a afla cea mai buna solutie a unei probleme.
- se axeaza pe gandirea logica a persoanei si nu necesita neaparat anumiti algoritmi.
- complexitatea algoritmului greedy propriu-zis este de O(n), dar depinde si de algoritmul de sortare folosit (Ex: QuickSort) care are nNogn ceea ce rezulta O(n) + O(n x logn) = nLogn.
*/

⭐ Exercitiul I 
/*
- Cerința
Se dau trei numere naturale n a b, 1 ≤ a < b < n. Să se determine o modalitate de a-l scrie pe n ca sumă de termeni egali cu a sau b în care numărul de termeni egali cu a este maxim.
- Date de intrare
Programul citește de la tastatură numerele n a b.
- Date de ieșire
Programul va afișa pe ecran un șir de numere ordonate crescător, reprezentând termenii ceruți.
- Restricții și precizări
1 ≤ n ≤ 1.000.000
1 ≤ a < b ≤ 1000
pentru toate datele de test n poate fi scris ca sumă de termeni egali cu a și b.
- Exemplu:
Intrare
40 3 5
Ieșire
3 3 3 3 3 3 3 3 3 3 5 5
*/

////////////////// REZOLVARE ////////////////////
#include <iostream>
using namespace std;

int n, a, b, cnta, cntb;

int main() {
    cin >> n >> a >> b;
    while (n % a && n > 0) {
        n -= b;
        cntb++;
    }
    while (n) {
        n -= a;
        cnta++;
    }
    for (int i = 0; i < cnta; i++) {
        cout << a << " ";
    }
    for (int i = 0; i < cntb; i++) {
        cout << b << " ";
    }
    return 0;
}
////////////////////////////////////////////////

⭐ Exercitiul II
/*
În curtea unui atelier de reparaţii auto, sunt n maşini care trebuie sa fie reparate. Deoarece nu sunt suficienţi mecanici, în fiecare moment de timp se poate lucra doar la o singură maşină.
- Cerinţa
Cunoscând timpul necesar pentru repararea fiecărei maşini, scrieţi un program care calculează numărul maxim de maşini care pot fi reparate într-un interval de timp T.
- Date de intrare
Pe prima linie a fişierului masini.in se găsesc două numere naturale n şi T separate printr-un singur spaţiu, reprezentând numărul de maşini din curtea atelierului auto şi timpul total în care se va lucra.
Pe linia a doua, separate prin câte un spaţiu, se găsesc n numere naturale t1, t2, …, tn, reprezentând timpii necesari pentru repararea fiecărei maşini.
- Date de ieşire
Pe prima linie a fişierului masini.out se va găsi un număr natural k, reprezentând numărul maxim de maşini care pot fi reparate.
- Restricţii şi precizări
1 < n, T <= 1000
numerele de pe a doua linie a fişierului de intrare vor fi mai mici sau egale cu 100
- Exemplu:
masini.in
5 10
6 2 4 8 2 
masini.out
3
Explicație
Se vor repara masinile 2, 3 şi 5, cu timpii de reparaţie 2, 4 şi 2.
*/

////////////////// REZOLVARE ////////////////////
#include <fstream>
using namespace std;

ifstream cin("masini.in");
ofstream cout("masini.out") ;

int n, T, a[1001];

void sortare(int a[], int n) { // Folosirea algoritmului de sortare BubbleSort
    bool este_sortat = false;
    while (!este_sortat) {
        este_sortat = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i + 1]) {
                este_sortat = false;
                swap(a[i], a[i+1]);
            }
        }
    }
}
int main() {
    cin >> n >> T;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sortare(a, n);
    int i = 1;
    while (T - a[i] >= 0 && i <= n) {
        T -= a[i];
        i++;
    }
    cout << i - 1;
    return 0;
}
//////////////////////////////////////////////
