#include <iostream>
#include <string>
using namespace std;

string texto = "";
int pos = 0;
int error = 0;

bool E();
bool E_();
bool T();
bool T_();
bool F();

bool E() {
    return T() && E_();
}

bool E_() {
    if (texto[pos] == '+') {
        ++pos;
        return T() && E_();
    }
    return true;
}

bool T() {
    return F() && T_();
}

bool T_() {
    if (texto[pos] == '*') {
        ++pos;
        return F() && T_();
    }
    return true;
}

bool F() {
    if (texto[pos] == '(') {
        ++pos;
        bool res = E() && texto[pos++] == ')';
        return res;
    }
    return texto[pos++] == 'd';
}

int main() {
    texto = "(d+d)*d";
    string combinaciones[] = {
            "d", "d+d", "d+d+d", "d*d", "(d)", "(d+d)*d",
            "d+", "d*", "+d", "d", "d+d"
    };
    int n = sizeof(combinaciones)/sizeof(combinaciones[0]);
    for (int i = 0; i < n; i++) {
        texto = combinaciones[i];
        pos = 0;
        error = 0;
        if (E() && pos == texto.length() && error == 0) {
            cout << "[ " << combinaciones[i] << " ] - valida" << endl;
        } else {
            cout << "[ " << combinaciones[i] << " ] - invalida" << endl;
        }
    }
    return 0;
}