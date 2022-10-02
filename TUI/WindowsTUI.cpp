//
// Created by Paweł Kisielewicz on 02/10/2022.
//

#include "WindowsTUI.h"

void WindowsTUI::sound(unsigned int frequency) {
    BOOL ret;
    DWORD dwDuration = 1;// minimalna wartoœæ 1ms
    ret = Beep(frequency, dwDuration);
    SprawdzFunkcje(ret, "Beep");
}

void WindowsTUI::NoSound(void) {/* procedura pusta*/; }

void WindowsTUI::delay(unsigned int milliseconds) {
    Sleep(milliseconds);// Sleep jest typu void
}

int WindowsTUI::wherex(void) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret;
    ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    SprawdzFunkcje(ret, "GetConsoleScreenBufferInfo");
    return (csbi.dwCursorPosition.X);
}

int WindowsTUI::wherey(void) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret;
    ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    SprawdzFunkcje(ret, "GetConsoleScreenBufferInfo");
    return (csbi.dwCursorPosition.Y);
}

void WindowsTUI::gotoxy(int x, int y) {
    COORD coordScreen;
    BOOL ret;
    coordScreen.X = x;
    coordScreen.Y = y;
    ret = SetConsoleCursorPosition(hConsoleOutput, coordScreen);
    SprawdzFunkcje(ret, "SetConsoleCursorPosition");
}

void WindowsTUI::clrscr(void) {
    Cls();
}

int WindowsTUI::gettext(int left, int top, int right, int bottom, void *destin) {

    // przepisuje z buforka du¿ego do buforka ma³ego
    int x, y;
    COORD dwReadCoord;
    LPTSTR kod_znak;
    LPWORD attr;
    LPDWORD number0, number1;
    // znak
    for (x = left; x < right + 1; x++)
        for (y = top; y < bottom + 1; y++) {
            dwReadCoord.X = x;
            dwReadCoord.Y = y;
            ReadConsoleOutputCharacter(hConsoleOutput, &kod_znak, sizeof(kod_znak), dwReadCoord, &number0);
            be.znak[x][y] = kod_znak;
        }
    // atrybuty znaku
    for (x = left; x < right + 1; x++)
        for (y = top; y < bottom + 1; y++) {
            dwReadCoord.X = x;
            dwReadCoord.Y = y;
            SetConsoleCursorPosition(hConsoleOutput, dwReadCoord);
            ReadConsoleOutputAttribute(hConsoleOutput, &attr, sizeof(attr), dwReadCoord, &number1);
            be.atrybut[x][y] = attr;
        }
    return 1;
}

int WindowsTUI::puttext(int left, int top, int right, int bottom, void *source) {

    // wydaje buforek ma³y na ekranik
    int x, y;
    //
    for (x = left; x < right + 1; x++)
        for (y = top; y < bottom + 1; y++) {
            gotoxy(x, y);
            SetConsoleTextAttribute(hConsoleOutput, be.atrybut[x][y]);
            cprintf("%c", be.znak[x][y]);
        }
    return 1;
}

void WindowsTUI::window(int left, int top, int right, int bottom) {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    BOOL ret;
    ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    SprawdzFunkcje(ret, "GetConsoleScreenBufferInfo");
    csbi.srWindow.Left = left;

    csbi.srWindow.Top = top;
    csbi.srWindow.Right = right;
    csbi.srWindow.Bottom = bottom;
    // ...chyba trzeba u¿yæ funkcji Set...

}

void WindowsTUI::SprawdzFunkcje(BOOL ret, PSTR nazwa_funkcji) {
    TCHAR bufor[MAX_WART_BUFORA_BLEDU];
    int nr_bledu;
    if(ret!=TRUE)
    {	nr_bledu = GetLastError();
        sprintf(bufor,"%d",nr_bledu);
        //MessageBox(NULL,TEXT("Numer b³êdu:\n")TEXT(bufor),"B³¹d procedury: " TEXT(nazwa_funkcji),MB_OK|MB_ICONERROR);
    }
}

