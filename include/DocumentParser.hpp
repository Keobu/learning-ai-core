#ifndef DOCUMENT_PARSER_HPP
#define DOCUMENT_PARSER_HPP

#include <string>
#include <vector>
#include <string_view>

class DocumentParser {
public:
    // Explicit constructor to prevent implicit conversions
    // Uses std::move to efficiently transfer ownership of the input string
    explicit DocumentParser(std::string raw_text);

    // Cleans the text by removing punctuation and converting characters to lowercase
    void clean_text();

    // Splits the cleaned text into individual words (tokens)
    // Returns std::string_view to point directly inside the internal string buffer without copying memory
    [[nodiscard]] std::vector<std::string_view> tokenize() const;

    // Getter for the internal cleaned text buffer
    [[nodiscard]] const std::string& get_cleaned_text() const { return m_cleaned_text; }

private:
    std::string m_raw_text;
    std::string m_cleaned_text;
};

#endif