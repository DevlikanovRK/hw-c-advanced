#include <curses.h>
#include <unistd.h>

int main() {
    initscr();
    char string[]="Hello world!";
    int x=10,y=10;
    printw(string); /* Напечатать на стандартном экране stdscr */
                    /* в текущей позиции курсора  */
    mvprintw(y, x, string);/* Напечатать в позиции (y, x)  */
    getch();
    endwin();
    return 0;
}
