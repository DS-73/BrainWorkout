//               Brain Workout
//    Description -  Brain workout is a mind game based on user's pattern finding ability and persistent memory power.            
//                   
//    How to play -
//      It is a number game which include random generated numbers on screen. Now, the user has to remember the numbers displayed on the screen 
//      quickly memorise it, after a span of 3 seconds user has to write the same number displayed on the screen. 
//           For every correct answers 10 points are rewarded.
//     Rules-
//      1. Only 3 lives will be provided to the user to play the game.
//      2. High scorer wins.
//
//      Features to expected soon
//         - Multiplayer support
//         - Different themes
//         - Different ranks on the basis of score
//         - Leaderboard Support
//         - Real time
//  
//      Changelogs-
//            v0.0.1
//              - Compile successfully
//
//
//       


#include<stdio.h>
#include<stdlib.h>       
#include<conio.h>
#include<windows.h>
#include<time.h>


int life=3,points=0,mode,a=0;


// Menu 4 to input from user after the random number is displayed
int menu4(){

    int res;
    char level[10],num[10];

    if(mode==1){
        strcpy(level,"Easy");
        strcpy(num,"****");
    }
    else if(mode==2){
        strcpy(level,"Medium");
        strcpy(num,"******");
    } 
    else{
        strcpy(level,"Hard");
        strcpy(num,"********");
    }
        system("cls");
        printf(" \n\n\t\t                                    ---  Brain Workout  ---                             ");
        printf("\n\n\t\t          ________________________________________________________________________       ");																		
        printf("\n\n\t\t                Lives - %d                               Points - %d         ",life,points);  			           	  	       	
        printf("\n\t\t                Mode - %s                                                            ",level);	           	
        printf("\n\n\t\t                                                                                         ");
        printf("\n\t\t                  Your Number is - %s                                                  ",num);
        printf("\n\n\n\t\t                ************************************************************           ");
        printf("\n\n\t\t                                                            	- Credit D.S.            "); 
        printf("\n\n\t\t            Exit - 0                                                                     "); 
        printf("\n\t\t                                                                                           ");
        printf("\n\t\t           _________________________________________________________________________       ");
        printf("\n\n\t\t          User Input - ");		
    scanf("%d",&res);
    if(res==0){
        life=0;
    }

    return(res);	                              

}

// Menu 3 displays the random generated number
void menu3(int num){
    system("cls");
    char level[10];

    if(mode==1){
        strcpy(level,"Easy");
    }
    else if(mode==2){
        strcpy(level,"Medium");
    } 
    else{
        strcpy(level,"Hard");
    }
    for(int i=3; i>0; i--){
        system("cls");
        printf(" \n\n\t\t                                    ---  Brain Workout  ---                             ");
        printf("\n\n\t\t          ________________________________________________________________________       ");
        printf("\n\n\t\t                Lives - %d                               Points - %d         ",life,points);
        printf("\n\t\t                Mode - %s                                Time -%d Sec              ",level,i);
        printf("\n\n\t\t                                                                                         ");
        printf("\n\t\t                  Your Number is - %d                                                  ",num);
        printf("\n\n\n\t\t                ************************************************************           ");
        printf("\n\n\t\t                                                            	- Credit D.S.            ");
        printf("\n\n\t\t                                                                                         ");
        printf("\n\t\t           _________________________________________________________________________       ");
        printf("\n");				  
        Sleep(1000);                               
    }
    int res=menu4();
    if(res==num){
        points+=10;
        printf("\n\n\t\t           Correct Answer -> +10 points");
        Sleep(2000);
    }
    else if(res==0){
       Sleep(1000); 
    }
    else{
        life-=1;
        printf("\n\n\t\t            Wrong Answer -> -1 Lives");
        Sleep(2000);
    }


}

// Function to generate random numbers required for the game
void generator(int a){

    srand((unsigned)time(0)); 
    static unsigned int num;
    if(a==1){
        num=(unsigned)(rand()%9001)+1000;
        mode=1;
    }
    else if(a==2){
        num=(unsigned)(rand()%900001)+100000;
        mode=2;
    }
    else if(a==3){
        num=(unsigned)(rand()%90000001)+10000000;
        mode=3;
    }
    
    menu3(num);
}

// Result Windows that display information after the game is over
void menu_return(){
    system("cls");
    printf(" \n\n\t\t                                    ---  Brain Workout  ---                             ");
    printf("\n\n\t\t          ________________________________________________________________________       ");
    printf("\n\n\t\t                Congratulations !! On completing the game                                ");
    printf("\n\t\t                                                                                           ");
    printf("\n\n\t\t                Points -> %d                                                      ",points);
    printf("\n\t\t                                                                                           ");
    printf("\n\t\t                                                                                           ");
    printf("\n\n\t\t                ************************************************************             ");
    printf("\n\n\t\t                                                            	- Credit D.S.            ");
    printf("\n\n\t\t                                                                                         ");
    printf("\n\t\t           _________________________________________________________________________       ");				  
    Sleep(1000);
    printf("\n\n\t\t           Press Any key to return       ");
    getch();
    system("cls"); 
    life=3;
    points=0;

}

// Function to check remaining lifes
void lives(int a){
    
    if(life==0){
        return;
    }
    generator(a);
    lives(a);

}

