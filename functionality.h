// PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)







void fallingPiece(float& timer, float& delay,int &colorNum )
{
    if (timer>delay)
    {
        for (int i=0;i<4;i++)
        {
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1]; 
            point_1[i][1]+=difficultylevel; //controls the speed of the falling ball more speed is harder level  
        
        }
        if (!anamoly())
        {
            int n=rand()% 7;				
            for (int i=0;i<4;i++)
            {
            gameGrid[point_2[i][1]][point_2[i][0]]=colorNum; 
            }
           colorNum=1+rand()%7;
            	int randomxpostion=1+rand()%8; 	//gives the regenarated block a random xpostion
                for (int i=0;i<4;i++)
                {
                    point_1[i][0] = (BLOCKS[n][i] % 2)+randomxpostion;  
                    point_1[i][1] = BLOCKS[n][i] / 2;	
                }
            
        }
        timer=0;
        delay=0.3;
    }
}


/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///





//========================================================================= BOMB FUNCTION =====================================================================//	
void bombfalling(float& bombtimer, float& bombdelay,int &colorNum)
{
	
	
    if ((bombtimer>bombdelay)&&Bomb)
    {
    	
				for (int i=0;i<4;i++) //bomb falling 
				{   
					bombpoint_2[i][0]=bombpoint_1[i][0]; 
					bombpoint_2[i][1]=bombpoint_1[i][1]; 
					bombpoint_1[i][1]++;	
				}
				
				int downsurface=0, touchblock=0;    //conditions if that were true bomb must be regenerated 
				
				if ((bombpoint_1[0][1]>=20))	//block touches down surface 
				downsurface=1;
				
				else if (  gameGrid[ bombpoint_1[0][1] ][ bombpoint_1[0][0] ] !=0 )
				touchblock=1;
				
				if (downsurface) 
				{
						//block of different colour is generated from a random xcordinate of top row
							
							bombcolorNum=1+rand()%7; //declared in utils
							int randomxcordinate=1+rand()%9;
							for (int i=0;i<4;i++)			//bomb regenerated to origin 
							{
								bombpoint_1[i][0] = randomxcordinate;
								bombpoint_1[i][1] = 0;
							}
							Bomb=0;

				}
					
					else if (touchblock)
					{
							
							if(bombcolorNum==gameGrid[ bombpoint_1[0][1] ][ bombpoint_1[0][0]]) //if colour of bomb same 
								{
									for(int i=0;i<20;i++)
									{
										for(int j=0;j<10;j++)
										{	
											gameGrid[i][j]=0;		//all blocks destroyed 
										}
									}
								
								}
					
							else if(bombcolorNum!=gameGrid[ bombpoint_1[0][1] ][ bombpoint_1[0][0] ])//if different color 
							{
									int blockdeleted=0;
									
									gameGrid[ bombpoint_1[0][1] ][ bombpoint_1[0][0] ]=0;
									blockdeleted+=1;
									
									if(blockdeleted<4)
									{
										/*//coloumn deletion
										for(int j=0;j<=4;j++)
										{
											if((gameGrid[ bombpoint_1[0][1] +j][ bombpoint_1[0][0] ])&&bombpoint_1[1][1]+j<20&&bombpoint_1[0][1]+j<10)
											{
											if ( blockdeleted==4 ) break;
											gameGrid[ bombpoint_1[0][1] +j ][ bombpoint_1[0][0] ]=0;
											blockdeleted++;
											}
										}*/
										
									}
									//rows deletion
									if(blockdeleted<4)
									{
										for(int j=0;j<=4;j++)
										{
										
											//row of impact of bomb 
											if(gameGrid[ bombpoint_1[0][1] ][ bombpoint_1[0][0] +j])
											{
											if ( blockdeleted==4 ) break;
											gameGrid[ bombpoint_1[0][1]  ][ bombpoint_1[0][0] +j]=0;
											blockdeleted++;
											}
											if(gameGrid[ bombpoint_1[0][1] ][ bombpoint_1[0][0] -j])
											{
											if ( blockdeleted==4 ) break;
											gameGrid[ bombpoint_1[0][1]  ][ bombpoint_1[0][0] -j]=0;
											blockdeleted++;
											}
											
										
											//one row beneath impact 
											if(bombpoint_1[0][1]<18)
											{
												if(gameGrid[ bombpoint_1[0][1] +1 ][ bombpoint_1[0][0] +j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1] +1 ][ bombpoint_1[0][0] +j]=0;
												blockdeleted++;
												}
												if(gameGrid[ bombpoint_1[0][1] +1][ bombpoint_1[0][0] -j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1] +1 ][ bombpoint_1[0][0] -j]=0;
												blockdeleted++;
												}
											}
											
											//two row beneath impact 
											if(bombpoint_1[0][1]<17)
											{
												if(gameGrid[ bombpoint_1[0][1]  +2][ bombpoint_1[0][0] +j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1]  +2][ bombpoint_1[0][0] +j]=0;
												blockdeleted++;
												}
												if(gameGrid[ bombpoint_1[0][1] +2][ bombpoint_1[0][0] -j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1]  +2][ bombpoint_1[0][0] -j]=0;
												blockdeleted++;
												}
											}
											
											//three row beneath impact 
											if(bombpoint_1[0][1]<16)
											{
												if(gameGrid[ bombpoint_1[0][1]  +3][ bombpoint_1[0][0] +j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1]  +3][ bombpoint_1[0][0] +j]=0;
												blockdeleted++;
												}
												if(gameGrid[ bombpoint_1[0][1] +3][ bombpoint_1[0][0] -j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1]  +3][ bombpoint_1[0][0] -j]=0;
												blockdeleted++;
												}
											}
											
											
											//4 row beneath impact 
											if(bombpoint_1[0][1]<15)
											{
												if(gameGrid[ bombpoint_1[0][1]  +4][ bombpoint_1[0][0] +j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1]  +4][ bombpoint_1[0][0] +j]=0;
												blockdeleted++;
												}
												if(gameGrid[ bombpoint_1[0][1] +4][ bombpoint_1[0][0] -j])
												{
												if ( blockdeleted==4 ) break;
												gameGrid[ bombpoint_1[0][1]  +4][ bombpoint_1[0][0] -j]=0;
												blockdeleted++;
												}
											}
											
											
											
										
											
										}
									}
									
									
										
									
							}
											  //block of different colour is generated from a random xcordinate of top row
						bombcolorNum=1+rand()%7;		 //declared in utils gives block a random color 
						int randomxcordinate=1+rand()%9;
						for (int i=0;i<4;i++)			
						{
						    bombpoint_1[i][0] = randomxcordinate;
						    bombpoint_1[i][1] = 0;		//bomb regenerated to origin 
						}
						Bomb=0;
					}
				
		    		 bombtimer=0;
		   		 bombdelay=0.3;
      }
}



