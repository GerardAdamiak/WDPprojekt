#include <allegro5\allegro5.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <cmath>
#include <time.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h> 
#include <allegro5\allegro_acodec.h> 
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <ctime>
#define BACKGROUND_FILE     "snake.png"
using namespace std;

const int height = 600, width = 800;

int main() {
    srand(time(NULL));
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_TIMER* blinkTimer = al_create_timer(0.5); // New timer for blinking
    ALLEGRO_TIMER* blinkTimer2 = al_create_timer(0.2); // New timer for blinking
    ALLEGRO_SAMPLE* MUZ = NULL;
    const float FPS = 60.0;
    const float frameFPS = 15.0;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_BITMAP* background = NULL;
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();



 
    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_load_ttf_font("test.ttf", 40, 0);
    ALLEGRO_FONT* font1 = al_load_ttf_font("test3.ttf", 200, 0);
    ALLEGRO_FONT* font2 = al_load_ttf_font("samson.ttf", 40, 0);
    ALLEGRO_FONT* font4 = al_load_ttf_font("samson.ttf", 80, 0);
    bool done = false, active = false;
    bool draw = true;
    int x = 0, y = 0, moveSpeed = 5;

    if (!font1 || !font2)
        return -2;
    if (!display)
        return -1;
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_timer_event_source(blinkTimer)); // Register the blinkTimer
    al_register_event_source(queue, al_get_timer_event_source(blinkTimer2)); // Register the blinkTimer
    bool redraw = true;
    bool blink = false; // Variable to control the blinking state
    ALLEGRO_EVENT event;

    int wazX = 270;  // Initial X position
    int wazY = 200; // Initial Y position
    al_start_timer(timer);
    al_start_timer(blinkTimer); // Start the blinkTimer
    al_start_timer(blinkTimer2);
    string direction;



    while (1) {
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (event.timer.source == blinkTimer)
            {
                blink = !blink; // Toggle the blink state
                redraw = true;
            }
            else {
                redraw = true;
            }
        }
        else if ((event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_SPACE) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)) {
            break;
        }
        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            background = al_load_bitmap(BACKGROUND_FILE);
            al_draw_bitmap(background, 100, 30, 0);
            // Get the window dimensions
            int windowWidth = al_get_display_width(display);
            int windowHeight = al_get_display_height(display);

            // Get the text dimensions
            int textWidth1 = al_get_text_width(font1, "SNAKE");
            int textHeight1 = al_get_font_ascent(font1);
            int textWidth2 = al_get_text_width(font2, "press space to start");
            int textHeight2 = al_get_font_ascent(font2);

            // Calculate the position to center the text
            int textX1 = (windowWidth - textWidth1) / 2;
            int textY1 = (windowHeight - textHeight1) / 2;
            int textX2 = (windowWidth - textWidth2) / 2;
            int textY2 = (windowHeight - textHeight2) / 2;
            al_draw_text(font1, al_map_rgb(255, 255, 255), textX1, 0, 0, "SNAKE");
            if (!blink) {
                al_draw_text(font2, al_map_rgb(255, 255, 255), textX2, 0.9 * (windowHeight - textHeight2), 0, "press space to start");
            }
            al_flip_display();

            redraw = false;
        }
    }if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode==ALLEGRO_KEY_SPACE) {
        al_clear_to_color(al_map_rgb(0, 0, 0));



        int dolzina = 800;
        int visina = 600;

        ALLEGRO_SAMPLE* MUZ = NULL;
        const float FPS = 60.0;
        const float frameFPS = 15.0;

        if (!al_init()) return -1;
    
        if (!display) return -1;
      
        if (!al_install_audio()) {
            fprintf(stderr, "failed to initialize audio!\n");
            return -2;
        }

        if (!al_init_acodec_addon()) {
            fprintf(stderr, "failed to initialize audio codecs!\n");
            return -3;
        }

        if (!al_reserve_samples(1)) {
            fprintf(stderr, "failed to reserve samples!\n");
            return -4;
        }


        bool done = false, active = false;
        bool draw = true;
        int x = 0, y = 0, moveSpeed = 5;


        al_init_primitives_addon();
        al_install_keyboard();
        al_init_image_addon();
        al_init_font_addon();
        al_init_ttf_addon();

        MUZ = al_load_sample("coin.mp3");
        if (!MUZ) {
            printf("Audio clip sample not loaded!\n");
            return -5;
        }
        ALLEGRO_BITMAP* headRight = al_load_bitmap("head.png");
        ALLEGRO_BITMAP* headLeft = al_load_bitmap("headLeft.png");
        ALLEGRO_BITMAP* headUp = al_load_bitmap("headUp.png");
        ALLEGRO_BITMAP* headDown = al_load_bitmap("headDown.png");
        //  if (glava)return 2;
        ALLEGRO_BITMAP* telo = al_load_bitmap("body.png");

        ALLEGRO_FONT* font1 = al_load_font("test.ttf", 15, 0);
        ALLEGRO_FONT* mcfont = al_load_font("test.ttf", 30, 0);
        ALLEGRO_BITMAP* coin1 = al_load_bitmap("coinPic.png");



        ALLEGRO_TIMER* timer = al_create_timer(1.0 / 10);
        ALLEGRO_TIMER* frameTimer = al_create_timer(1.0 / frameFPS);
        ALLEGRO_TIMER* VREME = al_create_timer(1);
        ALLEGRO_KEYBOARD_STATE keyState;

        ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
        al_register_event_source(event_queue, al_get_timer_event_source(VREME));
        al_register_event_source(event_queue, al_get_display_event_source(display));

        al_start_timer(timer);
        al_start_timer(frameTimer);
        al_start_timer(VREME);
        srand(time(NULL));

        const int maxF = 8;
        int curF = 0;
        int frameC = 0;
        int frameD = 2;
        int frameW = 40;
        int frameH = 40;
        int timeS = 0;
        int timeF = 0;

        enum Direction { DOWN, LEFT, RIGHT, UP };

        //bool sdasda;
        int dir = DOWN;
        int score = 1;
        int lastX;
        int lastY;

        int coinX = 40 * (rand() % 20);
        int coinY = 40 * (rand() % 15);

        int snakeT[50];
        for (int i = 0; i < 50; i++) {
            snakeT[i] = 0;
        }
        int snakeX[50], snakeY[50];

        bool menu = false;
        bool dead = false;
        while (!done) {



            lastX = x;
            lastY = y;


            ALLEGRO_EVENT events;
            al_wait_for_event(event_queue, &events);


            if (events.type == ALLEGRO_EVENT_KEY_UP)
            {
                switch (events.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    if (menu) menu = false, score = 1, timeS = 0, x = 0, y = 0;
                    break;
                }
            }
            else if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                done = true;

            if (events.type == ALLEGRO_EVENT_TIMER) {
                if (events.timer.source == VREME) timeS++;
                if (events.timer.source == timer) {

                    al_get_keyboard_state(&keyState);
                    if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && dir != LEFT)
                        dir = RIGHT;
                    else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) && dir != RIGHT)
                        dir = LEFT;
                    else if (al_key_down(&keyState, ALLEGRO_KEY_UP) && dir != DOWN)
                        dir = UP;
                    else if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) && dir != UP)
                        dir = DOWN;
                    else if (al_key_down(&keyState, ALLEGRO_KEY_A))
                        score++;
                    else if (al_key_down(&keyState, ALLEGRO_KEY_ENTER) && menu == true)
                        menu = false, score = 1, timeS = 0, x = 0, y = 0;
                    if (menu == false) {
                        if (score != 0) {
                            for (int i = score; i > 0; i--) {
                                snakeX[i] = snakeX[i - 1];
                                snakeY[i] = snakeY[i - 1];
                            }
                            snakeX[0] = lastX;
                            snakeY[0] = lastY;
                        }
                    }

                    switch (dir) {
                    case RIGHT: x = x + 40;
                        break;
                    case LEFT: x = x - 40;
                        break;
                    case UP: y = y - 40;
                        break;
                    case DOWN: y = y + 40;
                        break;
                    }

                    if (x == coinX && y == coinY) {
                        score++;
                        al_play_sample(MUZ, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        coinX = 40 * (rand() % 20);
                        coinY = 40 * (rand() % 15);
                        snakeT[score] = 1;
                    }

                    if (menu == false) {
                        for (int i = 0; i < score; i++) {
                            if (x == snakeX[i] && y == snakeY[i] && menu == false) dead = true;
                        }
                        if (x < 0 || x >= 800 || y < 0 || y >= 600 && menu == false) dead = true;
                    }

                    draw = true;

                }
            }
            if (++frameC >= frameD) {
                if (++curF >= maxF)
                    curF = 0;

                frameC = 0;
            }

            if (dead && menu == false) {
                menu = true;
                timeF = timeS;
                x = 0, y = 0;
                for (int i = 0; i < 50; i++) {
                    snakeT[i] = 0;
                }
                dead = false;
                dir = DOWN;
            }



            if (draw == true) {
                draw = false;
                if (menu) {
                    x = 0, y = 0;
                    for (int i = 0; i < 50; i++) {
                        snakeT[i] = 0;
                    }
                    al_draw_text(font4, al_map_rgb(255, 255, 255), 20, 100, 0,
                        "Press Enter to Start");
                    al_draw_text(font4, al_map_rgb(255, 255, 255), 100, 200, 0,
                        "Press Esc to Exit");
                    al_draw_textf(font2, al_map_rgb(255, 255, 255), 120, 350, 0,
                        "Coins %i", score - 1);
                    al_draw_textf(font2, al_map_rgb(255, 255, 255), 460, 350, 0,
                        "Time %i sec", timeF);
                }
                else {
                    //   al_draw_bitmap(coin, coinX, coinY, NULL);
                    al_draw_bitmap(coin1, coinX, coinY, 0);
                    for (int i = 0; i < score; i++) {
                        al_draw_bitmap(telo, snakeX[i], snakeY[i], NULL);
                    }

                    switch (dir) {
                    case RIGHT:  al_draw_bitmap(headRight, x-10, y, NULL);
                        break;
                    case LEFT:  al_draw_bitmap(headLeft, x-20, y, NULL);
                        break;
                    case UP:   al_draw_bitmap(headUp, x, y-20, NULL);
                        break;
                    case DOWN:  al_draw_bitmap(headDown, x, y-10, NULL);
                        break;
                    }
                  
                   
                    al_draw_textf(font2, al_map_rgb(255, 255, 255), 5, 5, 0,
                        "Coins: %i", score - 1);
                    al_draw_textf(font2, al_map_rgb(250, 255, 255), 675, 5, 0,
                        "Time: %i", timeS);
                }

                al_flip_display();
                al_clear_to_color(al_map_rgb(0, 0, 0));
            }




        }


        al_destroy_sample(MUZ);
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(event_queue);
        return 0;


        
       
    }
    al_destroy_font(font1);
    al_destroy_font(font2);
	al_destroy_display(display);


	return 0;
}















