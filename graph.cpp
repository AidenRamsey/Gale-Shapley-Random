#include "graph.h"
//edges are optional, I'll code them without the thing now. 
//stable matching! 


Matchlist gale_shapley(std::vector<Vertex> vertexlist, Edge edgelist) {
    // input the vertices, shuffle their preference lists. 
    //shuffle vertexlist, split in half. 
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vertexlist.begin(), vertexlist.end(), g); //shuffled list 
    
    unsigned int length = floor(vertexlist.size() / 2); 
    std::vector<Vertex> first_group; 
    std::vector<Vertex> second_group; 
    


    //need to make sure that the preference lists match, so in theory should make group 1's 2's preference lists and THEN shuffle
    //instead of shuffling each one like that...


    //now everything is shuffled both ways. So now we need to actually partition the group and have 
    //the first group choose their partners in the second group. 
    //responses: no, maybe. If there are no nos, terminate. 


    for (unsigned int i = 0; i < length; ++i) {//add to the thing here ) 
        first_group.push_back(vertexlist[i]);
        
    }
    
    for (unsigned int j = length; j < vertexlist.size(); ++j) {
        second_group.push_back(vertexlist[j]);
    }
    
 
    for (unsigned int i = 0; i < length; ++i) {//add to the thing here ) 
        
        second_group[i].preference_list = first_group; 
    }
    for (unsigned int i = 0; i < length; ++i) {
        first_group[i].preference_list = second_group; 
    }

    //shuffle preference lists 
    for (unsigned int k = 0; k < length; ++k) {
        std::shuffle(first_group[k].preference_list.begin(), first_group[k].preference_list.end(), g); 
    }
    for (unsigned int k = 0; k < length; ++k) {
        std::shuffle(second_group[k].preference_list.begin(), second_group[k].preference_list.end(), g); 
    }
    
    std::vector<std::pair<Vertex, Vertex>> matchlist; 
    std::vector<std::pair<Vertex, Vertex>> currentTargets; 
    unsigned int response = 0; // increment if ANY choosee is rejected. 
    while (true) {  
        //pick next group of the stuff
        for (Vertex two : second_group) {
            //currentTargets = second group -> first group
            currentTargets.push_back({two, two.preference_list[0]}); 
        }
        
        //check each "want" to find if there are duplicate "wants"
        std::vector<std::pair<Vertex, std::vector<Vertex>>> challenged; 
        for (int i = 0; i < currentTargets.size(); ++i) {
            
            std::vector<Vertex> challengers;
            Vertex target = currentTargets[i].second;

            for (int j = 0; j < currentTargets.size(); ++j) {
                if (currentTargets[j].second == target) {
                challengers.push_back(currentTargets[j].first);
        }
    }

    if (challengers.size() > 1) {
        bool already_added = false;
        for (auto& c : challenged) {
            if (c.first == target) { 
                already_added = true; 
                break; 
            }
        }
        if (!already_added) {
            challenged.push_back({target, challengers});
        }
    }   

        }
        //Vertices along with the challengeing vertices
       

    
        Vertex winner_candidate; 
        std::vector<Vertex> to_reject; 
        //find the vertex with highest priority of the specific group 
        for (unsigned int k = 0; k < challenged.size(); ++k) {//loop over all challenged vertices
            std::vector<Vertex> challengers = challenged[k].second; 
            Vertex winner_candidate = challengers[0]; 
        for (int i = 1; i < challengers.size(); ++i) {    //find a specific challenged vertex
            //need to find highest priority vertex, reject all of the rest 
            
                //pairwise comparison, 
                //Vertex candidate = higherPreference(challenged[k].first, challengers[i], challengers[j]); 
                winner_candidate = higherPreference(challenged[k].first, winner_candidate, challengers[i]); 
            
        
        }
        //finding vectors to reject based on which ones were NOT to reject
        for (Vertex& v : challengers) {
            
                if (v != winner_candidate)  {
                    to_reject.push_back(v); 
                }
            
        }
    }
        //reject everything that wasn't candidate winner, now we have a list of vectors to decrement their preference lists
    for (unsigned int i = 0; i < to_reject.size(); ++i) {
        int position = positionVector(second_group, to_reject[i]); 
       
        second_group[position].preference_list.erase(second_group[position].preference_list.begin()); 
        //this should successfully remove the rejected vector :) 
        response++; 
    }
   
        //zero sum everything, if there are no nos, then the value should be zero. 
        if (response == 0) {
            //construct match list
         

            return Matchlist(currentTargets);
        } else {
            //construct match list, which is current Target list
          
            response = 0; 
            currentTargets.clear(); 
            continue; 
        }
    }
}


Vertex higherPreference(Vertex challenged, Vertex one, Vertex two) {
    int position_one = 0; 
    int position_two = 0; 
    for (unsigned int i = 0; i < challenged.preference_list.size(); ++i) {
        if (challenged.preference_list[i] == one) {
            position_one = i; 
        } else if (challenged.preference_list[i]==two) {
            position_two = i; 
        }
    }
    Vertex ret = (position_one < position_two) ? one : two;
    return ret; 
}

int positionVector(std::vector<Vertex> list, Vertex find) {
    for (unsigned int i = 0; i < list.size(); ++i) {
        if (list[i]==find) {
            return i; 
        }
    }
    return -1; 
}