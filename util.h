#ifndef UTIL_H
#define UTIL_H
#include "graph.h"
#include <fstream> 

//vertex initializing, preference initializing, and such 
//csv output to google sheets

void initialize(Graph& g, std::string person_name); 


void to_csv(Matchlist matches, int week); 
void instructions(); 
#endif 