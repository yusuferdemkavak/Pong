#include <raylib.h>
#include <raymath.h>

// Window Properties
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_CENTER_X WINDOW_WIDTH / 2
#define WINDOW_CENTER_Y WINDOW_HEIGHT / 2

// Playground Properties
#define PLAYGROUND_WIDTH 1280
#define PLAYGROUND_HEIGHT 720
#define PLAYGROUND_CENTER_X PLAYGROUND_WIDTH / 2
#define PLAYGROUND_CENTER_Y PLAYGROUND_HEIGHT / 2
#define PLAYGROUND_POSX (WINDOW_WIDTH - PLAYGROUND_WIDTH) / 2
#define PLAYGROUND_POSY (WINDOW_HEIGHT - PLAYGROUND_HEIGHT) / 2

// Structs
typedef struct
{
    Rectangle transform;
    int VelocityX;
    int VelocityY;
    Color color;
} Object;

// Main Function
int main()
{
    // Start //
    //--------------------------------------------------//
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong: The Game");

    SetTargetFPS(60); // Set FPS: 60

    // Playground Window
    Rectangle Playground;

    Playground.width = PLAYGROUND_WIDTH;
    Playground.height = PLAYGROUND_HEIGHT;
    Playground.x = PLAYGROUND_POSX;
    Playground.y = PLAYGROUND_POSY;

    Rectangle PlaygroundBorder;

    PlaygroundBorder.width = PLAYGROUND_WIDTH + 40;
    PlaygroundBorder.height = PLAYGROUND_HEIGHT + 40;
    PlaygroundBorder.x = PLAYGROUND_POSX - 20;
    PlaygroundBorder.y = PLAYGROUND_POSY - 20;
    
    // Player Starting Data
    Object Player;
    
    Player.transform.width = 20; // Player Width
    Player.transform.height = 100; // Player Height
    Player.transform.x = 20 + PLAYGROUND_POSX; // Player X Position
    Player.transform.y = PLAYGROUND_CENTER_Y - (Player.transform.height / 2) + PLAYGROUND_POSY; // Player Y Position
    Player.color = WHITE; // Player Color
    Player.VelocityX = 0;
    Player.VelocityY = 0;
    
    // CPU Starting Data
    Object CPU;


    CPU.transform.width = 20; // CPU Width
    CPU.transform.height = 100; // CPU Height
    CPU.transform.x = PLAYGROUND_WIDTH - (20 + CPU.transform.width) + PLAYGROUND_POSX; // CPU X Position
    CPU.transform.y = PLAYGROUND_CENTER_Y - (CPU.transform.height / 2) + PLAYGROUND_POSY; // CPU Y Position
    CPU.color = WHITE; // CPU Color
    CPU.VelocityX = 0;
    CPU.VelocityY = 0;

    // Ball Starting Data
    Object Ball;

    Ball.transform.width = 20; // Ball Width
    Ball.transform.height = 20; // Ball Height
    Ball.transform.x = PLAYGROUND_CENTER_X - (Ball.transform.width / 2) + PLAYGROUND_POSX; // Ball X Position
    Ball.transform.y = PLAYGROUND_CENTER_Y - (Ball.transform.height / 2) + PLAYGROUND_POSY; // Ball Y Position
    Ball.color = WHITE; // Ball Color
    Ball.VelocityX = -10;
    Ball.VelocityY = 0;
    //--------------------------------------------------//
    
    // Game Loop //
    //--------------------------------------------------//
    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Environment Set-Up
        ClearBackground(BLACK); // Set Background Color: Black
        DrawRectangleRec(PlaygroundBorder, WHITE); // Draws Playground Border
        DrawRectangleRec(Playground, BLACK); // Draws Playground
        HideCursor(); // Hides Cursor
        
        // Rendering Objects
        DrawRectangleRec(Player.transform, Player.color); // Draws Player
        DrawRectangleRec(CPU.transform, CPU.color); // Draws CPU
        DrawRectangleRec(Ball.transform, Ball.color); // Draws Ball

        // Player Controls
        if (IsKeyPressed(KEY_W))
            Player.VelocityY = -4;
        else if(IsKeyPressed(KEY_S))
            Player.VelocityY = 4;

        // Moving Objects //
        //--------------------//
        // Player Movement
        Player.transform.x += Player.VelocityX;
        Player.transform.y += Player.VelocityY;

        // CPU Movement
        if (Ball.transform.y + (Ball.transform.height / 2) < CPU.transform.y + (CPU.transform.height / 2))
            CPU.VelocityY = -4;
        else if (Ball.transform.y + (Ball.transform.height / 2) > CPU.transform.y + (CPU.transform.height / 2))
            CPU.VelocityY = 4;
        else
            CPU.VelocityY = 0;

        CPU.transform.x += CPU.VelocityX;
        CPU.transform.y += CPU.VelocityY;

        //Ball Movement
        Ball.transform.x += Ball.VelocityX;
        Ball.transform.y += Ball.VelocityY;
        //--------------------//

        // Collision Detection
        //--------------------//
        // Ball Collision
        if (CheckCollisionRecs(Ball.transform, Player.transform))
        {
            Ball.VelocityX *= -1;
            Ball.VelocityY += Player.VelocityY / 2;
        }
        else if (CheckCollisionRecs(Ball.transform, CPU.transform))
        {
            Ball.VelocityX *= -1;
            Ball.VelocityY += CPU.VelocityY / 2;
        }
        else if (Ball.transform.y <= PLAYGROUND_POSY || Ball.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Ball.transform.height)
            Ball.VelocityY *= -1;

        // Player Collision
        if (Player.transform.y <= PLAYGROUND_POSY)
        {
            Player.VelocityY = 0;
            Player.transform.y = PLAYGROUND_POSY;
        }
        else if (Player.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Player.transform.height)
        {
            Player.VelocityY = 0;
            Player.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - Player.transform.height;
        }

        // CPU Collision
        if (CPU.transform.y <= PLAYGROUND_POSY)
        {
            CPU.VelocityY = 0;
            CPU.transform.y = PLAYGROUND_POSY;
        }
        else if (CPU.transform.y >= (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - CPU.transform.height)
        {
            CPU.VelocityY = 0;
            CPU.transform.y = (PLAYGROUND_POSY + PLAYGROUND_HEIGHT) - CPU.transform.height;
        }
        //--------------------//

        EndDrawing();
    }

    CloseWindow();
    //--------------------------------------------------//

    return 0;
}

/* 
    TODO:

    1. Player Movement DONE
    2. Ball Movement
        2.1. Collision Detection DONE
        2.2. Velocity Summing DONE
    3. CPU Movement DONE
    4. Scoring System
    5.  UI and Menu Screens
        5.1. Game Start Menu
            5.1.1 Settings Menu
            5.1.2 Customization Menu
        5.2 Game Over Menu
*/