//
// Created by Paweł Kisielewicz on 02/10/2022.
//

#ifndef POSUI_CURSESTUI_H
#define POSUI_CURSESTUI_H


class CursesTUI {

public:
    void Sound(unsigned frequency);

    void NoSound();

    void Delay(unsigned milliseconds);

    int WhereX();

    int WhereY();

    void GotoXY(int x, int y);

    void ClrScr();

    int GetText(int left, int top, int right, int bottom, void *destin);

    int PutText(int left, int top, int right, int bottom, void *source);

    void Window(int left, int top, int right, int bottom);

    void TextBackground(int newColor);

    void TextColor(int newColor);

    bool Init();

    bool Close();

};


#endif //POSUI_CURSESTUI_H
