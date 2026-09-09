
typedef struct {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Line;

int lastLineIndex = 0;
Line tmpLine;
Line lines[LINES_AMMT];

void addNewLine(Line line) {
    lines[lastLineIndex] = line;
    lastLineIndex++;
}

void removeLines() {
    memset(lines, 0, sizeof lines);
}