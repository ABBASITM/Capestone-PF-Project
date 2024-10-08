// PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
//i22-1013 , Muhammad Mustfa Kamran, CS-K
 


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;
int main(){
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3 , obj4, obj5, obj6, obj7, obj8 ,obj9, obj10;
    
    
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/menu.png");
    obj5.loadFromFile("img/shadow.png");
    obj6.loadFromFile("img/bomb.png");
    obj7.loadFromFile("img/help.png");
    obj8.loadFromFile("img/pause.png");
    obj9.loadFromFile("img/gameover.png");
    obj10.loadFromFile("img/difficulty.png");
        
    
    Sprite sprite(obj1), background(obj2), frame(obj3), menu(obj4), shadow(obj5), bomb(obj6), Help(obj7), Pause(obj8),gameover(obj9), difficulty(obj10);

//---------MUSIC  -----  
    Music music,gamemusic;
    music.openFromFile("music/gamemusic.wav");
    gamemusic.openFromFile("music/audio.wav");
    music.play();
    music.setLoop(true); 
//---------Score------------  
	score=0;
	
	std::ostringstream ssScore;
	ssScore<<"Score:"<< score;
	
	Font font1;
    font1.loadFromFile("arial.ttf");
    Text text;
    text.setFont(font1);
    
    text.setCharacterSize(15);
    text.setFillColor(Color::Black);
    text.setPosition(245,150);
    text.setString(ssScore.str());
      
 //---------VARIABLES----------      
    
    
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3;
    int rotate=0;
    
    float bombtimer=0,bombdelay=1;
    Clock clock;
    
    

 //---------Menu bools------------   
    bool seehigh=0;
    bool help=0;
    bool Space=0;
    bool Difficulty=1;
    
 //======================================================= main menu  =====================================================================	   
    while(start==0) //MENU LOOP WHEN 1 PRESSED LOOPED EXITED TO GAME
    {
    	Event a;	
	    while (window.pollEvent(a))
		{                    //Event is occurring - until the game is in running state
		   
       		    
		    window.draw(menu);
	    	    window.display();
		    if (a.type == Event::Closed)                   
		        {music.pause();
                      				 window.close();}                            
		    if (a.type == Event::KeyPressed)  
		    {            
		         if (a.key.code == Keyboard::Num1)            
                        {start = 1;   
                        Difficulty=0;  } 
                        else if (a.key.code == Keyboard::Num2)            
                        {
                         help = 1;
                        start = 1; 
                        
                        }
                        else if (a.key.code == Keyboard::Num3){            
                         
                        seehigh = 1;
                        start = 1; 
                        
                        }
                        else if (a.key.code == Keyboard::Num4)            
                        {
                        music.pause();
                        window.close();
                        }
    		    }
    		}

     }
     
//======================================================= HELP MENU =====================================================================				 		
				 		
	 
     while(help==1) //IF 2 PRESSED MENU LOOP EXITED AND HELP=1 SO THIS LOOP STARTS
     {
    	Event b;	
	    while (window.pollEvent(b))
		{                    //Event is occurring - until the game is in running state
		    
		    
		    window.draw(Help);
	    	    window.display();
		    if (b.type == Event::Closed)                   
		        {music.pause();
                      				 window.close();}                           
		    if (b.type == Event::KeyPressed)  
		    {            
		         if (b.key.code == Keyboard::Enter)            
                        help = 0;     
                        
                     
    		    }
    		}
     }			 		
	
     
//======================================================= Difficulty menu  =====================================================================	
     while(Difficulty==0) //IF 1 PRESSED MENU LOOP EXITED and THIS STARTS
    {
    	window.clear();
    	Event f;	
	    while (window.pollEvent(f))
		{                    
		    
		    window.draw(difficulty);
	    	    window.display();
		    if (f.type == Event::Closed)                   
		        {music.pause();
                      				 window.close();}                           
		    if (f.type == Event::KeyPressed)  
		    {            
		        if (f.key.code == Keyboard::Num1) 
		        {          
                        difficultylevel=1;     
                        Difficulty=1;
                        }
                        
                        else if (f.key.code == Keyboard::Num2)    
                        {        
                         
                        difficultylevel=2; 
                        Difficulty=1;
                        }
                        else if (f.key.code == Keyboard::Num3){           
                        difficultylevel=3;
                        Difficulty = 1;
                        }
                        
    		    }
    		}
     }

//======================================================= GAME WINDOW OPENS  =====================================================================	
    
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        bombtimer+=time;
        score=time;
       
      

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e))
        {                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed){
                        music.pause();
                        window.close();
                        }                   
            if (e.type == Event::KeyPressed)  
            {            
                if (e.key.code == Keyboard::Up)            
                    rotate += 1;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1     ;                     //Change in X-Axis - Positive
                else if (e.key.code == Keyboard::Space)    //Check if the other key pressed is space key
                    Space=1;  
                else if (e.key.code == Keyboard::B)            
						{
						Bomb=1;
						}                      
//======================================================= Pause menu  ========================================================================
                else if (e.key.code == Keyboard::P)
                {
		       	bool pause=1;
		          while(pause==1)
		          {
	    	          Event c;	
				    while (window.pollEvent(c))
					{                    //Event is occurring - until the game is in running state
					    window.draw(Pause);
				    	    window.display();
					    if (c.type == Event::Closed)                   
						{music.pause();
                      				 window.close();}                            
					    if (c.type == Event::KeyPressed)  
					    {            
						 if (c.key.code == Keyboard::Num1)            
						pause = 0;      
						else if (c.key.code == Keyboard::Num3)            
						{
						seehigh = 1; 
						pause = 1; 
						
						}
						else if (c.key.code == Keyboard::Num2){            
						help = 1; 
						pause=0;
						
						}
						else if (c.key.code == Keyboard::Num4)            
						{
						music.pause();
						window.close();
						}
						else if (c.key.code == Keyboard::P)            
						{
						pause=0;
						}
						
					    }
			    		}
			  }      
               	}
            }
              
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
	
	
	
