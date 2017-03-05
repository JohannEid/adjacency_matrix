//
// Created by johann on 02/03/17.
//

#ifndef TP_01_SOMMET_H
#define TP_01_SOMMET_H

#include "bits/stdtr1c++.h"
#include <memory>


struct Sommet {
    std::string name;

    Sommet(std::string name = " ") : name{name} {}


};

struct Graphe {


//on devras faire correspondre chaque indice à de notre matrice au même indice présent dans le
//le vector de Sommet
    std::vector<std::unique_ptr<Sommet>> sommet_vector;

    std::vector<std::vector<bool>> adjacency_matrix;

    int order;

    Graphe():order{0} {}

    void create_graphe(int order);

    void read_file ();

    void update_data(std::vector<std::string>&line_read);

    void display();

    void create_links(std::vector<std::string>& line_read);

    int match_sommet (char& to_match);



};


#endif //TP_01_SOMMET_H
