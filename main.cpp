#include "graph.h"
#include "util.h"
#include <iostream> 


int main() {
    instructions(); 
    Graph g; 
    Edge e; 
    while (true) {
        std::string input; 
        std::cin >> input; 
        if (input == "STOP") {
            break; 
        } else {
            initialize(g, input); //too many arguments? what ??? 
        }
    }
    
    int week = 0; 
    //std::cout << "To randomize again, type RANDOM (no spaces/punctuation). Otherwise, type END (no spaces or punctuation) " << std::endl; 
    while (true) {
        //std::cout << "resetting temp to equal the graph" << std::endl; 
        std::vector<Vertex> temp = g.graph;
        if (g.graph.size() % 2 != 0) {
            //std::cout << "graph has odd length" << std::endl; 
            int size = g.graph.size(); 
            std::mt19937 e(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, size-1); 
            int discard = dist(e); 
            Vertex person = g.graph[discard]; 
            std::string person_name = person.person_name; 
            std::cout << "Need to discard someone on this iteration. In this iteration, it is: " << person_name << std::endl; 
            //actually discard that person this iteration! 
            
            temp.erase(temp.begin() + discard);
            std::cout << "Actually deleting the person is done" << std::endl; 
        }
        //std::cout << "running gale_shapley" << std::endl; 
        Matchlist matches = gale_shapley(temp, e); 
        std::cout << "gale_shapley terminated" << std::endl; 
    std::string input; 
    std::cin >> input; 
    if (input == "END") {
        std::cout << "THANKS FOR USING, LEAVE A 5 STAR REVIEW PLEASE" << std::endl; 
        std::cout << "----------------------------------------------" << std::endl; 
        to_csv(matches, week); 
        return 0; 
    } else if (input == "RANDOM") {
        //another week/ iteration 
        std::cout << "outputing to " + std::to_string(week) + "!" << std::endl; 
        to_csv(matches, week); 
        std::cout << "successfully output, checking matches again" << std::endl; 
        matches = gale_shapley(temp, e); 
        std::cout << "new set of matches done" << std::endl; //something here I would assume? I don't reset the thing. 
        week++; 
        std::cout << "incrementing week, done with this iteration" << std::endl; 
    }
}
}