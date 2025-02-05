#include <curses.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

/*
#include <string.h>
#include <unistd.h>
*/

#define BG_GAME_COLOR 1
#define BG_GAME_OVER_COLOR 2
#define SNAKE_HEAD_COLOR 3
#define SNAKE_TAIL_COLOR 4

#define MIN_Y  2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10, SEED_NUMBER=3};

/*
// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
};

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};
struct control_buttons wasd = {'w', 'a', 's', 'd'};
struct control_buttons WASD = {'W', 'A', 'S', 'D'};
*/

// Хвост - это массив состоящий из координат x,y
typedef struct tail_t
{
    int x;
    int y;
} tail_t;


typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize; // Длина хвоста
    tail_t *tail; // Указатель на хвост
    //struct control_buttons controls;
} snake_t;

struct food
{
    int x;
    int y;
    time_t put_time; // Время установки
    char point;
    uint8_t enable; // Флаг, была ли съедена
} food[MAX_FOOD_SIZE];

void initHead(snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
/* Инициализируем генератор случайных чисел */    
    srand(time(NULL));
    head->direction = rand() %4 + 1;
}

void initTail(tail_t t[], size_t size)
{
    struct tail_t init_t = {COLS>>1, LINES>>1};
    for (size_t i = 0; i < size; i++)
        t[i] = init_t;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size + 1;
    //head->controls = default_controls;
}

// Движение головы с учетом текущего направления движения
void goHead(struct snake_t *head)
{
    char ch = 219;
    switch (head->direction)
    {
        //Циклическое движение, чтобы не уходить за пределы экрана
        case LEFT:
            if (head->x <= 0)
                head->x = COLS;
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
            if (head->x >= COLS)
                head->x = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
            if (head->y <= 0)
                head->y = LINES;
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
            if (head->y >= LINES)
                head->y = 0;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    refresh();
}

//Движение хвоста с учетом движения головы
void goTail(struct snake_t *head)
{
    char ch = 176;
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if ( (key == KEY_DOWN || key == 's' || key == 'S') && (snake->direction != UP) )
        snake->direction = DOWN;
    else if ( (key == KEY_UP || key == 'w' || key == 'W') && (snake->direction != DOWN) )
        snake->direction = UP;
    else if ( (key == KEY_RIGHT || key == 'd' || key == 'D') && (snake->direction != LEFT) )
        snake->direction = RIGHT;
    else if ( (key == KEY_LEFT || key == 'a' || key == 'A') && (snake->direction != RIGHT) )
        snake->direction = LEFT;
}

void initFood(struct food f[], size_t size)
{
    struct food init = {COLS>>1, LINES>>1, 0, 0, 0};
    for (size_t i=0; i<size; i++)
        f[i] = init;
}
/* Обновить/разместить текущее зерно на поле */
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}
/* Разместить еду на поле */
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
        putFoodSeed(&f[i]);
}
/* Обновить еду на поле */
void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
        if( f[i].put_time )
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
                putFoodSeed(&f[i]);
}

int main()
{    
    initscr();

/* Задаем цветность игровому полю */    
    start_color();
    init_pair(BG_GAME_COLOR, COLOR_BLUE, COLOR_WHITE);
    init_pair(BG_GAME_OVER_COLOR, COLOR_RED, COLOR_BLACK);
    bkgd(COLOR_PAIR(BG_GAME_COLOR) | ' ');
    //box(stdscr, 179, 196);
    border(0x00ba,0x00ba,0x00cd,0x00cd,0x00c9,0x00bb,0x00c8,0x00bc);
    
/* Инициализиро=уем змейку. Старт начинаем с середины экрана */    
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake, START_TAIL_SIZE, COLS>>1, LINES>>1);
    
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(1, 1,"Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);
    
    int key_pressed = 0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        goHead(snake);
        goTail(snake);
        timeout(100); // Задержка при отрисовке
        refreshFood(food, SEED_NUMBER);
        changeDirection(snake, key_pressed);
    }
    free(snake->tail);
    free(snake);
    
    endwin();
    return 0;
}



/*
int chekCollision()
{
    if()
    {
        beep();
        flash();
        bkgd(COLOR_PAIR(BG__GAME_OVER_COLOR));
        timeout(500);
        clear();
        refresh();
        return 1;
    }
    return 0;
}
*/
