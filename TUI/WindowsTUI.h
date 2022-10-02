//
// Created by Paweł Kisielewicz on 02/10/2022.
//

#ifndef POSUI_WINDOWSTUI_H
#define POSUI_WINDOWSTUI_H


class WindowsTUI {

public:
    void sound(unsigned frequency);

    void NoSound(void);

    void delay(unsigned milliseconds);

    int wherex(void);

    int wherey(void);

    void gotoxy(int x, int y);

    void clrscr(void);

    int gettext(int left, int top, int right, int bottom, void *destin);

    int puttext(int left, int top, int right, int bottom, void *source);

    void window(int left, int top, int right, int bottom);

    void textbackground(int newcolor);

    void textcolor(int newcolor);

    void SprawdzFunkcje(BOOL ret, PSTR nazwa_funkcji);

    BOOL InitConsole(void);

    void Cls(void);
};


#endif //POSUI_WINDOWSTUI_H
