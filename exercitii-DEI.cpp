                                            /// DIVIDE ET IMPERA //


                                    // Suma Elemente Pare Vector Recursiv //
/*
 - nr de elemente cat si elementele vectorului se citesc de la tastatura
 */

#include <iostream>
using namespace std;
int n, v[100];
void divizeaza (int s, int d, int &m) {
    m = (s + d) / 2;
}
void combina (int x, int y, int &z) {
    z = x + y;

}
void dei(int s, int d, int &z) {
    int m, x1, x2;
    if (s == d) {
        if(v[s] % 2 == 0) {
            z = v[s];
        } else {
            z = 0;
        }
    } else {
        divizeaza(s, d, m);
        dei(s, m, x1);
        dei(m + 1, d, x2);
        combina(x1, x2, z);
    }
}
int main() {
    int z;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dei (1,n,z);
    cout << z;
    return 0;
}

                                    // Sa se calculeze suma 1x2+2x3+3x4+...+nx(n+1) //
#include <iostream>
using namespace std;

int n, v[100];
void divizeaza (int s, int d, int &m) {
    m = (s + d) / 2;
}
void combinare (int x, int y, int &z) {
    z = x + y;
}
void dei(int s, int d, int &z) {
    int x1, x2, m;
    if(s == d) {
        z = s*(s+1);
    } else {
        divizeaza(s, d, m);
        dei(s, m, x1);
        dei(m + 1, d, x2);
        combinare(x1, x2, z);
    }
}
int main() {
    int z;
    cin >> n;
    dei(1,n,z);
    cout << z;
    return 0;
}

                                    // Sa se determine valoarea minima si valoarea maxima dintr-un vector "v" //
/*
 - nr de elemente ale vectorului se citesc de la tastatura
 */

#include <iostream>
using namespace std;

int n, v[100];
void divizeaza(int s, int d, int &m) {
    m = (s+d)/2;
}
void combinare(int x1, int y1, int &z1, int x2, int y2, int &z2) {  // z1 - valoarea minima si z2 - valoarea maxima
    if (x1 > y1) {
        z1 = y1;
    } else {
        z1 = x1;
    }
    if (x2 > y2) {
        z2 = x2;
    } else {
        z2 = y2;
    }
}
void dei(int s, int d, int &z1, int &z2) { // x1,y1 - minim si x2,y2 - maxim
    int m, x1, x2, y1, y2;
    if (d == s) { // un singur element
        z1 = z2 = v[s];
    } else {
        divizeaza(s, d, m);
        dei(s, m, x1 ,x2);  // x1,x2 apartin de partea stanga
        dei(m + 1, d, y1, y2); // y1,y2 apartin de partea dreapta
        combinare(x1, y1, z1, x2, y2, z2);
    }
}
int main() {
    int z1, z2;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    dei(1, n, z1, z2);
    cout << z1 << " " << z2;
    return 0;
}
                                                             
                        I  // CAUTAREA BINARA // 

#include <iostream>
using namespace std;

int n, x, v[100];

void divizare(int s, int d, int &m) {
    m = (s + d) / 2;
}

void cautare(int s, int d, int &z) {
    int m;
    if (d >= s) { // conditie daca exista doar un singur element sau daca sunt mai multe sa efectueze divizarea
        divizare(s, d, m);
        if (v[m] == x) // conditie daca elementul se afla pe potizia m
            z = m;
        else if (x > v[m])
            cautare(m+1, d, z); // cautam in partea dreapta a elementului pentru ca x > valoarea de pe pozitia v[m]
        else
            cautare(s, m, z); // cautam in partea stanga a elementului pentru ca x < valoarea de pe pozitia v[m]
    }
}

int main() {
    int z = 0;
    cin >> n; // lungimea sirului
    for (int i = 1; i <= n; ++i) { // citirea array-ului
        cin >> v[i];
    }
    cin >> x;
    cautare(1, n, z);
    if (z == 0) {
        cout << "Elementul nu a fost gasit... z = " << z;
    } else {
        cout << "Elementul a fost gasit pe pozitia z = " << z;
    }
    return 0;
}

// Aplicare algoritm cautare binara (METODA BISECTIEI)
/*
 - sa se determine cu o precizie de 4 zecimale, radacina reala, din interbalul [0,1] a ecuatiei x^3+x-1 = 0.
 - METODA BISECTIEI = consta in reducerea intervalului de cautare prin injumatatirea repetata si selectarea
 subintervalului in care se gaseste radacina.
 */

#include <iostream>
#include <iomanip>
using namespace std;

const float  r = 0.0001;
float f(float x) { return x*x*x+x-1; } // returnam ecuatia pe care lucram, x^3+x-1.
void divizare(float s, float d, float &m) { m = (s+d)/2; } // impartim sirul in doua.
void radacina(float s, float d, float &z) {
 float m;
 if (d-s < r) { // r = 0.0001 unde r este eroarea acceptata pentru o precizie cu 4 zecimale
  z = (s+d)/2;
 } else {
  divizare(s, d, m);
  if (f(s) * f(m) < 0) {
   radacina(s, m, z);
  } else {
   radacina(m, d, z);
  }
 }
}
int main() {
 float z = 0;
 radacina (0, 1, z);
 cout << "radacina " << z; // radacina = 0.682343
 return 0;
}
                  
                            II  // Quick Sort // 

#include <iostream>
using namespace std;

int v[100], n;
void schimb(int &a, int &b) {int aux = a; a = b; b = aux;}  // functie de interschimbare a variabilelor.
void divizare(int s, int d, int &m) {
    int i = s, j = d, pi = 0, pj = 1;
    //pivotul fiind pe pozitia "s", parcurgerea incepe cu indicele j.
    while(i < j) { // (s < d)
        if (v[i] > v[j]) {
            schimb (v[i], v[j]); // se interschimba valorile de pe pozitii
            schimb (pi, pj); // se interschimba valorile pi si pj (= 0 si = 1)
                            // 0 - ramane pe pozitie // 1 - se va parcurge vectorul de la elementul pi/pj ce are val 1
        }
        i += pi;
        j -= pj;
    }
    m = i;
}
void quickSort(int s, int d) {
    int m;
    if(s < d) {
        divizare(s,d,m);
        quickSort(s, m-1);
        quickSort(m + 1, d);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    quickSort(1, n);
    for (int i = 1; i <= n; ++i) {
        cout << v[i] << " ";
    }
}
