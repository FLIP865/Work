#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <iso646.h>

char map[14][21];
char key;
char last_key = 'd';
int stars_collected = 0, speed;
int x = 5, y = 11;
int ox, oy;
int star_x = 8, star_y = 3;

struct snakestail {
    int old_x, old_y;
} snakestail_old[216];

void init_game_state() {
    stars_collected = 0;
    x = 5;
    y = 11;
    ox = x;
    oy = y;
    star_x = 8;
    star_y = 3;

    for (int i = 0; i < 216; i++) {
        snakestail_old[i].old_x = -1;
        snakestail_old[i].old_y = -1;
    }
}

void init_map() {
    strcpy(map[0], "####################");
    for (int i = 1; i < 13; i++) {
        strcpy(map[i], "#                  #");
    }
    strcpy(map[13], "####################");
}

char lvl(int stars_collected) {
    if ((stars_collected >= 0) and (stars_collected <= 3)) {
        printw("1 (x1,00)\n");
    } else if ((stars_collected >= 3) and (stars_collected < 6)) {
        printw("2 (x1,50)\n");
    } else if ((stars_collected >= 6) and (stars_collected < 9)) {
        printw("3 (x2,00)\n");
    } else if (stars_collected >= 9) {
        printw("4 (x2,50)\n");
    }
    return stars_collected;
}

void draw_game() {
    move(0, 0);
    printw("Stars collected: %d\n", stars_collected);
    printw("Speed current:   "); lvl(stars_collected);

    for (int i = 0; i < 14; i++) {
        printw("%s\n", map[i]);
    }
}

void snakemovement() {
    if (map[y][x] == '^') y--;
    if (map[y][x] == 'v') y++;
    if (map[y][x] == '<') x--;
    if (map[y][x] == '>') x++;
}

void update_snake_position() {
    switch (key) {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case ERR: snakemovement();
                  break;
    }
}

bool is_collision() {
    if (y < 0 or y >= 14 or x < 0 or x >= 20) {
        return stars_collected > 0;
    }

    if (map[y][x] == '#') {
        x = ox;
        y = oy;
        return stars_collected > 0;
    }
    return false;
}

void place_star() {
    do {
        star_x = rand() % 18 + 1;
        star_y = rand() % 12 + 1;
    } while (map[star_y][star_x] != ' ');
}

void update_game_logic() {
    ox = x;
    oy = y;

    update_snake_position();

    if (is_collision()) {
        if (stars_collected > 0) {
            cbreak();
            move(9, 5);
            printw("GAME OVER! Press R to retry or Q to quit.\n");
            refresh();

            while (true) {
                key = getch();
                if (key == 'r' or key == 'R') {
                    init_game_state();
                    init_map();
                    return;
                } else if (key == 'q' or key == 'Q') {
                    endwin();
                    exit(0);
                }
            }
        }
        return;
    }

    // Проверка сбора зведз
    if (x == star_x and y == star_y) {
        stars_collected++;
        place_star();
    }
    
    // Установка скорости игры
    if ((stars_collected >= 0) and (stars_collected < 3)) {
        speed = 10;
    } else if ((stars_collected >= 3) and (stars_collected < 6)) {
        speed = 7;
    } else if ((stars_collected >= 6) and (stars_collected < 9)) {
        speed = 5;
    } else if (stars_collected >= 9) {
        speed = 3;
    }

    // Обновление хвоста
    for (int i = stars_collected; i >= 0; i--) {
        snakestail_old[i + 1].old_x = snakestail_old[i].old_x;
        snakestail_old[i + 1].old_y = snakestail_old[i].old_y;
    }
    snakestail_old[0].old_x = ox;
    snakestail_old[0].old_y = oy;

    // Обновление карты
    init_map();
    if (stars_collected > 0) {
        for (int i = 0; i < stars_collected; i++) {
            map[snakestail_old[i].old_y][snakestail_old[i].old_x] = '#';
        }
    }
      if (x > ox)  {
          map[y][x] = '>';
      } else if (x < ox) {
          map[y][x] = '<';
      } else if (y < oy) {
          map[y][x] = '^';
      } else if (y > oy) {
          map[y][x] = 'v';
      } else {
          map[y][x] = '@';
      }

    map[star_y][star_x] = '*';
}

void game_loop() {
    srand(time(NULL));
    init_game_state();
    init_map();
    
    while (true) {
        clear();
        draw_game();
        refresh();
        
        halfdelay(speed);
        key = getch();
        // Если пользователь ввёл новую команду, обновляем направление
        if (key != ERR) {
            if (key == 'w' or key == 's' or key == 'a' or key == 'd') {
                last_key = key;
            } else if (key == 'q' or key == 'Q') {
                break;
            }
        }

        update_game_logic();
    }
}

int main() {
    initscr();
    curs_set(0);
    noecho();

    geme_loop();

    endwin();
    return 0;
}
