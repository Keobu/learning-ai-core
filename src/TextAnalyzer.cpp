#include "TextAnalyzer.hpp"
#include <cmath>
#include <algorithm>

TextAnalyzer::TextAnalyzer(std::vector<std::string_view> tokens) 
    : m_tokens(std::move(tokens)) {}

void TextAnalyzer::calculate_frequencies() {
    if (m_tokens.empty()) return;

    m_term_counts.clear();
    m_tfidf_scores.clear();

    // Term Frequency (TF) - Count raw occurrences of each unique word
    for (std::string_view token : m_tokens) {
        // Constructing std::string from std::string_view only upon hash map insertion
        m_term_counts[std::string(token)]++;
    }

    size_t total_words = m_tokens.size();

    // Inverse Document Frequency (IDF) & Score Combination
    for (const auto& [word, count] : m_term_counts) {
        // Local Term Frequency: relative frequency in this document
        double tf = static_cast<double>(count) / total_words;

        // Custom heuristic IDF to penalize stop-words without an external dictionary
        double idf = 1.0;
        if (word.size() <= 3) {
            // Heavily penalize short filler words like "the", "and", "to", "it"
            idf = 0.1; 
        } else {
            // Standard logarithmic IDF formula adapted for local document metrics
            idf = std::log(1.0 + (static_cast<double>(total_words) / (1.0 + count)));
        }

        // Final score weight calculation
        m_tfidf_scores[word] = tf * idf;
    }
}

std::vector<std::pair<std::string, double>> TextAnalyzer::get_top_concepts(size_t top_n) const {
    // Copy hash map elements into a vector to allow sorting
    std::vector<std::pair<std::string, double>> sorted_scores(m_tfidf_scores.begin(), m_tfidf_scores.end());

    // Sort the vector in descending order using a C++ lambda function
    std::sort(sorted_scores.begin(), sorted_scores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Prevent out-of-bounds resizing if the text has fewer unique words than requested
    if (sorted_scores.size() > top_n) {
        sorted_scores.resize(top_n);
    }

    return sorted_scores;
}