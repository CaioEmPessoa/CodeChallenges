// ------------ Game-specific functions ------------ //

void flipScreens(void* n)
{
    cursorBot = cursorBot ? false : true;
}

void registerLineTouch(parameter_t* params, int param_count)
{

	if (tmpLine.start_x == touch.px ||
		tmpLine.start_y == touch.py  ) return;

	if (!tmpLine.start_x) {
		tmpLine.start_x = touch.px;
		tmpLine.start_y = touch.py;
	}
	else if (!tmpLine.end_x) {
		tmpLine.end_x = touch.px;
		tmpLine.end_y = touch.py;
	}

	if (tmpLine.end_x) {

		addNewLine(tmpLine);

		tmpLine.start_x = 0; tmpLine.start_y = 0;
		tmpLine.end_x = 0; tmpLine.end_y = 0;
	}
}

void removeLinesCommand(parameter_t* params, int param_count)
{
	removeLines();
}

void setAlgo(parameter_t* params, int param_count)
{
	algo = params[0].value.int_val;

	commandsValid = false;
	clear_button_commands();
}