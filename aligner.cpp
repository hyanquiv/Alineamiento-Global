#include "pch.h"
#include "aligner.h"
#include "utils.h"
#include <algorithm>

AlignmentResult globalAlignment(const std::string& seq1, const std::string& seq2, int gap) {
    size_t m = seq1.size();
    size_t n = seq2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (size_t i = 0; i <= m; ++i) dp[i][0] = i * gap;
    for (size_t j = 0; j <= n; ++j) dp[0][j] = j * gap;

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            int match = dp[i - 1][j - 1] + simpleScore(seq1[i - 1], seq2[j - 1]);
            int del = dp[i - 1][j] + gap;
            int ins = dp[i][j - 1] + gap;
            dp[i][j] = std::max({ match, del, ins });
        }
    }

    // Backtrack
    size_t i = m, j = n;
    std::string aligned1, aligned2;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + simpleScore(seq1[i - 1], seq2[j - 1])) {
            aligned1 = seq1[i - 1] + aligned1;
            aligned2 = seq2[j - 1] + aligned2;
            --i; --j;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + gap) {
            aligned1 = seq1[i - 1] + aligned1;
            aligned2 = '-' + aligned2;
            --i;
        }
        else {
            aligned1 = '-' + aligned1;
            aligned2 = seq2[j - 1] + aligned2;
            --j;
        }
    }

    // Retorno explícito para evitar errores de orden
    AlignmentResult result;
    result.finalScore = dp[m][n];
    result.gapPenalty = gap;
    result.alignments.push_back({ aligned1, aligned2 });
    result.scoreMatrix = dp;

    return result;
}

