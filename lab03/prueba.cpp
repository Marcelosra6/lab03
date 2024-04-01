#include <iostream>

using namespace std;

int main()
{
    float celsuis,fahrenheit;
    cout<<"Temperatura en C°: ";
    cin>>celsuis;
    
    fahrenheit=(((9*celsuis))/5)+32;
    cout<<"La temperatura en Fahrenheit: "<<endl<<fahrenheit;
    return 0;
}
