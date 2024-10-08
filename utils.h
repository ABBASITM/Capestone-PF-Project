// PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)





//---Title: PF-Project, Fall-2022 for BS(CS)---//
const char title[] = "PF-Project, Fall-2022";

//---Height and Width of the Actual Interactive Game---//
const int M = 20;   //Number of rows for a piece to cover on the screen (not the entire screen) = 20
const int N = 10;   //Number of columns for a piece to cover on the screen (not the entire screen) = 10

//---The Actual Interactive Game Grid - Built Over (MxN)---//
int gameGrid[M][N] = {0};

//---To Hold the Coordinates of the Piece---//
int point_1[4][2], point_2[4][2];




//---TTo Hold the Coordinates of the Shadow---//
int shadowpoint_1[4][2], shadowpoint_2[4][2];
int bombpoint_1[4][2]={0}, bombpoint_2[4][2]={0};
int n2; //saves the random block value for shdadow block 








//---Check Uncertain Conditions---//
bool anamoly(){  //makes sure block inside the premisises of the game if not it returns true 
    for (int i=0;i<4;i++)
        if (/*point_1[i][0]<0 || //block touches left wall
         point_1[i][0]>=N ||*/  //block touches right wall
          point_1[i][1]>=M)	//block touches down surface
            return 0;
        else if (gameGrid[point_1[i][1]][point_1[i][0]])
            return 0;
    return 1;	
};


//---Functions wasnt letting me pass more arguements into it so had to declar it as globle---//
int bombcolorNum=5;
int score=0;
bool Gameover=0;
bool start=0; 
bool Bomb=0;
int difficultylevel=1;
          