//========================================================================= SPACEBAR FUNCTION =====================================================================//


void spacebar(bool& Space)
{
	if (Space)
	{
	    for (int i=0;i<4;i++) 
		{
			
		    int uncolouredrow; //saves value of the lowest row that is not coloured 
		    for (int j=0;j<20;j++) //Loops finds uncoloured row starting from bottom to top
			{
				if(gameGrid[j][ point_1[0][0] ]==0 && (gameGrid[j][ point_1[1][0] ]==0) && (gameGrid[j][ point_1[2][0] ]==0) && (gameGrid[j][ point_1[3][0] ]==0))uncolouredrow=j;
			}
		    
		
			int lowesty; //saves y value of the block that is lowest 
			for (int j=0;j<4;j++) //loops finds lowest value of ycordinate
			{
				if(point_1[j][1]>lowesty)lowesty=point_1[j][1];
			}
			int movedownby=0;//saves value to tranform to lowest possible row
			movedownby=uncolouredrow-lowesty;
			
			
			
			for (int j=0;j<4;j++) //moves every shadow block to lowest row
			{
				point_1[j][1]=point_1[j][1]+movedownby;
			}	
			
		}
		
		Space=0; 			//resets the bool value back to zero
		
	}

}





void Shadow(int &delta_x)
	{ 

		for (int i=0;i<4;i++) 
		{
			
		    shadowpoint_1[i][0]=point_1[i][0]; //XAXIS OF SHDAOW IS SAME AS THE AXIS OF FALLING BLOCK
		    int uncolouredrow;
		    for (int j=0;j<20;j++) //Loops finds lowest uncoloured row starting from bottom to top
			{
				if(gameGrid[j][ point_1[0][0] ]==0 && (gameGrid[j][ point_1[1][0] ]==0) && (gameGrid[j][ point_1[2][0] ]==0) && (gameGrid[j][ point_1[3][0] ]==0))uncolouredrow=j; 
			}
		    
		    
		    
				
		
		
			int lowesty=0;
			for (int j=0;j<4;j++) //loops finds lowest value of ycordinate
			{
				if(point_1[j][1]>lowesty)lowesty=point_1[j][1];
			}
			int movedownby=0;
			movedownby=uncolouredrow-lowesty;			//moves falling piece to  last uncolored row
			for (int j=0;j<4;j++) //moves every shadow block to lowest row
			{
				shadowpoint_1[j][1]=point_1[j][1]+movedownby;
			}	
			
		}

	   
		
		
		
	}






