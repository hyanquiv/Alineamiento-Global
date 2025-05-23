#pragma once
#include <string>
#include <vector>
#include <tuple>

struct AlignmentResult {
    int finalScore;
    int gapPenalty; 
    std::vector<std::pair<std::string, std::string>> alignments;
    std::vector<std::vector<int>> scoreMatrix;
};


AlignmentResult globalAlignment(const std::string& seq1, const std::string& seq2, int gap);

