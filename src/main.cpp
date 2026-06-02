#include <iostream>
#include "DocumentParser.hpp"

int main() {
    // A sample text to test our parser (with punctuation, capitals, and hyphens)
    std::string sample_text = "Modern C++23 is ultra-fast! The text-mining engine processes data efficiently.";
    
    std::cout << "=== Original Text ===\n" << sample_text << "\n\n";

    // Initialize the parser with the sample text
    DocumentParser parser(sample_text);
    
    // Clean the text (lowercase and remove punctuation)
    parser.clean_text();
    std::cout << "=== Cleaned Text ===\n" << parser.get_cleaned_text() << "\n\n";

    // Tokenize the text into string_views
    auto tokens = parser.tokenize();
    
    std::cout << "=== Generated Tokens ===\n";
    for (const auto& token : tokens) {
        std::cout << "- [" << token << "]\n";
    }

    return 0;
}