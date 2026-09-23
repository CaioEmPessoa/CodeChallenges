
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

	int result[4] = {x, -y, w, h};
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
int* drawLineCoords(Coords start, Coords end, u32 c, float thickness) {
	C2D_DrawLine(
		convertPos('w', start.x), convertPos('h', start.y),
		c,
		convertPos('w', end.x), convertPos('h', end.y),
		c,
		thickness, 1
	);
}

int* drawText(float x, float y, char* text, C2D_TextBuf textBuffer, float fontSize) {
	C2D_Text txt;

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

int* drawTextQuick(float x, float y, char* text, float fontSize) {
	C2D_TextBuf textBuffer = C2D_TextBufNew(128); // TODO: Change to dynamic value

	drawText(x, y, text, textBuffer, fontSize);
}


// Activity draws
#include <math.h>

int* drawCube(Cube cube, int step)
{
	Coords
	top_left=cube.top_left,
	top_right=cube.top_right,
	bot_left=cube.bot_left,
	bot_right=cube.bot_right;

	// Calculate center point of the cube
	float center_x = (top_left.x + bot_right.x) / 2.0f;
	float center_y = (top_left.y + bot_right.y) / 2.0f;

	// Scale each corner relative to the center
	top_left.x = center_x + (top_left.x - center_x) * cube.scale;
	top_left.y = center_y + (top_left.y - center_y) * cube.scale;

	top_right.x = center_x + (top_right.x - center_x) * cube.scale;
	top_right.y = center_y + (top_right.y - center_y) * cube.scale;

	bot_left.x = center_x + (bot_left.x - center_x) * cube.scale;
	bot_left.y = center_y + (bot_left.y - center_y) * cube.scale;

	bot_right.x = center_x + (bot_right.x - center_x) * cube.scale;
	bot_right.y = center_y + (bot_right.y - center_y) * cube.scale;

	// Rotate each corner around the center by cube.angle degrees
	float rad = cube.angle * (float)M_PI / 180.0f;
	float cos_a = cosf(rad);
	float sin_a = sinf(rad);

	// top_left
	{
		float dx = top_left.x - center_x;
		float dy = top_left.y - center_y;
		top_left.x = center_x + dx * cos_a - dy * sin_a;
		top_left.y = center_y + dx * sin_a + dy * cos_a;
	}
	// top_right
	{
		float dx = top_right.x - center_x;
		float dy = top_right.y - center_y;
		top_right.x = center_x + dx * cos_a - dy * sin_a;
		top_right.y = center_y + dx * sin_a + dy * cos_a;
	}
	// bot_left
	{
		float dx = bot_left.x - center_x;
		float dy = bot_left.y - center_y;
		bot_left.x = center_x + dx * cos_a - dy * sin_a;
		bot_left.y = center_y + dx * sin_a + dy * cos_a;
	}
	// bot_right
	{
		float dx = bot_right.x - center_x;
		float dy = bot_right.y - center_y;
		bot_right.x = center_x + dx * cos_a - dy * sin_a;
		bot_right.y = center_y + dx * sin_a + dy * cos_a;
	}

	if (step >= 2)
		drawLine(
			top_left.x,
			top_left.y,
			top_right.x,
			top_right.y,
			getColor("black"),
			4
		);
	if (step >= 3)
		drawLine(
			top_right.x,
			top_right.y,
			bot_right.x,
			bot_right.y,
			getColor("black"),
			4
		);
	if (step >= 4)
		drawLine(
			bot_right.x,
			bot_right.y,
			bot_left.x,
			bot_left.y,
			getColor("black"),
			4
		);
	if (step >= 5)
		drawLine(
			bot_left.x,
			bot_left.y,
			top_left.x,
			top_left.y,
			getColor("black"),
			4
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