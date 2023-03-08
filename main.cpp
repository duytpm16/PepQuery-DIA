#include "cranium/src/cranium.h"

#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

    std::vector<Network*> net;
    for (int i = 0; i < 12; i++) {
        std::string file = "data/diann_net_" + std::to_string(i) + ".out";
        Network* nn = readNetwork(const_cast<char*>(file.c_str()));
        net.push_back(nn);
    }

    std::string file(argv[1]);
    std::ifstream scorefile(file, std::ifstream::in);

    std::string line;
    std::vector<float> vscores;
    float s;

    std::ofstream results("predicted_target_scores.out", std::ios_base::app);
    std::ostringstream oss;
    oss << "Average\n";
    while (std::getline(scorefile, line)) {
        std::istringstream iss(line);
        while(iss >> s) vscores.push_back(s);

        float* scores = &vscores[0];
        auto dataset = createDataSet(1, vscores.size(), &scores);

        double avg = 0.0;
        double n = 12.0;
        for (int i = 0; i < 12; i++) {
            forwardPassDataSet(net[i], dataset);
            auto result = getOuput(net[i]);
            avg += result->data[0];
        }
        avg /= n;
        oss  << avg << "\n";

        vscores.clear();
    }

    results << oss.str();
    oss.str(std::string());
    oss.clear();
    results.close();

    return 0;
}