#include "pch.h"

#include <gtest/gtest.h>
#include "aligner.h"
#include "utils.h"

TEST(SubstringTest, Positive) {
    EXPECT_TRUE(isSubstring("abcdef", "cde"));
    EXPECT_TRUE(isSubstring("xyz", "xyz"));
}

TEST(SubstringTest, Negative) {
    EXPECT_FALSE(isSubstring("abc", "def"));
}

TEST(CustomPairScoreTest, EqualStrings) {
    EXPECT_EQ(customPairScore("AAAA", "AAAA"), 4);  // 4 * +1
}

TEST(CustomPairScoreTest, CompletelyDifferent) {
    EXPECT_EQ(customPairScore("AAAA", "TTTT"), -8); // 4 * -2
}

TEST(CustomPairScoreTest, MixedMatch) {
    EXPECT_EQ(customPairScore("ACGT", "AGGT"), 1); // A==A(+1), C!=G(-2), G==G(+1), T==T(+1) → 1
}

TEST(GlobalAlignmentTest, MultipleOptimalAlignments) {
    std::string s1 = "TACGCGC";
    std::string s2 = "TCCGA";

    AlignmentResult result = globalAlignment(s1, s2, -2);

    // Validar número de alineamientos 
    EXPECT_EQ(result.alignments.size(), 3);

    // Validar que estén los alineamientos proporcionados
    std::set<std::pair<std::string, std::string>> expectedAlignments = {
        {"TACGCGC", "TCCGA--"},
        {"TACGCGC", "TCCG-A-"},
        {"TACGCGC", "TCCG--A"}
    };

    std::set<std::pair<std::string, std::string>> actualAlignments;
    for (const auto& align : result.alignments) {
        actualAlignments.insert({ align.first, align.second });
    }

    EXPECT_EQ(actualAlignments, expectedAlignments);
}