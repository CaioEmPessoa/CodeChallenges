
// basic functions like drawing text, squares, triangles etc

// xy positions for square // width&height of square // color of the square
int* drawSquare(int x, int y, int w, int h, u32 c)
{
	C2D_DrawRectangle(
		convertPos('w', x),
		convertPos('h', y),
		0, w, h,
		c, c, c, c
	);

	int result[4] = {x, y, w, h};
    int *pResult = malloc(sizeof(int) * 4);
    memcpy(pResult, result, sizeof(int) * 4);
    return pResult;
}

int* drawLine(int x0, int y0, int x1, int y1, u32 c, float thickness) {
	C2D_DrawLine(
		convertPos('w', x0), convertPos('h', y0),
		c,
		convertPos('w', x1), convertPos('h', y1),
		c,
		thickness, 1
	);
}


void drawLineBasic(int x0, int y0, int x1, int y1, u32 c, float thickness) {
	int x, y;
	float a;
	int valor;

	a = (y1-y0) / (x1-x0);

	for (x=x0; x<=x1; x++){
		y = nearbyintf(y0 + a * (x - x0));
		drawSquare(x, y, thickness, thickness, c);
	}
}

int* drawText(float x, float y, char* text, float fontSize) {
	C2D_Text txt;
	C2D_TextBuf textBuffer = C2D_TextBufNew(128); // TODO: Change to dynamic value

	C2D_TextParse(&txt, textBuffer, text);
	C2D_TextOptimize(&txt);

	C2D_DrawText(
		&txt, 0,
		convertPos('w', x), convertPos('h', y),
		0.0f,
		fontSize, fontSize
	);

	return 0;
}