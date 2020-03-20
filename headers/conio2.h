#ifndef CONIO2_H_INCLUDED
#define CONIO2_H_INCLUDED

/*
	Yan Almeida Garcia - 2019 199 05
*/
 
#include <time.h>
#include <windows.h>   
   
void textcolor(int c);
void textbackground(int c);
void gotoxy(int x, int y);
void movexy(int x, int y, char *c);
void borders(int a, int b, int x, int y);
void date(int x, int y);

int i, j;

	// esquema de cores 
enum cor {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
}; 
	// esquema de cores >> textcolor(L); -> random colors
void textcolor(int c){ // textcolor(COR)
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= c);
}
	// esquema de cores >> text background
void textbackground(int c){ // textbackground(COR)
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= (c << 4));
}
	// coordenadas >> x/y
void gotoxy(int x, int y){ // gotoxy(LIN, COL)
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	// coordenadas + cadeia de caracteres
void movexy(int x, int y, char *c){ // movexy(LIN, COL, "texto")
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("%s", c);
}
	// borderline
void borders(int a, int b, int x, int y){ // bordas(altura, largura, LIN, COL)
	for(i = 0; i < a + 2; i++){
    	gotoxy(x, y + i);
    	for(j = 0; j < b + 2; j++){
    	//	textcolor(LIGHT_GRAY); >> change color
	    	if(i == 0) printf("Û");
	    	else if(j == 0) printf("Û");
	    	else if(j == b + 1) printf("Û");
	    	else if(i == a + 1) printf("Û");
	    	else printf(" ");
		}
	}
}
	// data e hora >> momento de execução
struct tm* DH;  
void date(int x, int y){ // date(LIN, COL) -> coordenadas para data
	time_t segundos;
 
	time(&segundos);   

  	DH = localtime(&segundos);  
    
    gotoxy(x, y);
    textbackground(DARK_GRAY);
    printf("%.2d/%.2d/%.4d ", DH->tm_mday, DH->tm_mon + 1, DH->tm_year + 1900); // data
 	printf("- %.2d:%.2d:%.2d", DH->tm_hour, DH->tm_min, DH->tm_sec); // hora   
}
#endif // CONIO2_H_INCLUDED
