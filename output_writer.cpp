#include "pch.h"
#include "output_writer.h"
#include <fstream>

void writeResultToFile(const std::string& filename, const AlignmentResult& result) {
    std::ofstream out(filename);
    out << "Score final: " << result.finalScore << "\n";
    out << "Matriz de scores:\n";
    for (const auto& row : result.scoreMatrix) {
        for (int val : row) {
            out << val << " ";
        }
        out << "\n";
    }
    out << "Cantidad de alineamientos: " << result.alignments.size() << "\n";
    out << "Alineamientos generados:\n";
    for (const auto& [a1, a2] : result.alignments) {
        out << a1 << "\n" << a2 << "\n\n";
    }
}
