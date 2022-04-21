#include "raylib.h"
int main()
{
    int length{1440}; // pencere boyutları
    int width{810};
    InitWindow(length, width, "Yasin'nin Penceresi");

    int circle_x{50}; // daire koordinatları
    int circle_y{405};
    int circle_r = 50;

    int axe_x{720}; // balta koordinatları
    int axe_y{0};
    int axe_length{75};
    int axe_width{75};

    int direction{15}; // hareket yönü

    int r_circle_x{circle_x + circle_r}; // dairenin sınırları
    int l_circle_x{circle_x - circle_r};
    int u_circle_y{circle_y - circle_r};
    int b_circle_y{circle_y + circle_r};

    int l_axe_x{axe_x}; // baltanın sınırları
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_width};

    bool collision_with_axe =
        (b_axe_y >= u_circle_y) &&
        (u_axe_y <= b_circle_y) &&
        (r_axe_x >= l_circle_x) &&
        (l_axe_x <= l_circle_x);

    SetTargetFPS(60); // tuşlara bastığımızda dairenin hareketini sınırlamak için kullanırız.

    while (WindowShouldClose() == false) // WindowShouldClose() esc veya kapatma tuşuna bastığımızda true döndürür ve programı kapatır.
    {

        BeginDrawing();
        ClearBackground(WHITE); // Çizilen kareler üst üste bindiğinde flickering olmaması için ClearBackground() fonksiyonunu kullanırız.

        if (collision_with_axe)
        {
            DrawText("Game Over!", 720, 405, 20, RED);
        }
        else
        {
            // oyun mantığı burada başlıyor

            r_circle_x = circle_x + circle_r; // dairenin sınırları güncelleniyor
            l_circle_x = circle_x - circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y + circle_r;

            l_axe_x = axe_x; // baltanın sınırları güncelleniyor
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_width;

            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_width, RED);

            axe_y += direction; // baltayı hareket ettir
            if (axe_y + axe_width > width || axe_y < 0)
            {
                direction *= -1;
            }

            if (IsKeyDown(KEY_D) && circle_x + circle_r < length)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x - circle_r > 0)
            {
                circle_x -= 10;
            }

            // oyun mantığı burada bitiyor
        }

        EndDrawing();
    }
}