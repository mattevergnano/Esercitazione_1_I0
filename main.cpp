#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double remap(double value){
    double a = 3.0/4.0;
    double b = -7.0/4.0;
    double num = a*value+b;
    return num;
}

int main()
{
    ifstream file("./data.txt");
    if(file.fail()){
        cout << "Errore nell'apertura del file!" << endl;
        return 1;
    }
    double val = 0.0;
    double mean = 0.0;
    int i = 1;
    double sum = 0.0;
    double temp = 0.0;
    ofstream myFile("./results.txt");
    myFile << setprecision(16) << scientific;
    while(file >> temp){
        val = remap(temp);
        sum = sum + val;
        mean = sum / i++;
        myFile << mean << endl;
    }
    myFile.close();
    return 0;
}
