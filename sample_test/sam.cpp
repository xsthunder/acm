#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    double** p = new double*[2];
    for (int i = 0; i < 2; i++)
        p[i] = new double[n];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];
    double a = 0;
    for (int i = 1; i < 4; i++){
        for (int j = 0; j < n; j++)
            a += pow(fabs(p[0][j] - p[1][j]), i);
        cout << fixed << setprecision(8) << pow(a, 1.0 / i) << "\n";
        a = 0;
    }
    double d = 0;
    for (int i = 0; i < n; i++){
        double tmp = fabs(1.0 * p[0][i] - p[1][i]);
        d = d < tmp ? tmp : d;
    }
    cout << d << "\n";
}