//========================================================================= ROTATION FUNCTION =====================================================================//


void Rotationfunction(int& rotate)
{
		
	int point_3[4][2];	
			switch(rotate)
			{
				case 1:
					int tempx,tempy;	//stores the y x value so it can be added by after rotation
					for(int i=0;i<4;i++)
					{
						
						
						tempx=point_1[0][0];
						tempy=point_1[0][1];
						
						point_1[i][0]-=tempx;  //this makes the first iteration block act as origin with cordinates(0,0)
						point_1[i][1]-=tempy;
						
						point_3[i][0]=point_1[i][0]; // exchange of x,y cordinates 
						point_1[i][0]=point_1[i][1]; 
						point_1[i][1]= - point_3[i][0];//point 3 temporaory holds xcords
						
						point_1[i][0]+=tempx	;	//adds back the cordinate so first blocks cordinates no longer 0,0
						point_1[i][1]+=tempy;
						
						point_2[i][0]=point_1[i][0]; 
		      	        point_2[i][1]=point_1[i][1]; 
						

						
					}
					rotate+=1; //PREVENTS INFINTIE TRIGGERING
					
					break;
					
				case 3: //when up is pressed rotate goes from 2 to 3
				
					for(int i=0;i<4;i++)
					{
						
						tempx=point_1[0][0];
						tempy=point_1[0][1];
						
						point_1[i][0]-=tempx;  //this makes the first iteration block act as origin with cordinates(0,0)
						point_1[i][1]-=tempy;
						
						point_3[i][0]=point_1[i][0]; // exchange of x,y cordinates 
						point_1[i][0]= 	 point_1[i][1]; 
						point_1[i][1]= - point_3[i][0];//point 3 temporaory holds xcords
						
						point_1[i][0]+=tempx	;	//adds back the cordinate so first blocks cordinates no longer 0,0
						point_1[i][1]+=tempy;
						
						point_2[i][0]=point_1[i][0]; 
		      	        point_2[i][1]=point_1[i][1]; 
						
					}
					rotate+=1; //PREVENTS INFINTIE TRIGGERING
					break;
					
				case 5: 
				
					for(int i=0;i<4;i++)
					{
						
						tempx=point_1[0][0];
						tempy=point_1[0][1];
						
						point_1[i][0]-=tempx;  //this makes the first iteration block act as origin with cordinates(0,0)
						point_1[i][1]-=tempy;
						
						point_3[i][0]=point_1[i][0]; // exchange of x,y cordinates 
						point_1[i][0]=point_1[i][1]; 
						point_1[i][1]= - point_3[i][0];//point 3 temporaory holds xcords
						
						point_1[i][0]+=tempx	;	//adds back the cordinate so first blocks cordinates no longer 0,0
						point_1[i][1]+=tempy;
						
						point_2[i][0]=point_1[i][0]; 
		      	        point_2[i][1]=point_1[i][1]; 

					}
					rotate+=1; //PREVENTS INFINTIE TRIGGERING
					break;
					
				case 7 :
				
					for(int i=0;i<4;i++)
					{
						tempx=point_1[0][0];
						tempy=point_1[0][1];
						
						point_1[i][0]-=tempx;  //this makes the first iteration block act as origin with cordinates(0,0)
						point_1[i][1]-=tempy;
						
						point_3[i][0]=point_1[i][0]; // exchange of x,y cordinates 
						point_1[i][0]=point_1[i][1]; 
						point_1[i][1]=-  point_3[i][0];//point 3 temporaory holds xcords
						
						point_1[i][0]+=tempx	;	//adds back the cordinate so first blocks cordinates no longer 0,0
						point_1[i][1]+=tempy;
						
						point_2[i][0]=point_1[i][0]; 
		      	        point_2[i][1]=point_1[i][1]; 
					}
					rotate=0; //back to original position so made back to 0
					break;     
					
			
			
			}
        


}


