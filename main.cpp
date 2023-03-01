#include "cranium/src/cranium.h"

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

int main() {

    std::vector<Network*> net;
    for (int i = 0; i < 12; i++) {
        std::string file = "data/diann_net_" + std::to_string(i) + ".out";
        Network* nn = readNetwork(const_cast<char*>(file.c_str()));
        net.push_back(nn);
    }

    std::ifstream scorefile("scores1.out", std::ifstream::in);
    
    return 0;
}