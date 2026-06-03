#include <iostream>
#include "DocumentParser.hpp"
#include "TextAnalyzer.hpp"
#include "ExportEngine.hpp"

int main() {
    std::string academic_text = 
        "Artificial intelligence is a core pillar of modern computer science. "
        "Modern artificial intelligence systems process vast amounts of data to extract information. "
        "Computer memory stores this data, but artificial intelligence learns patterns from the data itself. "
        "Many developers use algorithms to optimize software performance.";

    std::cout << "\n=========================================\n";
    std::cout << "=== RUNNING UPDATED C++23 NLP PIPELINE ===\n";
    std::cout << "=========================================\n\n";

    // Parse & Tokenize
    DocumentParser parser(academic_text);
    parser.clean_text();
    auto tokens = parser.tokenize();
    auto sentences = parser.split_sentences();

    // Analyze
    TextAnalyzer analyzer(tokens);
    analyzer.calculate_frequencies();
    
    double density = analyzer.calculate_information_density();
    std::cout << "[ANALYSIS] Text Information Density: " << density << "%\n";
    if (density > 60.0) {
        std::cout << "[NOTICE] This text has high cognitive load (dense syntax).\n";
    }

    // AI Smart Summary Extraction
    std::string summary = analyzer.get_summary_sentence(sentences);
    std::cout << "\n=== AI SMART SUMMARY (Key Sentence) ===\n";
    std::cout << ">> " << summary << "\n\n";

    // Export Setup
    constexpr size_t top_n_concepts = 3;
    auto top_concepts = analyzer.get_top_concepts(top_n_concepts);

    ExportEngine exporter("AI_Core_Concepts");
    std::string mermaid_code = exporter.generate_mermaid_mindmap(top_concepts);

    // Save to disk
    std::string file_name = "output_mindmap.md";
    if (exporter.save_to_file(file_name, mermaid_code)) {
        std::cout << "[SUCCESS] Visual mind map generated successfully!\n";
        std::cout << "[INFO] File saved as: build/" << file_name << "\n";
    }

    return 0;
}