#include "pch.h"
#include "utils.h"

bool isSubstring(const std::string& a, const std::string& b) {
    // Devuelve true si b está en a o a está en b
    auto isSub = [](const std::string& text, const std::string& pattern) {
        if (pattern.empty()) return true;
        if (pattern.size() > text.size()) return false;

        for (size_t i = 0; i <= text.size() - pattern.size(); ++i) {
            size_t j = 0;
            while (j < pattern.size() && text[i + j] == pattern[j]) {
                ++j;
            }
            if (j == pattern.size()) {
                return true;
            }
        }
        return false;
        };

    return isSub(a, b) || isSub(b, a);
}

int simpleScore(char a, char b) {
    return (a == b) ? 1 : -1;
}

int customPairScore(const std::string& a, const std::string& b) {
    int score = 0;
    size_t minLen = std::min(a.size(), b.size());

    for (size_t i = 0; i < minLen; ++i) {
        score += (a[i] == b[i]) ? 1 : -2;
    }

    return score;
}