#include "ExportEngine.hpp"
#include <fstream>
#include <sstream>

ExportEngine::ExportEngine(std::string document_title) 
    : m_document_title(std::move(document_title)) {}

std::string ExportEngine::generate_mermaid_mindmap(
    const std::vector<std::pair<std::string, double>>& concepts) const {
    
    std::stringstream ss;
    
    // Initialize a Mermaid mindmap diagram
    ss << "```mermaid\n";
    ss << "mindmap\n";
    
    // Root node: The main document topic
    ss << "  root((" << m_document_title << "))\n";
    
    // Using classic item access (.first and .second) to maintain strict Clang compatibility
    for (const auto& item : concepts) {
        ss << "    " << item.first << "[" << item.first << " <br/> Score: " << item.second << "]\n";
    }
    
    ss << "```\n";
    return ss.str();
}

bool ExportEngine::save_to_file(std::string_view file_path, std::string_view content) const {
    std::ofstream output_file{std::string(file_path)};
    
    if (!output_file.is_open()) {
        return false;
    }
    
    output_file << content;
    return true;
}