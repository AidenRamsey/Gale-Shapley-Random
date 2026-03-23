#include "util.h"


void initialize(Graph& g, std::string person_name) {
    g.graph.push_back(Vertex(person_name)); 
}
void instructions() {
    std::cout << "HELLO AND WELCOME TO MY VARIATION OF GALE-SHAPELY STABLE MATCHING" << std::endl; 

    std::cout << "THIS ALGORITHM WILL GENERATE A STABLE MATCHING OF THE GIVEN VERTICES" << std::endl; 

    std::cout << "TECHNICALLY, THIS ONLY MATCHES FOR AN EVEN NUMBER OF PEOPLE BY TUTTE'S THEOREM FOR PERFECT MATCHINGS" << std::endl; 

    std::cout << "I'LL DECIDE HOW TO DEAL WITH AN ODD NUMBER OF PEOPLE LATER POSSIBLY IDK " << std::endl; 

    std::cout << "ANY QUESTIONS ON HOW TO USE CAN BE DIRECTED TO A. RAMSEY" << std::endl; 

    std::cout << "ESSENTIALLY, INPUT MEMBER NAMES HOWEVER YOU'D LIKE (MAKE SURE YOU KEEP A PATTERN THOUGH)" << std::endl; 

    std::cout << "FOR EXAMPLE INPUT, Aiden OR AIDEN OR Aiden R OR Aiden Ramsey" << std::endl; 

    std::cout << "AGAIN, KEEP NAMING CONVENTIONS CONSISTENT FOR EASE OF USE" << std::endl; 

    std::cout << "THERE WILL BE MORE INSTRUCTIONS LATER, BUT INPUT NAMES ONE AT A TIME AND THEN IT WILL RANDOMIZE MATCHINGS" << std::endl; 

    std::cout << "IF YOU WANT ANOTHER MATCHING, THEN FOLLOW INSTRUCTIONS. ELSE, TYPE END" << std::endl; 

    std::cout << "HAVE FUN :D - A. RAMSEY" << std::endl; 

}

void to_csv(Matchlist matches, int week) {
    std::string iteration = "matches" + std::to_string(week) + ".csv"; 
    std::ofstream file(iteration);
    //sort matches here, by first vertex in the matching, preferably
    //that way it is predictable outcome for the stuff
    //turn into Pairs, probably just to be consistent 
    std::vector<Pair> to_output; 
    //make two, both directions, then have each included in
    for (int i = 0; i < matches.matches.size(); ++i) {
        std::pair<Vertex, Vertex> t = matches.matches[i]; 
        Pair pair = Pair(t.first, t.second);
        Pair pair2 = Pair(t.second, t.first); 
        to_output.push_back(pair); 
        to_output.push_back(pair2); 
    }
    std::sort(to_output.begin(), to_output.end()); 
    file << "Brother,Match\n";
    for (const auto& pair : to_output) {
        file << pair.first.person_name << "," << pair.second.person_name << "\n";
    }
    std::cout << "exported to matches_i_.csv" << std::endl; 
}