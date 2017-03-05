#include <iostream>
#include "Sommet.h"


int main() {
    Graphe graphe;
    graphe.read_file();
    graphe.display();

    return 0;
}