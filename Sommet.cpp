//
// Created by johann on 02/03/17.
//

#include "Sommet.h"

void Graphe::create_graphe(int order) {
    Graphe::order = order;
    Graphe::adjacency_matrix.resize(order, std::vector<bool>(order, false));
}

void Graphe::read_file() {
    std::string line;
    std::vector<std::string> input;
    std::ifstream myfile("source.txt");
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            input.push_back(line);
        }
        myfile.close();
    } else std::cout << "Unable to open file";
    update_data(input);
}


void Graphe::display() {
    for (auto &elem: sommet_vector) { std::cout << elem->name << std::endl; }
    for (int i = 0; i < order; ++i) {
        std::cout << std::endl;
        for (int j = 0; j < order; ++j) {
            std::cout << adjacency_matrix[i][j];
        }
    }
}

void Graphe::update_data(std::vector<std::string> &line_read) {
    std::string name = " ";
    bool is_reached{false};

    int order = 0;

    for (auto &line : line_read) {
        is_reached = true;
        for (auto &c : line) {
            if (c == ' ') {
                is_reached = false;
                sommet_vector.push_back(std::make_unique<Sommet>(name));
                ++order;
                name = " ";
            } else if (is_reached) {
                name += c;
            }

        }
    }
    create_graphe(order);

    create_links(line_read);
}

void Graphe::create_links(std::vector<std::string> &line_read) {

    int index_1{1224};
    int index_2{1224};

    for (auto &line : line_read) {
        index_1 = 1224;
        index_2 = 1224;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '-') { index_1 = match_sommet(line[i + 1]); }
            else if (line[i] == '|') {
                index_2 = match_sommet(line[i + 1]);
                if ((index_1 <= order - 1) && (index_2 <= order - 1)) { adjacency_matrix[index_1][index_2] = true; }
            } else if (line[i] == ',') {
                index_2 = match_sommet(line[i + 1]);
                if ((index_1 <= order - 1) && (index_2 <= order - 1)) { adjacency_matrix[index_1][index_2] = true; }
            }

        }
    }
}

int Graphe::match_sommet(char &to_match) {

    for (int i = 0; i < sommet_vector.size(); ++i) {
        if (to_match == sommet_vector[i]->name[sommet_vector[i]->name.size() - 1]) { return i; }
    }
    return 1224;
}
