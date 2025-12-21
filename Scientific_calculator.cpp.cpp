#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// global variables (simple names)
bool mode = true;     // true = degree, false = radian



// ---------------- BASIC OPS ----------------

double add(double n1, double n2) {
    return n1 + n2;
}

double sub(double n1, double n2) {
    return n1 - n2;
}

double mul(double n1, double n2) {
    return n1 * n2;
}

double divi(double n1, double n2) {
    if (n2 == 0) {
        cout << "Division by zero not allowed\n";
        return 0;
    }
    return n1 / n2;
}

// ---------------- SCIENTIFIC ----------------

double degToRad(double v) {
    return v * 3.14159 / 180;
}

double sinFun(double x) {
    if (mode)
        x = degToRad(x);
    return sin(x);
}

double cosFun(double x) {
    if (mode)
        x = degToRad(x);
    return cos(x);
}

double tanFun(double x) {
    if (mode)
        x = degToRad(x);
    return tan(x);
}

double logFun(double x) {
    if (x <= 0) {
        cout << "Wrong value for log\n";
        return 0;
    }
    return log10(x);
}

double lnFun(double x) {
    if (x <= 0) {
        cout << "Wrong value for ln\n";
        return 0;
    }
    return log(x);
}

double sqFun(double x) {
    if (x < 0) {
        cout << "Negative value not allowed\n";
        return 0;
    }
    return sqrt(x);
}

double powFun(double a, double b) {
    return pow(a, b);
}

// recursion example
int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}


// ---------------- FILE ----------------

void saveFile(string exp, double ans) {
    ofstream file("history.txt", ios::app);
    file << exp << " = " << ans << "\n";
    file.close();
}

void loadFile() {
    ifstream file("history.txt");
    if (!file) {
        cout << "No saved history found.\n";
        return;
    }
    cout << "\n--- Saved History (File) ---\n";
    string line;
    while (getline(file, line)) cout << line << endl;
}


// ---------------- MATRIX ----------------

void Matrix(int M[2][2]) {
    cout << "Enter 4 numbers for 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> M[i][j];
}

void showMat(int m[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

void addM(int a[2][2], int b[2][2], int r[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r[i][j] = a[i][j] + b[i][j];
}

void subM(int a[2][2], int b[2][2], int r[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r[i][j] = a[i][j] - b[i][j];
}

void mulM(int a[2][2], int b[2][2], int r[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            r[i][j] = a[i][j] * b[j][i];
}

// ---------------- MENUS ----------------

void basicMenu() {
    double x, y;
    int ch;

    double (*op[4])(double, double) = { add, sub, mul, divi };

    cout << " 1 Add  \n2 Sub  \n3 Mul  \n4 Div\n";
    cin >> ch;

    if (ch < 1 || ch > 4) {
        cout << "Wrong choice\n";
        return;
    }

    cin >> x >> y;
    double ans = op[ch - 1](x, y);

    cout << "Ans = " << ans << endl;

    saveFile("basic", ans);
    
}

void sciMenu() {
    int ch;
    double x, y;

    cout << " 1 Sin \n2 Cos \n3 Tan \n4 Log \n5 Ln \n6 Sqrt \n7 Power \n8 Fact\n";
    cin >> ch;

    if (ch >= 1 && ch <= 5) {
        cin >> x;
        double (*f[5])(double) = { sinFun, cosFun, tanFun, logFun, lnFun };
        cout << f[ch - 1](x) << endl;
    }
    else if (ch == 6) {
        cin >> x;
        cout << sqFun(x) << endl;
    }
    else if (ch == 7) {
        cin >> x >> y;
        cout << powFun(x, y) << endl;
    }
    else if (ch == 8) {
        int n;
        cin >> n;
        cout << fact(n) << endl;
    }

}

void matMenu() {
    int a[2][2], b[2][2], r[2][2];
    int ch;

    cout << " 1 Add \n2 Sub \n3 Mul\n";
    cin >> ch;

    Matrix(a);
    Matrix(b);

    if (ch == 1) addM(a, b, r);
    else if (ch == 2) subM(a, b, r);
    else if (ch == 3) mulM(a, b, r);

    showMat(r);
}

// ---------------- MAIN ----------------

int main() {
    while (true) {
        int c;
        cout << " \n1 Basic \n2 Sci \n3 Matrix \n4 FileHist \n5 Mode \n6 Exit\n";
        cin >> c;

        if (c == 1) basicMenu();
        else if (c == 2) sciMenu();
        else if (c == 3) matMenu();
        else if (c == 4) loadFile();
        else if (c == 5) {
            mode = !mode;
            cout << (mode ? "Degree\n" : "Radian\n");
        }
        
        else if (c == 6) {
            break;
        }
        else {
            cout << "Invalid\n";
        }
    }
    return 0;
}