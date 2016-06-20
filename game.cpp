/***********************************************************************
 * Source File:
 *    Skeet ++ - main file for this game
 * Author:
 *    Br. Comeau
 * Summary:
 *    This project will impliment the Skeet game outlined in the cs165
 *    textbook.
 ************************************************************************/

#include <cmath>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "movable.h"
#include "drop.h"
#include "bullet.h"

#include "bird.h"
#include "normal.h"
#include "tough.h"
#include "sacred.h"

#define NUMBULLETS 100
#define MAXDROPS 200
#define MAXBIRDS 10

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   // create the game
    Game() : gameOver(false), score(0), survivors(0), type(0),
             temp(0), firstTime(true){}
   
   // handle user input
   void input(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui) const;
   
private:
   
    bool gameOver;
    bool firstTime;
    Rifle rifle;
    int score;
    int survivors;
    int type;
    int temp;
    Bullet bullets[NUMBULLETS];
   
    Drop drops[MAXDROPS];
    
    Bird *bird;
   // TODO - REQUIREMENT for this project!!!!
   //      - you must use/have a pointer to a bird object
   //      - Ie., Bird *bird;

   // TODO: add any objects or variables that are required
};

/***************************************
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if(firstTime)
   {
      bird = new Normal();
      firstTime = false;
   }
    if (bird->getIsDead())
    {
        int wb = random(0, 3);
        switch (wb) {
            case 0:
                bird = new Normal();
                break;
            case 1:
                bird = new Tough();
                break;
            case 2:
                bird = new Sacred();
                break;
            default:
                break;
        }
        
    }
    else
        bird->advance();
    
   // TODO: advance anything that moves
    for (int i = 0; i < NUMBULLETS; i++)
    {
        if(bullets[i].getIsAlive())
            bullets[i].advance();
        if(bullets[i].getX() < -200 || bullets[i].getY() > 200)
            bullets[i].setIsAlive(false);
    }
 
   // TODO: decide if anything died, the game is over, etc...
    if (bird->getX() > 210)
    {
        bird->setDead();
        survivors++;
    }
    
    for (int i = 0; i < MAXDROPS; i++)
    {
        if(drops[i].getY() < -205)
        {
            drops[i].setIsAlive(false);
        }
        else
        {
            drops[i].addGravity();
            drops[i].advance();
        }
    }
    
    for (int i = 0;i < NUMBULLETS;i++)
    {
        if(bullets[i].getIsAlive())
        {
            if ((powf((bullets[i].getX() - bird->getX()), 2) +
                    powf((bullets[i].getY() - bird->getY()), 2)) <
                    powf(20, 2))
            {
                temp = score;
                score += bird->hitBird();
                if(temp != score)
                {
                    
                    temp = 0;
                    for(int j = 0; j < MAXDROPS && temp < 30; j++)
                    {
                        if (!drops[j].getIsAlive())
                        {
                            //std::cout <<"\nThis is Called for drops.";
                            //std::cout <<bird->getX() << " " << bird->getY();
                            drops[j].setX(bird->getX() + random(-15, 15));
                            drops[j].setY(bird->getY() + random(-15, 15));
                            drops[j].setDx(((float)random(-5, 25))/10);
                            drops[j].setDy(((float)random(-15, 20))/10);
                            drops[j].setIsAlive(true);
                            temp++;
                        }
                    }
                }
                bullets[i].setIsAlive(false);
            }
        }
    }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: input(const Interface & ui)
{
   // TODO: handle user input
    if(ui.isSpace())
    {
        switch (type) {
            case 0:
                for (int i = 0; i < NUMBULLETS; i++) {
                    if(!bullets[i].getIsAlive())
                    {
                        bullets[i].setIsAlive(true);
                        bullets[i].fire(rifle.getAngle(), type);
                        break;
                    }
                }
                break;
            case 1:
                for (int i = 0; i < NUMBULLETS; i++) {
                    if(!bullets[i].getIsAlive())
                    {
                        bullets[i].setIsAlive(true);
                        bullets[i].fire(rifle.getAngle(), type);
                    }
                }
                break;
            default:
                break;
        }
        
    }
    if (ui.isUp())
    {
        if(type > 1)
            type = 0;
        else
            type++;
    }
    if (ui.isDown())
    {
        if(type < 0)
            type = 1;
        else
            type--;
    }
    if(type > 1)
        type = 0;
    if(type < 0)
        type = 1;
   // Note that you can discover keys that were pressed by checking
   // methods such as ui.isUp(), ui.isLeft(), etc.
   // see Pong for an example

   // Move the the rifle
   rifle.move(ui.isRight(), ui.isLeft());
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui) const
{
	// display the rifle
   	rifle.draw();
    
    switch (type) {
        case 0:
            drawText(Point(110, -185), "Rifle");
            break;
        case 1:
            drawText(Point(110, -185), "Shotgun");
            break;
        default:
            break;
    }
    
    for(int i = 0; i < NUMBULLETS; i++)
    {
        if (bullets[i].getIsAlive())
            bullets[i].drawType(type);
    }
    
    bird->draw();
    // TODO: draw anything you need to display in the game

    drawNumber(Point(170, 190), survivors);
    if(score >= 0)
        drawNumber(Point(-190, 190), score);
    else
    {
        drawText(Point(-190, 180), "-");
        drawNumber(Point(-180, 190), -(score));
    }
    for(int i = 0; i < MAXDROPS; i++)
    {
        if(drops[i].getIsAlive())
        {
            drops[i].draw();
            //std::cout<<"\n draw is called";
        }
    }
}

#define X_SIZE       400

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *pGame = (Game *)p;
   
   pGame->advance();
   pGame->input(*pUI);
   pGame->draw(*pUI);
}

// set the bounds of the drawing rectangle
float Point::xMin = -(X_SIZE / 2.0);
float Point::xMax =  (X_SIZE / 2.0);
float Point::yMin = -200.0;
float Point::yMax =  200.0;

/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Skeet");
   Game game;
   ui.run(callBack, &game);
   
   return 0;
}
