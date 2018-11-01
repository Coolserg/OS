void setPixel(int x, int y, int color);
void bkColor(int color);
void drawFillRectangle(int x, int y, int h, int w, int color);
void pause(int ms);
void drawLine(int x1, int y1, int x2, int y2, int color);
void drawCircle(int x_center, int y_center, int r, int color);
void drawSymbol(int symbol, int x, int y, int size, int color);
void LoadScreen();

#define ARRAY_SYMBOLS_SIZE 3
#define ARRAY_SYMBOLS_ROW 7
#define ARRAY_SYMBOLS_FIELD 5

int _start() {
	LoadScreen();
	drawFillRectangle(20, 30, 20, 20, 0xFFFFFF);
	while(1);
}

void LoadScreen() {
	bkColor(0x2151A3);
	drawLine(300, 150, 724, 150, 0xFFFFFF);
	drawCircle(512, 384, 200, 0xF754E1);
	drawLine(300, 618, 724, 618, 0xFFFFFF);
	drawFillRectangle(487, 359, 20, 20, 0xF754E1);
	pause(200);
	drawFillRectangle(512, 359, 20, 20, 0xFFFFFF);
	pause(200);
	drawFillRectangle(487, 384, 20, 20, 0xFFFFFF);
	pause(200);
	drawFillRectangle(512, 384, 20, 20, 0xF754E1);
	pause(500);
	drawSymbol(0, 20, 30, 50, 0xFFFFFF);
}

void setPixel(int x, int y, int color) {
	char *address;
	asm("mov dword ptr[ebp-4], esi");
	address += ((y * 1024) + x) * 3;
	*(int*)address=*(int*)&color;
}

void drawSymbol(int symbol, int x, int y, int size, int color) {
	int *address = (char*)0x9000 + (symbol * (ARRAY_SYMBOLS_ROW * ARRAY_SYMBOLS_FIELD));
	if(*address == 1) {
		drawFillRectangle(x, y, size, size, color);
	} else {
		drawFillRectangle(x, y, size, size, 0xF754E1);
	}
}

void bkColor(int color) {
	for(int i = 0; i < 1024; i++) {
		for(int j = 0; j < 768; j++) {
			setPixel(i, j, color);
		}
	}	
}

void drawFillRectangle(int x, int y, int h, int w, int color) {
	int 
		i,
		j;
	for(i = x; i < x+h; i++) {
		for(j = y; j < y+w; j++) {
			setPixel(i, j, color);
		}
	}
}

void drawCircle(int x_center, int y_center, int r, int color) {
	int x = 0;
	int y = r;
	int sigma = 0;
	int delta = 2 - 2 * r;
	while(y >= 0) {
		setPixel(x_center + x, y_center + y, color);
		setPixel(x_center + x, y_center - y, color);
		setPixel(x_center - x, y_center - y, color);
		setPixel(x_center - x, y_center + y, color);
		sigma = 2 * (delta + y) - 1;
		if(delta < 0 && sigma <= 0) {
			x++;
			delta += x + 1;
			continue;
		} else if(delta > 0 && sigma > 0) {
			y--;
			delta -= y + 1;
			continue;
		} else {
			x++;
			delta += x - y;
			y--;
		}
	}
}

void drawLine(int x1, int y1, int x2, int y2, int color) {
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    if (deltaX < 0) deltaX*=(-1);
    if (deltaY < 0) deltaY*=(-1);
    int signX = x1 < x2 ? 1 : -1;
    int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    setPixel(x2, y2, color);
    while(x1 != x2 || y1 != y2) {
        setPixel(x1, y1, color);
        const int error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
}


void pause(int ms) {
	for(int i = 0; i < ms; i++) {
		for(int j = 0; j < 65536; j++) {

		}
	}
}