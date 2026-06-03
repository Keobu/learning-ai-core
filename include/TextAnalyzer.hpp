#ifndef TEXT_ANALYZER_HPP
#define TEXT_ANALYZER_HPP

#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

class TextAnalyzer {
public:
    explicit TextAnalyzer(std::vector<std::string_view> tokens);
    void calculate_frequencies();
    [[nodiscard]] std::vector<std::pair<std::string, double>> get_top_concepts(size_t top_n) const;
    
    //Returns a percentage (0.0 to 100.0) representing text complexity
    [[nodiscard]] double calculate_information_density() const;

    //Evaluates sentences and returns the single most informative summary sentence
    [[nodiscard]] std::string get_summary_sentence(const std::vector<std::string>& sentences) const;
private:
    std::vector<std::string_view> m_tokens;
    std::unordered_map<std::string, size_t> m_term_counts;
    std::unordered_map<std::string, double> m_tfidf_scores;
};

#endif // TEXT_ANALYZER_HPP