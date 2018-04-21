/*
Header file : Arts.h
기타 추가적인 시스템 기능
Remark : 2018.04.21 정지웅.
*/
#define DEFAULT_COLOR 7 

typedef enum {
	NOCURSOR,
	SOLIDCURSOR,
	NORMALCURSOR
} CURSOR_TYPE;

void gotoxy(int, int);

void textcolor(int);

void setcursortype(CURSOR_TYPE);

void type_effect(char *, int);

void clearbuffer();

void titleLine(const char *);