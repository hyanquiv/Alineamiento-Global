#include "pch.h"
#include "fasta_reader.h"
#include <fstream>
#include <sstream>

std::vector<std::pair<std::string, std::string>> readFastaFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::pair<std::string, std::string>> sequences;
    std::string line, id, seq;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == '>') {
            if (!id.empty()) {
                sequences.emplace_back(id, seq);
                seq.clear();
            }
            id = line.substr(1); // remove '>'
        }
        else {
            seq += line;
        }
    }
    if (!id.empty()) {
        sequences.emplace_back(id, seq);
    }
    return sequences;
}