//------//============================================== GAMEOVER DISPLAY =============================================================
	while(Gameover==1) //if gameover 
				 		{
				 		    Event d;	
						    while (window.pollEvent(d))
						    {                    
							    text.setCharacterSize(20);
       							    text.setFillColor(Color::Black);
                                                            text.setPosition(300,100);
                                                            text.setString(ssScore.str());
							    window.draw(text);
							    window.draw(gameover);
						    	    window.display();
							    if (d.type == Event::Closed)                   
								{music.pause();
                      						  window.close();   }                         
							    if (d.type == Event::KeyPressed)  
							    {            
								 if (d.key.code == Keyboard::Num1)  //if 1 pressed brings back to menu           
								 {
								 	start = 0;
								 	music.pause();
									window.close();
								 }
								
					    		    }
					    	     }
				 		
				 		
				 		
				 		}
//======================================================= HELP MENU =====================================================================				 		
				 		
	 
     while(help==1)
     {
    	Event b;	
	    while (window.pollEvent(b))
		{                    //Event is occurring - until the game is in running state
		    
		    
		    window.draw(Help);
	    	    window.display();
		    if (b.type == Event::Closed)                   
		        {music.pause();
                      				 window.close();}                            
		    if (b.type == Event::KeyPressed)  
		    {            
		         if (b.key.code == Keyboard::Enter)            
                        help = 0;     
                        
                     
    		    }
    		}
     }			 		
				 		
//======================================================= CALLING YOUR FUNCTIONS  =====================================================================	
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
		fallingPiece( timer,  delay, colorNum);       
        
        Linefull( );
        horizontalmove(delta_x);
        Reachtop(); 
		bombfalling( bombtimer,  bombdelay, colorNum);
        Rotationfunction(rotate);
        Shadow(delta_x);
        spacebar(Space);
     
        
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
        
        


//======================================================= WINDOWS/TEXT/SPRITES DRAWINGS  =====================================================================	
        window.clear(Color::Black);
        
        window.draw(background);
        
        
        text.setCharacterSize(15);
        text.setFillColor(Color::Black);
        text.setPosition(245,150);
        text.setString(ssScore.str());
         window.draw(text);
        for (int i=0; i<M; i++)
       
        
        {
            for (int j=0; j<N; j++)
            {
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
                
                
                shadow.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                shadow.setPosition(j*18,i*18);
                shadow.move(28,31); //offset
                window.draw(shadow);
                
                 
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
            
            
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setPosition(shadowpoint_1[i][0]*18,shadowpoint_1[i][1]*18);
            shadow.move(28,31);
            window.draw(shadow);
            
            bomb.setTextureRect(IntRect(bombcolorNum*18,0,18,18));
            bomb.setPosition(bombpoint_1[i][0]*18,bombpoint_1[i][1]*18);
            bomb.move(28,31);
            window.draw(bomb);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    return 0;
}
