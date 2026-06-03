# learning-ai-core

`learning-ai-core` is a lightweight software engine developed in **Modern C++ (C++17)** focused on classic Natural Language Processing (NLP) and text-mining. The project aims to analyze complex textual documents, extract key concepts, and structure them into visual summaries to enhance learning efficiency and reduce cognitive load, with a special focus on accessibility for students with learning disabilities (such as dyslexia).

## 🚀 Project Objectives
- **Low-Level Efficiency:** High-performance text processing implemented from scratch, without heavy external dependencies or cloud-based APIs.
- **Classic AI/NLP Algorithms:** Hands-on implementation of core Information Retrieval concepts (Tokenization, TF-IDF weights).
- **Software Engineering Best Practices:** Focus on modern development patterns (Clean Architecture, efficient memory management using `std::string_view`, Move Semantics, and Unit Testing).

## 🛠️ System Architecture
The engine is decoupled into independent modules following SOLID principles:
1. **DocumentParser:** Handles text input, cleaning, and ultra-fast in-memory tokenization.
2. **TextAnalyzer:** Applies statistical metrics to rank term importance based on word frequency.
3. **ExportEngine (In Development):** Translates extracted data into standard graphical formats (Mermaid/Graphviz) for automated mind mapping.

## 📦 Requirements and Build Instructions
This project uses **CMake** as its standard build system.

### Prerequisites
- A compiler supporting C++17 (GCC 7+, Clang 5+, or MSVC 2017+)
- CMake 3.15 or higher