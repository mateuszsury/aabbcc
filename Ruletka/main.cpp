#include <locale.h>
#include <iostream>
#include "MainMenu.h" 

int main()
{
    // Żeby były polskie znaki diak.
    // 1. ustawić locale:
    setlocale(LC_ALL, "pl_PL");
    // 2. Każdy plik w którym się pojawiają takie znaki zapisać z kodowaniem "UTF-8 without signature"
    //       (File->Save As->Save With Encoding)
    // 3. W ustawieniach konfiguracji (ang. "Ruletka Properties") Configuration Properties > C/C++ > Command Line
    //    dodać opcję lini poleceń "/utf-8".

    MainMenu menu;
    menu.show(); 

}