// Menu 2 to set difficulty level of the game
void menu2(){
    system("cls");
    int choice;
    do{
        printf(" \n\n\t\t                                    ---  Brain Workout  ---                       ");
        printf("\n\n\t\t          ________________________________________________________________________ ");
        printf("\n\n\t\t                ************************************************************       ");																		
        printf("\n\n\t\t                          1. Easy                                                  ");  			           	  	       	
        printf("\n\t\t                          2. Medium                                                  ");	           	
        printf("\n\t\t                          3. Hard                                                    ");
        printf("\n\n\t\t                ************************************************************       ");
        printf("\n\n\t\t                                                            	- Credit D.S.      ");  
        printf("\n\n\t\t                 Back - 0                                                          ");
        printf("\n\t\t           _________________________________________________________________________ ");				  
        printf("\n\n\t\t          User Input - ");	
        scanf("%d",&choice);

        switch(choice){
            case 0:   return;
                      break;
            case 1:   a=1;
                      lives(a);
                      break;
            case 2:   a=2;
                      lives(a);
                      break;
            case 3:   a=3;
                      lives(a);
                      break;
            default:
                    printf("\n\n\t\t           W");
                    Sleep(200);
                    printf("R");
                    Sleep(200);
                    printf("O");
                    Sleep(200);
                    printf("N");
                    Sleep(200);
                    printf("G");
                    Sleep(200);
                    printf(" ");
                    Sleep(200);
                    printf("I");
                    Sleep(200);
                    printf("N");
                    Sleep(200);
                    printf("P");
                    Sleep(200);
                    printf("U");
                    Sleep(200);
                    printf("T");
                    Sleep(200);
                    break;
        }
           menu_return();
    
    }
    while(choice!=0);
    menu_return();
}

// How to play information is here
void how_t(){
    system("cls");
  
    printf("\n\n\t                                           ---  BrainWorkout  ---                                ");
    printf("\n\n\t          ____________________________________________________________________________________   ");
    printf("\n\n\t                                               How to play ?                                     ");		
    printf("\n\n\t                                  *************************************                          ");																
    printf("\n\n\t                 It is a number game which include random generated numbers on screen.           ");  			           	 	       	
    printf("\n\t                 Now, the user has to remember the numbers displayed on the screen                 ");	           	
    printf("\n\t                 quickly memorise it, after a span of 3 seconds user has to write                  ");	           	
    printf("\n\t                 the same number displayed on the screen.                                          ");	           	
    printf("\n\n\t                     Rules -                                                                     ");	           	
    printf("\n\t                 1. Only 3 lives will be provided to the user to play the game.                    ");	           	
    printf("\n\t                 2. High scorer wins.                                                              ");
    printf("\n\n\t                                  *************************************                          ");		
    printf("\n\n\t                                                                    	    - Credit D.S.        ");  
    printf("\n\n\t          ____________________________________________________________________________________   ");
    printf("\n");

    getch();
    system("cls");

}

// About Section information is here
void about(){
    system("cls");
  
    printf("\n\n\t\t                                           ---  BrainWorkout  ---                                ");
    printf("\n\n\t\t          ____________________________________________________________________________________   ");
    printf("\n\n\t\t                                               About US                                          ");		
    printf("\n\n\t\t                                  *************************************                          ");																
    printf("\n\n\t\t                                                                                                 ");  			           	 	       	
    printf("\n\t\t                 We are always ready for a challange and currently acceptng any kind               ");	           	
    printf("\n\t\t                 of challange that you are willing to give us. At team BrainWorkout                ");	           	
    printf("\n\t\t                 currently we have only one person(details given below) but we are                 ");
    printf("\n\t\t                 accepting entries so be sure to hit us up if you want to join our                 ");		           	
    printf("\n\t\t                 comunity.                                                                         ");
    printf("\n\n\t\t                                    Welcome Aboard                                               ");	           	
    printf("\n\t\t                 Team -  D.S. (leader)                                                             ");	
    printf("\n\t\t                         D.S.#8865(discord)                                                        ");	           	
    printf("\n\n\t\t                                  *************************************                          ");		
    printf("\n\n\t\t                                                                    	    - Credit D.S.        ");  
    printf("\n\n\t\t          ____________________________________________________________________________________   ");

    getch();
    system("cls");

}

int main(){

    int choice;
    do{
    // Main Menu or Starting menu 
        printf(" \n\n\t\t                                    ---  Welcome  ---                             ");
        printf("\n\n\t\t          ________________________________________________________________________ ");
        printf("\n\n\t\t                                        BrainWorkout                               ");		
        printf("\n\n\t\t                ************************************************************       ");																
        printf("\n\n\t\t                          1. Play Game                                             ");  			           	
        printf("\n\t\t                          ------------------                                         ");  	       	
        printf("\n\t\t                          2. How to play ?                                           ");	           	
        printf("\n\t\t                          3. About us                                                ");
        printf("\n\n\t\t                ************************************************************       ");
        printf("\n\n\t\t                                                            	- Credit D.S.      ");  
        printf("\n\n\t\t                 Exit - 0                                                          ");
        printf("\n\t\t           _________________________________________________________________________ ");				  
        printf("\n\n\t\t          User Input - ");	
    // var choice to get input from user 								
        scanf("%d",&choice);
        Sleep(200);
        switch(choice){
            case 0:  exit(0);   // Exit_menu
            case 1: menu2();
                    break;
            case 2: how_t();
                    break;
            case 3: about();
                    break;
            default:
                    printf("\n\n\t\t           W");
                    Sleep(200);
                    printf("R");
                    Sleep(200);
                    printf("O");
                    Sleep(200);
                    printf("N");
                    Sleep(200);
                    printf("G");
                    Sleep(200);
                    printf(" ");
                    Sleep(200);
                    printf("I");
                    Sleep(200);
                    printf("N");
                    Sleep(200);
                    printf("P");
                    Sleep(200);
                    printf("U");
                    Sleep(200);
                    printf("T");
                    Sleep(200);
                    break;
        }
        system("cls");
    }
    while(choice!=0);

    getch();
    return 0;
}