BOOL WindowsTUI::InitConsole(void) {
    BOOL ret;
    HANDLE hStdIn, hStdOut; /* standard input, output handles */
    DWORD dwMode;
    /* array of console input event records */
    INPUT_RECORD inputBuffer;
    DWORD dwInputEvents; /* number of events actually read */
    CHAR bOutBuf[256]; /* buffer to format event information into */
    /* used to get the new console screen buffer size if it is changed */
    COORD coordScreen; /* used when reading the index number from the screen */
    CHAR *szLineBuf; /* buffer to read the index number into */
    DWORD cCharsRead;
    enum cAPIs apiNumber; /* the index number of the API read from the screen */
    CONSOLE_CURSOR_INFO cci; /* used when turning off the cursor */
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* used to get cursor position */
    OSVERSIONINFO osVer; /* for GetVersionEx() */
// step 1
    //ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
    //SprawdzFunkcje(ret, "GetConsoleScreenBufferInfo");
// step 2 ???

    if (csbi.dwCursorPosition.X | csbi.dwCursorPosition.Y)
    {
        ret = FreeConsole();
        SprawdzFunkcje(ret, "FreeConsole");
        ret = AllocConsole();
        SprawdzFunkcje(ret, "AllocConsole");
    }

// step 3 nazwa konsoli
    /* let's put up a meaningful console title */
    ret = SetConsoleTitle("System WEWY wersja 1.0.0");
    SprawdzFunkcje(ret, "SetConsoleTitle");
// step 4
    /* get the standard handles */
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SprawdzFunkcje(hStdOut != INVALID_HANDLE_VALUE, "GetStdHandle");
    hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    SprawdzFunkcje(hStdIn != INVALID_HANDLE_VALUE, "GetStdHandle");
    //hStdIn = hConsoleInput;
    //hStdOut = hConsoleOutput;
    /* set up mouse and window input */
    ret = GetConsoleMode(hStdIn, &dwMode);
    SprawdzFunkcje(ret, "GetConsoleMode");
    /* when turning off ENABLE_LINE_INPUT, you MUST also turn off */
    /* ENABLE_ECHO_INPUT. */

    ret = SetConsoleMode(hStdIn, (dwMode & ~(ENABLE_LINE_INPUT |
                                             ENABLE_ECHO_INPUT)) | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    SprawdzFunkcje(ret, "SetConsoleMode");


    /* save then hide the cursor */

    cci.dwSize = 100;
    cci.bVisible = FALSE;
    ret = SetConsoleCursorInfo(hStdOut, &cci);
    SprawdzFunkcje(ret, "SetConsoleCursorInfo");

    /* resize console to CONX * CONY and put list of console APIs up */
    // showConAPIs(hStdOut);
    /* This is the main input loop. Read from the input queue and process */
    /* the events read */
    // szLineBuf = (char *) malloc(getConX(hStdOut));
    // SprawdzFunkcje(szLineBuf, "malloc");
    return ret;
}

void WindowsTUI::Cls(void) {
    COORD coordScreen = { 0, 0 };
    BOOL ret;
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    SprawdzFunkcje(ret, "GetConsoleScreenBufferInfo");
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    // wype³nienie ekranu "pustym znakiem"
    ret = FillConsoleOutputCharacter(hConsoleOutput, (TCHAR) ' ',
                                     dwConSize, coordScreen, &cCharsWritten);
    SprawdzFunkcje(ret, "FillConsoleOutputCharacter");

    ret = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    SprawdzFunkcje(ret, "ConsoleScreenBufferInfo");

    ret = FillConsoleOutputAttribute(hConsoleOutput, csbi.wAttributes,
                                     dwConSize, coordScreen, &cCharsWritten);
    SprawdzFunkcje(ret, "FillConsoleOutputAttribute");
    // pozycja kursora (0,0) - struktura coordScreen
    ret = SetConsoleCursorPosition(hConsoleOutput, coordScreen);
    SprawdzFunkcje(ret, "SetConsoleCursorPosition");
    return;
}

void WindowsTUI::textbackground(int newcolor) { ; }

void WindowsTUI::textcolor(int newcolor) { ; }