//========================================================================= HORIZONTAL MOVEMENT FUNCTION =====================================================================//

void horizontalmove(int &delta_x)

{
		//======================================= left right boundary 
		
		
		int rbound=0,lbound=0;  //variable if true will be assigned value one 
		for (int i=0;i<4;i++)
		{
			if (point_1[i][0]<0+1)  //block touches left wall lbound variable will be true 
			 	{
			 		lbound=1;
			 	}
			 	 else if(point_1[i][0]>=N-1) rbound=1;       //block touches right wall lboundvariable will be true 
		}
		//=======================================
		
		for (int i=0;i<4;i++)
		{
				if(lbound==1)  
				{
					if(delta_x==-1)delta_x=0; //if left key pressed block doesnt move left
					else if(delta_x==+1) 		//but block still moves right
					{
					point_2[i][0]=point_1[i][0];
					point_2[i][1]=point_1[i][1];
				   	 point_1[i][0]+=delta_x;  
					}
				}
				else if (rbound==1)  
				{
					if(delta_x==+1)delta_x=0; //if left key pressed block doesnt move right
					else if(delta_x==-1) 		//but block still moves left
					{
					point_2[i][0]=point_1[i][0];
					point_2[i][1]=point_1[i][1];
				   	 point_1[i][0]+=delta_x;  
					}
				}
			  else //if block hasnt touch left or right boundary than normal horizontal movement.
			  {  
			  	point_2[i][0]=point_1[i][0];
			    point_2[i][1]=point_1[i][1];
			   	 point_1[i][0]+=delta_x;             //updates the position of point i array that stores the xpostion of 4 blocks
			  }
		}
	delta_x=0; //resets it back to zero 

		if (!anamoly())
		{
		    int n=rand()%7;
		        for (int i=0;i<4;i++)
		        {
		            point_1[i][0] = BLOCKS[n][i] % 2;
		            point_1[i][1] = BLOCKS[n][i] / 2;
		        }
		}
}




//========================================================================= LINE DELETION FUNCTION =====================================================================//


