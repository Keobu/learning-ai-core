#ifndef DOCUMENT_PARSER_HPP
#define DOCUMENT_PARSER_HPP

#include <string>
#include <vector>
#include <string_view>

class DocumentParser {
public:
    // Explicit constructor to prevent implicit conversions
    explicit DocumentParser(std::string raw_text);

    // Cleans the text by removing punctuation and converting characters to lowercase
    void clean_text();

    // Splits the cleaned text into individual words (tokens)
    [[nodiscard]] std::vector<std::string_view> tokenize() const;

    // Splits the cleaned text into individual sentences
    [[nodiscard]] std::vector<std::string> split_sentences() const;

    // Getter for the internal cleaned text buffer
    [[nodiscard]] const std::string& get_cleaned_text() const { return m_cleaned_text; }

private:
    std::string m_raw_text;
    std::string m_cleaned_text;
};

#endif // DOCUMENT_PARSER_HPP