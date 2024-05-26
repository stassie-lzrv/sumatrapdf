#pragma once

#include <string>
#include "PDFDoc.h"

class Annotations {
public:
    Annotations(PDFDoc* doc);
    ~Annotations();

    void AddComment(const std::string& text, float x, float y);
    void HighlightText(float x1, float y1, float x2, float y2);
    void AddNote(const std::string& note, float x, float y);

private:
    PDFDoc* document;
};