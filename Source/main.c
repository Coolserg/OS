void setPixel(int x, int y, int color);
void bkColor(int color);
void drawFillRectangle(int x, int y, int h, int w, int color);
void pause(int ms);
void drawLine(int x1, int y1, int x2, int y2, int color);
void drawCircle(int x_center, int y_center, int r, int color);
void drawSymbol(int symbol, int x, int y, int size, int color);
void LoadScreen();
void LoadScreenSortArray();

#define ARRAY_SYMBOLS_SIZE 3
#define ARRAY_SYMBOLS_ROW 7
#define ARRAY_SYMBOLS_FIELD 5

int _start() {
	LoadScreen();
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
	for(int i = 0; i < 10; i++) {
		if(i % 2 == 0) {
			drawFillRectangle(512, 384, 20, 20, 0xFFFFFF);
		} else {
			drawFillRectangle(512, 384, 20, 20, 0xF754E1);
		}
		pause(50);
	}
	pause(500);
	drawSymbol(2, 20, 5, 5, 0xFFFFFF);
}


void setPixel(int x, int y, int color) {
	char *address;
	asm("mov dword ptr[ebp-4], esi");
	address += ((y * 1024) + x) * 3;
	*(int*)address=*(int*)&color;
}

void drawSymbol(int symbol, int x, int y, int size, int color) {
	//int *address = (int*)0x9000 + (symbol * (ARRAY_SYMBOLS_ROW * ARRAY_SYMBOLS_FIELD));
	char *address = 0x9000 + (symbol * (ARRAY_SYMBOLS_ROW * ARRAY_SYMBOLS_FIELD));
	int pos_x = x;
	int pos_y = y;
	for(int i = 0; i < ARRAY_SYMBOLS_FIELD; i++) {
		for(int j = 0; j < ARRAY_SYMBOLS_ROW; j++) {
			if(*address) {
				drawFillRectangle(pos_x, pos_y, size, size, color);
			}
			pos_y += size;
			address++;
		}
		pos_x += size;
		pos_y = y;
	}
}

void bkColor(int color) {
	for(int i = 0; i < 768; i++) {
		for(int j = 0; j < 1024; j++) {
			setPixel(j, i, color);
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