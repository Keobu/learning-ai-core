#include "DocumentParser.hpp"
#include <algorithm>
#include <cctype>

DocumentParser::DocumentParser(std::string raw_text) 
    : m_raw_text(std::move(raw_text)), m_cleaned_text("") {}

void DocumentParser::clean_text() {
    m_cleaned_text.clear();
    // Optimization: reserve memory to avoid multiple reallocations during the loop
    m_cleaned_text.reserve(m_raw_text.size()); 

    for (char c : m_raw_text) {
        // Keep only alphanumeric characters and spaces
        if (std::isalnum(static_cast<unsigned char>(c)) || std::isspace(static_cast<unsigned char>(c))) {
            // Convert to lowercase to normalize tokens (e.g., "Data" and "data" become identical)
            m_cleaned_text.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
        } else if (c == '-' || c == '\'') {
            // Replace hyphens and apostrophes with a space to separate connected words
            m_cleaned_text.push_back(' ');
        }
    }
}

std::vector<std::string_view> DocumentParser::tokenize() const {
    std::vector<std::string_view> tokens;
    std::string_view text_view(m_cleaned_text);

    size_t start = 0;
    size_t end = text_view.find_first_of(" \t\n\r");

    while (end != std::string_view::npos) {
        // Only extract the token if it's not an empty space caused by consecutive delimiters
        if (end > start) {
            tokens.push_back(text_view.substr(start, end - start));
        }
        start = text_view.find_first_not_of(" \t\n\r", end);
        end = text_view.find_first_of(" \t\n\r", start);
    }

    // Add the remaining last word if present
    if (start < text_view.size()) {
        tokens.push_back(text_view.substr(start));
    }

    return tokens;
}

std::vector<std::string> DocumentParser::split_sentences() const {
    std::vector<std::string> sentences;
    std::string current;

    for (char c : m_raw_text) {
        // Skip annoying newline characters to keep sentences clean
        if (c == '\n' || c == '\r') continue;

        current.push_back(c);

        // Split when hitting a proper sentence delimiter
        if (c == '.' || c == '!' || c == '?') {
            // Trim leading spaces before storing
            size_t start = current.find_first_not_of(" \t");
            if (start != std::string::npos) {
                sentences.push_back(current.substr(start));
            }
            current.clear();
        }
    }

    // Safety fallback: if the text didn't end with a punctuation mark, flush the rest
    if (!current.empty()) {
        size_t start = current.find_first_not_of(" \t");
        if (start != std::string::npos) {
            sentences.push_back(current.substr(start));
        }
    }

    return sentences;
}