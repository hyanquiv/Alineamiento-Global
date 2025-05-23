#include "pch.h"
#include "fasta_reader.h"
#include "aligner.h"
#include "utils.h"
#include "output_writer.h"
#include <iostream>

//Comentar main para ejecutar pruebas unitarias
/*
int main() {
    auto seqs = readFastaFile("sequences.fasta");
    if (seqs.size() < 2) {
        std::cerr << "Se necesitan al menos dos secuencias en formato FASTA\n";
        return 1;
    }

    auto& [id1, s1] = seqs[0];
    auto& [id2, s2] = seqs[1];

    auto result = globalAlignment(s1, s2, -5);
    writeResultToFile("resultado.txt", result);

    std::cout << "Alineamiento guardado en resultado.txt\n";
    return 0;
}
*/