//============================================================================
// Name        : Tetris.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<fstream>
#include<algorithm>
//#include<cstdlib>
#include<ctime>
#include <string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath>      // for basic math functions such as cos, sin, sqrt
using namespace std;
const int menu=0;
int height=850;
int width=850;
const int gamePlaying=1;
const int gamePause=2;
const int gameEnd=3;
int gameState=menu;
int sideways[3]={210,440,550};
int currentSideway=1;
int myPlayer_x_position=sideways[1];
int myPlayer_y_position=65;
int total_lives=3;
int coins_collected=0;
int score=0;
int distance_covered =0;
int distance_milestone=1000;
int speed=10;
const int obstacle=3;
int obstacle_x_axis[obstacle];
int obstacle_y_axis[obstacle];
bool is_obstacle_present[obstacle];
const int coins=3;
int coins_x_axis[coins];
int coins_y_axis[coins];
bool is_coin_present[coins];
string name="";
int high_score=0;
//screen(35-700)
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
   void Read()
    {
      ifstream file("Laiba.txt");
        if (file.is_open())
                {
             file>>high_score;
             file.close();
                }
    }
  void Write(int score)
    {
      if(score>high_score)
       { high_score=score;}
        cout<<high_score;
        ofstream file("Laiba.txt");
        file<<high_score;
        file.close();
    }
 
void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
 int x5=374,y5=35;
 
