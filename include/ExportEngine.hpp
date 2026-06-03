#ifndef EXPORT_ENGINE_HPP
#define EXPORT_ENGINE_HPP

#include <string>
#include <vector>
#include <string_view>

class ExportEngine {
public:
    // Constructor taking the document title/central topic
    explicit ExportEngine(std::string document_title);

    // Generates a visual mind map in Mermaid.js syntax based on the extracted concepts
    [[nodiscard]] std::string generate_mermaid_mindmap(
        const std::vector<std::pair<std::string, double>>& concepts) const;

    // Saves the generated Mermaid code into a file (.md or .mmd)
    [[nodiscard]] bool save_to_file(std::string_view file_path, std::string_view content) const;

private:
    std::string m_document_title;
};

#endif // EXPORT_ENGINE_HPP