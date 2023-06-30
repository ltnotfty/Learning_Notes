#include <ncurses.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 10

struct hPos {
    int x;
    int y;
    int dir;
};



void putPoint(int y, int x, int dirChar)
{


    attron(COLOR_PAIR(2) );
    attron(A_BLINK);

    mvprintw(y, x,"%c", dirChar);
   //  attroff(A_BLINK);
    attron(COLOR_PAIR(2));
}
void Test_Color_Support()
{
    if (!has_colors()) {
        fprintf( stderr, "this terminal don't support colors!!!");
        endwin();
        exit(EXIT_FAILURE);
    }
    else {
        fprintf(stdout, "this terminal support colors!!!\n");
    }

}



void putBorder(int COLS, int ROWS, int bChar)
{
    for ( int i = 0; i <= COLS; ++i) {
        for ( int j = 0; j <= ROWS; ++j ) {
            if (COLS == i  || ROWS == j || i == 0 || j == 0 ) {

                attron(COLOR_PAIR(1));
                mvaddch(i, j, bChar);
                attroff(COLOR_PAIR(1));
            }
        }
    }

}
enum HEAD_DIR
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
};
int DIR_CHAR[] = { '<', '>','A', 'V'};

int getRand( int lb, int rb )
{
    if ( lb == rb)
        return  lb;
    srand((unsigned ) time( NULL) );

    int MOD = rb - lb ;


    return rand() % MOD + lb;
}

int main()
{

    int xBOUND = 10;
    int yBOUND = 10;

    int ch;
    initscr();
    Test_Color_Support();
    cbreak();
    start_color();
    init_pair( 1, COLOR_RED, COLOR_RED);
    init_pair( 2, COLOR_YELLOW, COLOR_BLACK);


    struct hPos hPos;
    hPos.x = hPos.y = 1;

    while ( (ch = getch() ) !=  'q')
    {
        switch( ch )
        {
            case 'w':
                if ( hPos.y > 1)
                    --hPos.y, hPos.dir = UP;
                break;
            case 's':
                if ( hPos.y + 1 < yBOUND)
                    ++hPos.y, hPos.dir = DOWN;
                break;
            case 'a':
                if ( hPos.x > 1)
                    --hPos.x, hPos.dir = LEFT;
                break;
            case 'd':
                if ( hPos.x + 1 < xBOUND )
                    ++hPos.x, hPos.dir = RIGHT;
                break;
            default:
                ;
        }

        clear();
        putBorder(yBOUND, xBOUND, '#');
        putPoint(hPos.y, hPos.x, DIR_CHAR[hPos.dir]);


        move(hPos.y, hPos.x);
        refresh();
    }
    
    endwin();
    return 0;
}


