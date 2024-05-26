#include "ColoredAnnotations.h"
#include "fpdf_annot.h"

Annotations::Annotations(PDFDoc* doc) : document(doc) {}

Annotations::~Annotations() {}

void Annotations::AddComment(const std::string& text, float x, float y) {
    FPDF_PAGE page = FPDF_LoadPage(document->GetFPDFDocument(), 0);
    if (page) {
        FPDF_ANNOTATION annot = FPDFPage_CreateAnnot(page, FPDF_ANNOT_TEXT);
        FPDFAnnot_SetStringValue(annot, "Contents", text.c_str());
        FS_RECTF rect = { x, y, x + 100, y + 20 };
        FPDFAnnot_SetRect(annot, &rect);
        FPDFPage_CloseAnnot(annot);
        FPDF_ClosePage(page);
    }
}

void Annotations::HighlightText(float x1, float y1, float x2, float y2) {
    FPDF_PAGE page = FPDF_LoadPage(document->GetFPDFDocument(), 0);
    if (page) {
        FPDF_ANNOTATION annot = FPDFPage_CreateAnnot(page, FPDF_ANNOT_HIGHLIGHT);
        FS_QUADPOINTSF quadPoints = { x1, y1, x2, y1, x1, y2, x2, y2 };
        FPDFAnnot_SetQuadPoints(annot, 0, &quadPoints);
        FPDFPage_CloseAnnot(annot);
        FPDF_ClosePage(page);
    }
}

void Annotations::AddNote(const std::string& note, float x, float y) {
    FPDF_PAGE page = FPDF_LoadPage(document->GetFPDFDocument(), 0);
    if (page) {
        FPDF_ANNOTATION annot = FPDFPage_CreateAnnot(page, FPDF_ANNOT_TEXT);
        FPDFAnnot_SetStringValue(annot, "Contents", note.c_str());
        FS_RECTF rect = { x, y, x + 100, y + 100 };
        FPDFAnnot_SetRect(annot, &rect);
        FPDFPage_CloseAnnot(annot);
        FPDF_ClosePage(page);
    }
}