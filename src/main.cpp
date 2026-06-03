#include <iostream>
#include "DocumentParser.hpp"
#include "TextAnalyzer.hpp"

int main() {
    // A sample academic text to test the complete NLP pipeline
    std::string academic_text = 
        "Artificial intelligence is a core pillar of modern computer science. "
        "Modern artificial intelligence systems process vast amounts of data to extract information. "
        "Computer memory stores this data, but artificial intelligence learns patterns from the data itself. "
        "Many developers use algorithms to optimize software performance.";

    std::cout << "Target Document for Analysis ===\n" << academic_text << "\n\n";

    // Initialize the parser and clean the raw text
    DocumentParser parser(academic_text);
    parser.clean_text();
    
    // Tokenize the cleaned text into lightweight string_views
    auto tokens = parser.tokenize();

    // Pass the tokens to the analyzer and run the TF-IDF algorithm
    TextAnalyzer analyzer(tokens);
    analyzer.calculate_frequencies();

    // Extract the top 3 core concepts from the text
    constexpr size_t top_n_concepts = 3;
    auto top_concepts = analyzer.get_top_concepts(top_n_concepts);

    std::cout << "Extracted Core Concepts (Top " << top_n_concepts << ") ===\n";
    for (size_t i = 0; i < top_concepts.size(); ++i) {
        std::cout << i + 1 << ". Concept: \"" << top_concepts[i].first 
                  << "\" | Statistical Weight: " << top_concepts[i].second << "\n";
    }

    return 0;
}