void Linefull()  //This function checks if a row is full,if it is deleted and all the colors filled on blocks above the row are brought one down
{

		int linefull=0;
		
			for(int i=0;i<20;i++)//loop checks every row, if all coloumn of a row is zero
			
			{
				
				 			
				//if 3 rows full together	
				 if	(( (gameGrid[i][0]!=0) && (gameGrid[i][1]!=0) && (gameGrid[i][2]!=0) && (gameGrid[i][3]!=0) && (gameGrid[i][4]!=0) && (gameGrid[i][5]!=0) && (gameGrid[i][6]!=0) && (gameGrid[i][6]!=0) && (gameGrid[i][7]!=0) && (gameGrid[i][8]!=0) && (gameGrid[i][9]!=0)  ) && 
				 ( (gameGrid[i+1][0]!=0) && (gameGrid[i+1][1]!=0) && (gameGrid[i+1][2]!=0) && (gameGrid[i+1][3]!=0) && (gameGrid[i+1][4]!=0) && (gameGrid[i+1][5]!=0) && (gameGrid[i+1][6]!=0) && (gameGrid[i+1][6]!=0) && (gameGrid[i+1][7]!=0) && (gameGrid[i+1][8]!=0) && (gameGrid[i+1][9]!=0)  ) &&
				  ( (gameGrid[i-1][0]!=0) && (gameGrid[i-1][1]!=0) && (gameGrid[i-1][2]!=0) && (gameGrid[i-1][3]!=0) && (gameGrid[i-1][4]!=0) && (gameGrid[i-1][5]!=0) && (gameGrid[i-1][6]!=0) && (gameGrid[i-1][6]!=0) && (gameGrid[i-1][7]!=0) && (gameGrid[i-1][8]!=0) && (gameGrid[i-1][9]!=0)  ) )
				  
				{
				 
					linefull=i; //if a line is full this int stores value of the row that is full
					  
					score+=30; 
						
					for(int j=0;j<10;j++)//row deletion .........each coloumn(j ) of the row i is reset to zero
					{
							gameGrid[linefull][j]=0; //full row deleted 
							score+=10;
							for(int k=0;k<( linefull );k++)
							{
								gameGrid[linefull-k][j]=gameGrid[linefull-k-1][j]; //every row assigns its value to the row below it to fill the deleted space 
								
							}
					}
					
				}
				
				
				//if 2 rows full together 			
					
				 if	(( (gameGrid[i][0]!=0) && (gameGrid[i][1]!=0) && (gameGrid[i][2]!=0) && (gameGrid[i][3]!=0) && (gameGrid[i][4]!=0) && (gameGrid[i][5]!=0) && (gameGrid[i][6]!=0) && (gameGrid[i][6]!=0) && (gameGrid[i][7]!=0) && (gameGrid[i][8]!=0) && (gameGrid[i][9]!=0)  ) && 
				 ( (gameGrid[i+1][0]!=0) && (gameGrid[i+1][1]!=0) && (gameGrid[i+1][2]!=0) && (gameGrid[i+1][3]!=0)   ) )
				  
				{
				 
					linefull=i; //if a line is full this int stores value of the row that is full
					  
					score+=20;
						
					for(int j=0;j<10;j++)//row deletion .........each coloumn(j ) of the row i is reset to zero
					{
							gameGrid[linefull][j]=0; //full row deleted 
							score+=10;
							for(int k=0;k<( linefull );k++)
							{
								gameGrid[linefull-k][j]=gameGrid[linefull-k-1][j]; //every row assigns its value to the row below it to fill the deleted space 
							}
					}
				}
			
				else if	( (gameGrid[i][0]!=0) && (gameGrid[i][1]!=0) && (gameGrid[i][2]!=0) && (gameGrid[i][3]!=0) && (gameGrid[i][4]!=0) && (gameGrid[i][5]!=0) && (gameGrid[i][6]!=0) && (gameGrid[i][6]!=0) && (gameGrid[i][7]!=0) && (gameGrid[i][8]!=0) && (gameGrid[i][9]!=0)  )
				{
				 
					linefull=i; //if a line is full this int stores value of the row that is full
					  
					score+=10;
						
					for(int j=0;j<10;j++)//row deletion .........each coloumn(j ) of the row i is reset to zero
					{
							gameGrid[linefull][j]=0; //full row deleted 
							score+=10;
							for(int k=0;k<( linefull );k++)
							{
								gameGrid[linefull-k][j]=gameGrid[linefull-k-1][j]; //every row assigns its value to the row below it to fill the deleted space 	
							}
					}
				}
		       }		
}
				







//========================================================================= GAMEOVER FUNCTION =====================================================================//

void Reachtop()  
	{
		int reachedtop=0;
		
		
		if	( (gameGrid[1][0]!=0) || (gameGrid[1][1]!=0) || (gameGrid[1][2]!=0) || (gameGrid[1][3]!=0) || (gameGrid[1][4]!=0) || (gameGrid[1][5]!=0) || (gameGrid[1][6]!=0) || (gameGrid[1][6]!=0) || (gameGrid[1][7]!=0) || (gameGrid[1][8]!=0) || (gameGrid[1][9]!=0)  ) reachedtop=1; //if top row of game is coloured meaning it reached reachtop variavle true  
			 		
		if( reachedtop==1 ) 
		{
			
			for(int j=0;j<20;j++)
			{	
				 	for(int k=0;k<10;k++)
					{	
					
						
				 		gameGrid[j][k]=0;//sets all game grid to zero
						Gameover=1;	//bool that causes while loop in intmain to start causing gameover menu to popup
					}				
			}
		}	
	}






///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
