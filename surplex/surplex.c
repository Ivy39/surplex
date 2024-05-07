#include <stdio.h>
#include <raylib.h>
#include <raymath.h> 



// key const
int key_speed = 10;



//keys for holder 1
int key_x = 0;
int key_y = 0;
int key_x_cheakpoint = 1500;
int key_y_cheakpoint = 200;
int is_key_was_on_cheackpoint = 0;




int key_to_holder_update()
{
    if(is_key_was_on_cheackpoint==0)
    {
        if (key_x < key_x_cheakpoint) { key_x += key_speed; }
        if (key_x > key_x_cheakpoint) { key_x -= key_speed; }
        if (key_y < key_y_cheakpoint) { key_y += key_speed; }
        if (key_y > key_y_cheakpoint) { key_y -= key_speed; }
    }

    if (key_x == key_x_cheakpoint && key_y == key_y_cheakpoint) { is_key_was_on_cheackpoint = 1; }

    if (is_key_was_on_cheackpoint == 1)
    {
        if (key_x < 930) { key_x += key_speed; }
        if (key_x > 930) { key_x -= key_speed; }
        if (key_y < 800) { key_y += key_speed; }
        if (key_y > 800) { key_y -= key_speed; }
    }
}



//nodeholder

//1
int holder_1_x = 930;
int holder_1_y = 800;
int holder_1_pressed = 0;

//2
int holder_2_x = 820;
int holder_2_y = 800;
int holder_2_pressed = 0;

//3
int holder_3_x = 710;
int holder_3_y = 800;
int holder_3_pressed = 0;

//4
int holder_4_x = 600;
int holder_4_y = 800;
int holder_4_pressed = 0;




//loop
int Draw_and_Colision()
{
    //colision
    Rectangle holder_rect_1 = { holder_1_x,holder_1_y,100,50 };
    Rectangle holder_rect_2 = { holder_2_x,holder_2_y,100,50 };
    Rectangle holder_rect_3 = { holder_3_x,holder_3_y,100,50 };
    Rectangle holder_rect_4 = { holder_4_x,holder_4_y,100,50 };

    //keycolision
    Rectangle key_rect = { key_x,key_y,100,50 };

    //Draw key
    DrawRectangleRec(key_rect, PINK);

    //Draw holder
    if (holder_1_pressed == 0){DrawRectangleRec(holder_rect_1, WHITE);}
    if (holder_1_pressed == 1) { DrawRectangleRec(holder_rect_1, GRAY); }

    if (holder_2_pressed == 0) { DrawRectangleRec(holder_rect_2, WHITE); }
    if (holder_2_pressed == 1) { DrawRectangleRec(holder_rect_2, GRAY); }

    if (holder_3_pressed == 0) { DrawRectangleRec(holder_rect_3, WHITE); }
    if (holder_3_pressed == 1) { DrawRectangleRec(holder_rect_3, GRAY); }

    if (holder_4_pressed == 0) { DrawRectangleRec(holder_rect_4, WHITE); }
    if (holder_4_pressed == 1) { DrawRectangleRec(holder_rect_4, GRAY); }
    return 0;
}
//Key
int Input()
{
    if (IsKeyDown(KEY_K)) { holder_1_pressed = 1; }
    if (IsKeyUp(KEY_K)) { holder_1_pressed = 0; }

    if (IsKeyDown(KEY_J)) { holder_2_pressed = 1; }
    if (IsKeyUp(KEY_J)) { holder_2_pressed = 0; }

    if (IsKeyDown(KEY_F)) { holder_3_pressed = 1; }
    if (IsKeyUp(KEY_F)) { holder_3_pressed = 0; }

    if (IsKeyDown(KEY_D)) { holder_4_pressed = 1; }
    if (IsKeyUp(KEY_D)) { holder_4_pressed = 0; }
    return 0;
}







//main
int main()
{
    
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "surplex");

    SetTargetFPS(30);               
    
    while (!WindowShouldClose())    
    {
       
        Input();
        key_to_holder_update();


        BeginDrawing();
        ClearBackground(BLACK);
        //---------------------------
        Draw_and_Colision();
        //-------------------------
        EndDrawing();
        
    }


    CloseWindow();        
   



	return 0;
}
