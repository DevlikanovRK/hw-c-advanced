#include <stdio.h>
#include <curses.h>

int main(int argc, char **argv)
{
    int ch;
    initscr();  // Начать curses mode
    raw();      // Отключаем buffering. Ctrl+C не завершит программу
    noecho(); // Отключаем echo() режим пока считываем символы getch
    printw("Type text: \n");
    while( (ch = getch()) != '.')
    {
        printw("%c", ch);
    }
    //refresh(); // Печатаем это на экран
    getch();   // Ждем пока пользователь нажмет клавишу
    endwin();  // Завершить curses mode
    return 0;
}
