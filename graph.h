#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <cmath> 

struct Vertex {
    std::vector<Vertex> preference_list; 
    std::vector<Vertex> original_preference_list; 
    std::string person_name; 
    Vertex(std::string person) {
        person_name = person; 
        preference_list = {}; 
        original_preference_list = {}; 
    }                   
    Vertex() {
        person_name = ""; 
        preference_list = {}; 
        original_preference_list = {}; 
    }
    bool operator==(const Vertex& other) const {
        return this->person_name == other.person_name && this->original_preference_list == other.original_preference_list; 
    }
    bool operator!=(const Vertex& other) const {
        return !(*this == other); 
    }
    bool operator<(const Vertex& other) const {
        return (person_name < other.person_name); 
    }
}; 
struct Graph {
    std::vector<Vertex> graph; 
};

struct Pair {
    Vertex first; 
    Vertex second; 
    bool operator<(const Pair& other) const {
        return this->first < other.first; 
    }
    Pair(Vertex one, Vertex two) {
        first = one; 
        second = two; 
    }
}; 

struct Edge {
    Vertex incidentOne; 
    Vertex incidentTwo; 
};

struct Matchlist {
    std::vector<std::pair<Vertex, Vertex>> matches; 
    Matchlist(std::vector<std::pair<Vertex, Vertex>> input) {
        matches = input; 
    }
};

Matchlist gale_shapley(std::vector<Vertex> vertexlist, Edge edgelist);


Vertex higherPreference(Vertex challenged, Vertex one, Vertex two); 

int positionVector(std::vector<Vertex> list, Vertex find);


#endif