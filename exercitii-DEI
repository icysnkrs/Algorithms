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
