#include <curses.h>
#include <unistd.h>

int main() {
    initscr();
    printw("Hello World !!!");
    printw("\nPress any key to continue... ");
    refresh(); // по пробуйте включить и выключить
    sleep(3);
    getch();
    endwin();
    return 0;
}