void Display(){
    // set the background color using function glClearColotgr.
    // to change the background play with the red, green and blue values below.
    // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

    glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors
    
	
       
    //DrawString( x5, 670, "Here are some are basic shapes", colors[MISTY_ROSE]); // this will print given string at x=50 , y=600
   
   // DrawCircle( 200 , 200 , 50 , colors[5]); // This will draw a circle at x=200,y=200 of radius 50
																		
																		//                    v1( x,y )   v2( x,y )  , v3( x,y ) 
   // DrawTriangle( 300, 50 , 500, 50 , 400 , 250, colors[MISTY_ROSE] );  // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
    
    //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
    
     
    
	

	//DrawCircle(20,20,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	
	if(gameState==menu)
	{DrawString(220,500,"(=^..^=) Laiba Endless Runner Game! (=^..^=)",colors[WHITE]);
	DrawString(270,400,"<<<<<Press Enter to Play>>>>>",colors[WHITE]);
        DrawString(330,450,"Player Name: "+name,colors[DODGER_BLUE]);
        //DrawString(430+(name.length()*15),480,"_",colors[WHITE]);
	}
	else if(gameState==gamePause|| gameState==gamePlaying)
	{  DrawLine( 650, 0 ,  650, 850 , 45 , colors[WHITE] );  //2nd line	
           //DrawLine( 34,35,802,35,40,colors[WHITE]);                    //lower horizontal line
           DrawLine( 200, 0,  200 , 850, 45, colors[WHITE] ); // first line
          
          
        //     ==========1st segmented line=========
            DrawLine( 350, 0,  350 , 50, 45, colors[GRAY] );
            DrawLine( 350, 100,  350 , 150, 45, colors[GRAY] );
            DrawLine( 350, 200,  350 , 250, 45, colors[GRAY] );
            DrawLine( 350, 300,  350 , 350, 45, colors[GRAY] );
            DrawLine( 350, 400,  350 , 450, 45, colors[GRAY] );
            DrawLine( 350, 500,  350 , 550, 45, colors[GRAY] );
            DrawLine( 350, 600,  350 , 650, 45, colors[GRAY] );
            DrawLine( 350, 700,  350 , 750, 45, colors[GRAY] );
            DrawLine( 350, 800,  350 , 850, 45, colors[GRAY] );
            //   ============2nd semened line===========
      //     DrawLine( 500, 0,  500 , 850, 45, colors[GRAY] ); // second segment line
           DrawLine( 500, 0,  500 , 50, 45, colors[GRAY] );
           DrawLine( 500, 100,  500 , 150, 45, colors[GRAY] );
           DrawLine( 500, 200,  500 , 250, 45, colors[GRAY] );
           DrawLine( 500, 300,  500 , 350, 45, colors[GRAY] );
           DrawLine( 500, 400,  500 , 450, 45, colors[GRAY] );
           DrawLine( 500, 500,  500 , 550, 45, colors[GRAY] );
           DrawLine( 500, 600,  500 , 650, 45, colors[GRAY] );
           DrawLine( 500, 700,  500 , 750, 45, colors[GRAY] );
           DrawLine( 500, 800,  500 , 850, 45, colors[GRAY] );
           
           
           
        
	//DrawSquare( x5 , y5 ,100,colors[10]);  //This will draw a square shape of size 100x100  at x=300 and y=300 
	
	// for my player character
	DrawSquare(x5+20,y5,15,colors[WHEAT]);
	DrawSquare(x5+45,y5,15,colors[WHEAT]);
	DrawRoundRect(x5+15,y5+15,50,50,colors[HOT_PINK],10);
	DrawCircle(x5+40,y5+75,18,colors[CHOCOLATE]);
	DrawLine(x5+20,y5+55,x5,y5+35,8,colors[WHEAT]);
	DrawLine(x5+60,y5+55,x5+80,y5+35,8,colors[WHEAT]);
	
	// Things I'll display in game state pause and playing
	DrawString( 670, 755, "Score: "+to_string(score), colors[WHITE]); 
	DrawString( 670, 690, "Lives: "+to_string(total_lives), colors[WHITE]); 
	    if(total_lives==2)
	      {DrawString( 670, 690, "Lives: "+to_string(total_lives), colors[DARK_OLIVE_GREEN]);}
	    if(total_lives==1)
	      {DrawString( 670, 690, "Lives: "+to_string(total_lives), colors[RED]); }
	DrawString( 670, 720, "Coins: "+to_string(coins_collected), colors[WHITE]); 
	DrawString( 670, 610, "Distance: "+to_string(distance_covered), colors[WHITE]); 
	DrawString( 670, 650, "Speed: "+to_string(speed), colors[WHITE]); 
	DrawString( 670, 570, "High Score: "+to_string(high_score), colors[WHITE]); 
	DrawString(670,790,"Name: "+name,colors[WHITE]);
	
	
	   //my computer player
	      if(distance_covered>=2000)
	      {
	      DrawSquare(x5+20,y5-180,15,colors[LIGHT_STEEL_BLUE]);
	      DrawSquare(x5+45,y5-180,15,colors[LIGHT_STEEL_BLUE]);
	      DrawRoundRect(x5+15,y5-165,50,50,colors[NAVY],10);
	      DrawCircle(x5+40,y5-95,18,colors[BURLY_WOOD]);
	      DrawLine(x5+20,y5-115,x5,y5-135,8,colors[LIGHT_STEEL_BLUE]);
	      DrawLine(x5+60,y5-115,x5+80,y5-135,8,colors[LIGHT_STEEL_BLUE]);
	      
	      }
	
	if(gameState==gamePause)
	{DrawString(280,500,"=-=-=Game Paused!=-=-=",colors[WHITE]);
	DrawString(275,450,"<<<<<Press R to resume!>>>>>",colors[WHITE]);
	}
	
	for(int i=0;i<obstacle;i++)
	{
	   if(is_obstacle_present[i]==true)
	    {
	    
	    
	    
	    DrawRoundRect(obstacle_x_axis[i],obstacle_y_axis[i],80,100,colors[RED],15);
	    DrawSquare(obstacle_x_axis[i]+15,obstacle_y_axis[i]+25,50,colors[DARK_RED]);
	    DrawCircle(obstacle_x_axis[i]+15,obstacle_y_axis[i]+5,8,colors[TEAL]);
	    DrawCircle(obstacle_x_axis[i]+65,obstacle_y_axis[i]+5,8,colors[TEAL]);
	    //DrawSquare( obstacle_x_axis[i] , obstacle_y_axis[i] ,100,colors[YELLOW]);
	    
	    }
	}
	for(int i=0;i<coins;i++)
	{
	   if(is_coin_present[i]==true)
	   {
	   DrawCircle(coins_x_axis[i],coins_y_axis[i],10,colors[GOLD]);
	   }
	}
     }
     if(gameState==gameEnd)
	{
	DrawString(280,500,">>>>> GAME OVER! <<<<<",colors[RED]);
	DrawString( 370, 460, "Score: "+to_string(score), colors[WHITE]);
	DrawString( 328, 420, "Coins Collected: "+to_string(coins_collected), colors[WHITE]); 
	DrawString( 295, 380, "Distance Covered: "+to_string(distance_covered)+" m", colors[WHITE]); 
	DrawString( 315, 340, "Highest Score: "+to_string(high_score), colors[ROSY_BROWN]);
	DrawString( 200, 296, "***** PRESS ENTER TO PLAY AGAIN! *****", colors[DARK_OLIVE_GREEN]); 
	}
     
   glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
                if(gameState!=gamePlaying) return;
                

    if (key == GLUT_KEY_LEFT   /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
             {
                x5-=20;
                if(x5<200)
                 {
                 x5=201;
                 }
                 
    } else if (key == GLUT_KEY_RIGHT  /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
    {DrawString( 670, 790, "Score: "+to_string(score), colors[WHITE]); 
                   x5+=20;
                   if(x5>550)
                    {
                    x5=549;
                    }		
    } else if (key == GLUT_KEY_UP) /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/ {
        
    }
    else if (key == GLUT_KEY_DOWN)   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/ {
		
    }
    

    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
     glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC/* Escape key ASCII*/) {
        exit(1); // exit the program when escape key is pressed.
    }
    if(key==13)
     {    
     if(gameState==menu)
       {
         gameState=gamePlaying;
       }
       else if(gameState==gameEnd)
        {
          gameState=gamePlaying;
          total_lives=3;
          score=0;
          currentSideway=1;
          distance_covered =0;
          coins_collected=0;
          myPlayer_x_position=sideways[1];
        }
    }
    if (key == 'R' || key=='r'/* Escape key ASCII*/) 
    {
        //exit(1); // exit the program when escape key is pressed.
    	//aswangle+=90;
    	if(gameState==gamePause)
    	   {
    	   gameState=gamePlaying;
    	   }
    }
    if (key == 'P' || key=='p'/* Escape key ASCII*/) 
    {
        
    	if(gameState==gamePlaying)
    	   {
    	   gameState=gamePause;
    	   }
    }
    //else if (int(key) == 13)
    //{  
	//}
    
    glutPostRedisplay(); 
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer(int m) {

// implement your functionality here
       if(gameState==gamePlaying)
       {
       distance_covered +=50;
       if(distance_covered>= distance_milestone)
       {
       speed+=10;
       distance_milestone+=1000;
       }
       score+=1;
       y5=180;
      // y5+=5;
       //if(y5>800)
       //{
       //y5=0;
       //}
       
       for(int i=0;i<obstacle;i++)
      {
            if(is_obstacle_present[i]==true)
            {
              obstacle_y_axis[i]-=speed;
            }
          
            if(obstacle_y_axis[i]<100 || is_obstacle_present[i]==false)
             {
               is_obstacle_present[i]=true;
               obstacle_y_axis[i]=850+(i*400);
               int myRandom=GetRandInRange(0, 3);
               obstacle_x_axis[i]=sideways[myRandom];
            }
           if(abs(x5-obstacle_x_axis[i])<90 &&abs(y5-obstacle_y_axis[i])<90)
            { 
               total_lives-=1;
               obstacle_y_axis[i]=-200;
               is_obstacle_present[i]=false;
               if(total_lives<=0)
                 {
                   gameState=gameEnd;
                   Write(score);
                 }
            }
        }
        
        for(int i=0;i<coins;i++)
         {
           if(is_coin_present[i]==true)
            {
              coins_y_axis[i]-=speed;
            }
          
            if(coins_y_axis[i]<100 || is_coin_present[i]==false)
             {
               is_coin_present[i]=true;
               coins_y_axis[i]=850+(i*400);
               int myRandom=GetRandInRange(0, 3);
               coins_x_axis[i]=sideways[myRandom];
            }
           if(abs(x5-coins_x_axis[i])<90 &&abs(y5-coins_y_axis[i])<90)
            { 
               coins_collected+=1;
               //cout<<"coins:"<<coins_collected<<endl;
               coins_y_axis[i]=-200;
               is_coin_present[i]=false;
            }
        
         } 
       }
       
       
       
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(1000.0 / FPS, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
     cout<<endl;
     cout<<"Enter your name: ";
     getline(cin, name);
     
    int width = 850, height = 850; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    Read();
    glutInit(&argc, argv); // initialize the graphics library...

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("PF's Game"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer, 0);

// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */

