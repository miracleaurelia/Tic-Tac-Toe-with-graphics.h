#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

//global declaration
char Board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn='X';
int draw=-1;
int check=0;
int check5=0;

//prototyping
void printboard (int row,int column);
int getkey();
void turnwcomp();
void turntwoplayer();
void turntwoplayer_math();
int statgame();
void play_math();

//main program
int main() {
	int gd,gm,mode;
	detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	//generate angka random sesuai waktu (agar berubah2)
	srand(time(NULL));
    setcolor(BLUE);
    outtextxy(150,170,"TIC-TAC-TOE");
	setcolor(RED);
    outtextxy(150,190,"CHOOSE MODE");
	setcolor(RED);
	outtextxy(150,210,"1. WITH COMPUTER");
	setcolor(RED);
	outtextxy(150,230,"2. TWO PLAYERS");
	setcolor(RED);
	outtextxy(150,250,"3. TWO PLAYERS WITH MATH");
    mode=getkey();
    //49 adalah ascii char 1, dst
    //getch() baca char, return int
    if (mode==49) {
    	cleardevice();
        setcolor(BLUE);
        outtextxy(200,150,"TIC-TAC-TOE");
        outtextxy(200,50,"Player X - You");
        outtextxy(200,70,"Player O - Computer");
        printboard(row,column);
        int randturn = rand()%2+1;
        if (randturn==1) turn='X';
        else turn='O';
    	//jika game masih berjalan panggil fungsi untuk bermain
    	while(statgame()==1) {
    		if (turn=='O') {
        		setcolor(WHITE);
        		outtextxy(150,350,"Player with turn O");
			}
			else if (turn=='X') {
				setcolor(WHITE);
        		outtextxy(150,350,"Player with turn X");
			}
        	turnwcomp();
    	}
    	//pada saat kondisi menang dicek
    	//gilirannya sudah diubah maka jika menang saat turn O, yang menang sebenarnya adalah player X
    	//dan sebaliknya
    	//jika draw == -1 maka game tidak seri
    	if(turn=='O' && draw==-1) {
    		getkey();
    		cleardevice();
        	setcolor(WHITE);
        	outtextxy(50,200,"CONGRATULATIONS PLAYER X, YOU WON!");
    	}
    	else if(turn=='X' && draw==-1) {
    		getkey();
    		cleardevice();
        	setcolor(WHITE);
        	outtextxy(50,200,"CONGRATULATIONS PLAYER O, YOU WON!");
    	}
    	else {
    		getkey();
    		cleardevice();
    		setcolor(WHITE);
        	outtextxy(200,200,"IT'S A TIE!");
		}
	}
	else if(mode==50) {
		cleardevice();
        setcolor(BLUE);
        outtextxy(200,150,"TIC-TAC-TOE");
        printboard(row,column);
        int randturn = rand()%2+1;
        if (randturn==1) turn='X';
        else turn='O';
    	while(statgame()==1) {
			if (turn=='O') {
        		setcolor(WHITE);
        		outtextxy(150,350,"Player with turn O");
			}
			else if (turn=='X') {
				setcolor(WHITE);
        		outtextxy(150,350,"Player with turn X");
			}
        	turntwoplayer();
    	}
    	if(turn=='O' && draw==-1) {
    		getkey();
    		cleardevice();
    		setcolor(WHITE);
        	outtextxy(50,200,"CONGRATULATIONS PLAYER X, YOU WON!");
    	}
    	else if(turn=='X' && draw==-1) {
    		getkey();
    		cleardevice();
        	setcolor(WHITE);
        	outtextxy(50,200,"CONGRATULATIONS PLAYER O, YOU WON!");
    	}
    	else {
    		getkey();
    		cleardevice();
    		setcolor(WHITE);
        	outtextxy(200,200,"IT'S A TIE!");
		}
	}
	else if(mode==51) {
		cleardevice();
		setcolor(BLUE);
		outtextxy(200,150,"TIC-TAC-TOE");
        printboard(row,column);
        int randturn = rand()%2+1;
        if (randturn==1) turn='X';
        else turn='O';
    	while(statgame()==1) {
			if (turn=='O') {
        		setcolor(WHITE);
        		outtextxy(150,350,"Player with turn O");
			}
			else if (turn=='X') {
				setcolor(WHITE);
        		outtextxy(150,350,"Player with turn X");
			}
        	turntwoplayer_math();
    	}
    	if(turn=='O' && draw==-1) {
    		getkey();
    		cleardevice();
    		setcolor(WHITE);
        	outtextxy(50,200,"CONGRATULATIONS PLAYER X, YOU WON!");
    	}
    	else if(turn=='X' && draw==-1) {
    		getkey();
    		cleardevice();
        	setcolor(WHITE);
        	outtextxy(50,200,"CONGRATULATIONS PLAYER O, YOU WON!");
    	}
    	else {
    		getkey();
    		cleardevice();
    		setcolor(WHITE);
        	outtextxy(200,200,"IT'S A TIE!");
		}
	}
	getch();
	closegraph();
	return 0;
}

//fungsi untuk print board Tic Tac Toe
void printboard (int row,int column) {
    int i,j;
    char str[2];
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            if(i==row&&j==column) setcolor(RED);             
            else setcolor(WHITE);                        
            rectangle(j*35+200,i*35+200,j*35+30+200,i*35+30+200);
            sprintf(str,"%c",Board[i][j]);       
            outtextxy(j*35+8+200,i*35+8+200,str);
        }
    }
}

//fungsi untuk dapat membaca input user dari keyboard
int getkey() {
    int ch;
    ch=getch();
    return ch;
}

//fungsi jika user mau bermain dgn computer
void turnwcomp() {
    //menerima input user dan
    //mengganti karakter di box sesuai pilihan
    if (turn=='X') {
    	choice=getkey();
    	if (choice==49) {
        	row=0; column=0;
		}
		else if (choice==50) {
			row=0; column=1;
		}
		else if (choice==51) {
			row=0; column=2;
		}
		else if (choice==52) {
			row=1; column=0;
		}
        else if (choice==53) {
        	row=1; column=1;
		}
        else if (choice==54) {
        	row=1; column=2;
		}
        else if (choice==55) {
        	row=2; column=0; 
		}
        else if (choice==56) {
        	row=2; column=1;
		}
        else if (choice==57) {
        	row=2; column=2;
		}
		if(Board[row][column]!='X' && Board[row][column]!='O') {
	        //mengganti karakter di box pilihan jadi 'X' jika player X
	        //dan box belum ditempati
	        Board[row][column]='X';
	        turn='O'; //ganti giliran
    	}
    	else {
        	//jika box sudah terisi
        	//memanggil fungsi turnwcomp lagi (rekursi) untuk meminta input yg benar
        	cleardevice();
        	setcolor(BLUE);
        	outtextxy(200,150,"TIC-TAC-TOE");
        	outtextxy(200,50,"Player X - You");
        	outtextxy(200,70,"Player O - Computer");
        	printboard(row,column);
        	outtextxy(150,350,"Invalid Move");
        	turnwcomp();
        	cleardevice();
    	}
	}
    //kondisi2 agar komputer tidak dengan sangat mudah kalah
	else if(turn=='O') {
		delay(600);
		//choice nya random sesuai waktu karena pakai srand(time(NULL))
		//generate angka dr 1-9
		choice=rand()%9+1;
		//jika box 5 sudah diisi block salah 1 diagonal (yaitu box 1)
		if (Board[1][1]=='X' && check5==0) {
			Board[0][0]='O';
			turn='X';
			choice=1;
			check5=1;
		}
		//box 5 berhubungan dgn semua box lain maka diblock
		else if (Board[1][1]!='O' && Board[1][1]!='X')  {
			Board[1][1]='O';
			turn='X';
			choice=5;
		}
		//jika sudah ada 2 karakter 'O' baik diagonal, vertical, horizontal
		//maka tempatkan 'O' lagi agar menang
		//ditaruh diatas if nya agar diprioritaskan
        else if (((Board[0][1]=='O' && Board[0][2]=='O') || (Board[1][0]=='O' && Board[2][0]=='O') || (Board[1][1]=='O' && Board[2][2]=='O')) && Board[0][0]=='1') {
			Board[0][0]='O';
			turn='X'; //ganti turn
			choice=1; //set nilai choice agar tdk random
		}
		else if (((Board[0][0]=='O' && Board[0][2]=='O') || (Board[1][1]=='O' && Board[2][1]=='O')) && Board[0][1]=='2') {
			Board[0][1]='O';
			turn='X';
			choice=2;
		}
		else if (((Board[0][1]=='O' && Board[0][0]=='O') || (Board[1][2]=='O' && Board[2][2]=='O') ||(Board[1][1]=='O' && Board[2][0]=='O')) && Board[0][2]=='3') {
			Board[0][2]='O';
			turn='X';
			choice=3;
		}
		else if (((Board[1][1]=='O' && Board[1][2]=='O') || (Board[0][0]=='O' && Board[2][0]=='O')) && Board[1][0]=='4') {
			Board[1][0]='O';
			turn='X';
			choice=4;
		}
		else if (((Board[0][1]=='O' && Board[2][1]=='O') || (Board[1][0]=='O' && Board[1][2]=='O') || (Board[0][2]=='O' && Board[2][0]=='O')) && Board[1][1]=='5') {
			Board[1][1]='O';
			turn='X';
			choice=5;
		}
		else if (((Board[2][2]=='O' && Board[0][2]=='O') || (Board[1][0]=='O' && Board[1][1]=='O')) && Board[1][2]=='O') {
			Board[1][2]='O';
			turn='X';
			choice=6;
		}
		else if (((Board[0][0]=='O' && Board[1][0]=='O') || (Board[2][1]=='O' && Board[2][2]=='O') || (Board[1][1]=='O' && Board[0][2]=='O')) && Board[2][0]=='7') {
			Board[2][0]='O';
			turn='X';
			choice=7;
		}
		else if (((Board[0][1]=='O' && Board[1][1]=='O') || (Board[2][2]=='O' && Board[2][0]=='O')) && Board[2][1]=='8') {
			Board[2][1]='O';
			turn='X';
			choice=8;
		}
		else if (((Board[1][2]=='O' && Board[0][2]=='O') || (Board[2][1]=='O' && Board[2][0]=='O') || (Board[1][1]=='O' && Board[0][0]=='O')) && Board[2][2]=='9') {
			Board[2][2]='O';
			turn='X';
			choice=9;
		}
		//selnjutnya untuk blok lawan agar tidak menang
		//jika ada 2 karakter lawan baik diagonal, vertikal, horizontal
		else if (((Board[0][1]=='X' && Board[0][2]=='X') || (Board[1][0]=='X' && Board[2][0]=='X') || (Board[1][1]=='X' && Board[2][2]=='X')) && Board[0][0]=='1') {
			Board[0][0]='O';
			turn='X';
			choice=1;
		}
		else if (((Board[0][0]=='X' && Board[0][2]=='X') || (Board[1][1]=='X' && Board[2][1]=='X')) && Board[0][1]=='2') {
			Board[0][1]='O';
			turn='X';
			choice=2;
		}
		else if (((Board[0][1]=='X' && Board[0][0]=='X') || (Board[1][2]=='X' && Board[2][2]=='X') ||(Board[1][1]=='X' && Board[2][0]=='X')) && Board[0][2]=='3') {
			Board[0][2]='O';
			turn='X';
			choice=3;
		}
		else if (((Board[1][1]=='X' && Board[1][2]=='X') || (Board[0][0]=='X' && Board[2][0]=='X')) && Board[1][0]=='4') {
			Board[1][0]='O';
			turn='X';
			choice=4;
		}
		else if (((Board[0][1]=='X' && Board[2][1]=='X') || (Board[1][0]=='X' && Board[1][2]=='X') || (Board[0][2]=='X' && Board[2][0]=='X') || (Board[0][0]=='X' && Board[2][2]=='X')) && Board[1][1]=='5') {
			Board[1][1]='O';
			turn='X';
			choice=5;
		}
		else if (((Board[2][2]=='X' && Board[0][2]=='X') || (Board[1][0]=='X' && Board[1][1]=='X')) && Board[1][2]=='6') {
			Board[1][2]='O';
			turn='X';
			choice=6;
		}
		else if (((Board[0][0]=='X' && Board[1][0]=='X') || (Board[2][1]=='X' && Board[2][2]=='X') || (Board[1][1]=='X' && Board[0][2]=='X')) && Board[2][0]=='7') {
			Board[2][0]='O';
			turn='X';
			choice=7;
		}
		else if (((Board[0][1]=='X' && Board[1][1]=='X') || (Board[2][2]=='X' && Board[2][0]=='X')) && Board[2][1]=='8') {
			Board[2][1]='O';
			turn='X';
			choice=8;
		}
		else if (((Board[1][2]=='X' && Board[0][2]=='X') || (Board[2][1]=='X' && Board[2][0]=='X') || (Board[1][1]=='X' && Board[0][0]=='X')) && Board[2][2]=='9') {
			Board[2][2]='O';
			turn='X';
			choice=9;
		}
		//jika lawan ada di box tertentu
		//halangin jalannya agar lebih sulit untuk menang
		else if (choice==1 && Board[0][0]=='1' && (Board[0][1]=='X' || Board[0][2]=='X' || Board[1][0]=='X' || Board[1][1]=='X' || Board[2][0]=='X' || Board[2][2]=='X')) {
			Board[0][0]='O';
			turn='X';
		}
		else if (choice==2 && Board[0][1]=='2' && (Board[0][0]=='X' || Board[0][2]=='X' || Board[1][1]=='X' || Board[2][1]=='X')) {
			Board[0][1]='O';
			turn='X';
		}
		else if (choice==3 && Board[0][2]=='3' && (Board[0][0]=='X' || Board[0][1]=='X' || Board[1][2]=='X' || Board[2][2]=='X' || Board[1][1]=='X' || Board[2][0]=='X')) {
			Board[0][2]='O';
			turn='X';
		}
		else if (choice==4 && Board[1][0]=='4' && (Board[0][0]=='X' || Board[2][0]=='X' || Board[1][1]=='X' || Board[1][2]=='X')) {
			Board[1][0]='O';
			turn='X';
		}
		else if (choice==5 && Board[1][1]=='5' && (Board[0][1]=='X' || Board[1][0]=='X' || Board[1][2]=='X' || Board[2][1]=='X' || Board[0][0]=='X' || Board[2][2]=='X')) {
			Board[1][1]='O';
			turn='X';
		}
		else if (choice==6 && Board[1][2]=='6' && (Board[2][2]=='X' || Board[0][2]=='X' || Board[1][1]=='X'|| Board[1][0]=='X')) {
			Board[1][2]='O';
			turn='X';
		}
		else if (choice==7 && Board[2][0]=='7' && (Board[1][0]=='X' || Board[2][1]=='X' || Board[0][2]=='X' || Board[1][1]=='X')) {
			Board[2][0]='O';
			turn='X';
		}
		else if (choice==8 && Board[2][1]=='8' && (Board[2][2]=='X' || Board[2][0]=='X' || Board[1][1]=='X'|| Board[0][1]=='X')) {
			Board[2][1]='O';
			turn='X';
		}
		else if (choice==9 && Board[2][2]=='9' && (Board[0][2]=='X' || Board[1][2]=='X' || Board[2][0]=='X' || Board[2][1]=='X' || Board[0][0]=='X' || Board[1][1]=='X')) {
			Board[2][2] = 'O';
			turn='X';
		}
		//jika syarat tidak ada yang memenuhi pilih angka lain
		else {
			choice=rand()%9;
		}
		//mengupdate row dan column untuk fungsi printboard
		if (choice==1) {
        	row=0; column=0;
		}
		else if (choice==2) {
			row=0; column=1;
		}
		else if (choice==3) {
			row=0; column=2;
		}
		else if (choice==4) {
			row=1; column=0;
		}
        else if (choice==5) {
        	row=1; column=1;
		}
        else if (choice==6) {
        	row=1; column=2;
		}
        else if (choice==7) {
        	row=2; column=0; 
		}
        else if (choice==8) {
        	row=2; column=1;
		}
        else if (choice==9) {
        	row=2; column=2;
		}
    }
    setcolor(BLUE);
    outtextxy(200,150,"TIC-TAC-TOE");
    outtextxy(200,50,"Player X - You");
    outtextxy(200,70,"Player O - Computer");
    printboard(row,column);
}

//fungsi untuk dua player
void turntwoplayer() {
    choice=getkey();
    if (choice==49) {
       	row=0; column=0;
	}
	else if (choice==50) {
		row=0; column=1;
	}	
	else if (choice==51) {
		row=0; column=2;
	}
	else if (choice==52) {
		row=1; column=0;
	}
	else if (choice==53) {
        row=1; column=1;
	}
	else if (choice==54) {
       	row=1; column=2;
	}
    else if (choice==55) {
        row=2; column=0; 
	}
    else if (choice==56) {
       	row=2; column=1;
	}
    else if (choice==57) {
      	row=2; column=2;
	}
    if(turn=='X' && Board[row][column]!='X' && Board[row][column]!='O') {
        Board[row][column]='X';
        turn='O';
    }
	else if(turn=='O' && Board[row][column]!='X' && Board[row][column]!='O') {
        Board[row][column]='O';
        turn='X';
    }
	else {
        cleardevice();
        setcolor(BLUE);
        outtextxy(200,150,"TIC-TAC-TOE");
        printboard(row,column);
        outtextxy(150,350,"Invalid Move");
        turntwoplayer();
        cleardevice();
    }
    setcolor(BLUE);
    outtextxy(200,150,"TIC-TAC-TOE");
    printboard(row,column);
}

void turntwoplayer_math() {
    choice=getkey();
    if (choice==49) {
       	row=0; column=0;
	}
	else if (choice==50) {
		row=0; column=1;
	}	
	else if (choice==51) {
		row=0; column=2;
	}
	else if (choice==52) {
		row=1; column=0;
	}
	else if (choice==53) {
        row=1; column=1;
	}
	else if (choice==54) {
       	row=1; column=2;
	}
    else if (choice==55) {
        row=2; column=0; 
	}
    else if (choice==56) {
       	row=2; column=1;
	}
    else if (choice==57) {
      	row=2; column=2;
	}
	if (turn=='X' && Board[row][column]!='X' && Board[row][column]!='O') {
		cleardevice();
 		play_math();
 		getkey();
 		cleardevice();
	}
	else if (turn=='O' && Board[row][column]!='X' && Board[row][column]!='O') {
		cleardevice();
 		play_math();
 		getkey();
 		cleardevice();
	}
	else {
		cleardevice();
		setcolor(BLUE);
		outtextxy(200,150,"TIC-TAC-TOE");
		printboard(row,column);
        outtextxy(150,350,"Invalid Move");
        turntwoplayer_math();
        cleardevice();
	}
    if(turn=='X' && Board[row][column]!='X' && Board[row][column]!='O') {
        if (check==1) Board[row][column]='X';
        turn='O';
    }
	else if(turn=='O' && Board[row][column]!='X' && Board[row][column]!='O') {
        if (check==1) Board[row][column]='O';
        turn='X';
    }
    setcolor(BLUE);
    outtextxy(200,150,"TIC-TAC-TOE");
    printboard(row,column);
}

//fungsi untuk melihat status game seperti masih lanjut/selesai (karena salah satu menang)
int statgame() {
    //cek kondisi menang untuk baris dan kolom
    for(int i=0; i<3; i++) {
    	if(Board[i][0]==Board[i][1] && Board[i][0]==Board[i][2] || Board[0][i]==Board[1][i] && Board[0][i]==Board[2][i]) {
    		return -1;
		}
	}
    //cek kondisi menang untuk diagonal
    if(Board[0][0]==Board[1][1] && Board[0][0]== Board[2][2] || Board[0][2]==Board[1][1] && Board[0][2]==Board[2][0]) {
    	return -1;
	}
    //cek apa masih ada yang belum terisi, jika ada game masih lanjut
    for(int i=0; i<3; i++) {
    	for(int j=0; j<3; j++) {
    		if(Board[i][j]!='X' && Board[i][j]!='O') {
    			return 1;
			}
		}
	}
    //jika kondisi di atas tidak ada yg memenuhi (alias seri)
    //maka game draw
    draw = 1;
    return -1;
}

int timeover(char ans) {
	int limit=0;
	int s=0;
	char c='z',countdown[10];
	//selama limit=0
	while(limit==0) {
		//jika ada key yg dipencet
    	if(kbhit()==1) {
        	c=getkey();
        	break;
    	}
    	Sleep(1000);
    	sprintf(countdown, "Timer : %d",9-s);
    	setcolor(RED);
    	outtextxy(400,10,countdown);
    	if (++s>9) {
    		limit=1;
		}
    	else limit=0; //jika kondisi salah nilai limit=0
	}
	if (c>='A' && c<='Z') c+=32;
	if (c!=ans) return -1;
	else return 1;
}

void play_math() {
	int a,b,c,d,e,random1,random2,randchoice,randchoice2;
	random1=rand()%70+11;
	random2=rand()%9+1;
	randchoice=rand()%4+1;
	randchoice2=rand()%4+1;
	if (randchoice==1) {
		char store1[100],store2[100],store3[100],question[20],option2[10],option3[10],option4[10],option5[10];
		sprintf(question,"%d + %d = ?",random1,random2);
		outtextxy(10,10,question);
		int ans1=random1+random2;
		int randmc1=rand()%5 + (ans1-5);
		int randmc2=rand()%5 + (ans1+1);
		int randmc3=ans1+10;
		int randmc4=ans1-10;
		if (randchoice2==1) {
			sprintf(store1,"A. %d",ans1);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('a')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
                outtextxy(10,230,store2);
			}
            else {
            	check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==2) {
			sprintf(store1,"A. %d",randmc2);
			sprintf(option2,"B. %d",ans1);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",randmc4);
			sprintf(option5,"E. %d",randmc3);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('b')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==3) {
			sprintf(store1,"A. %d",randmc4);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",ans1);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc2);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('c')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==4) {
			sprintf(store1,"A. %d",randmc3);
			sprintf(option2,"B. %d",randmc2);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",ans1);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('d')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else {
			sprintf(store1,"A. %d",randmc1);
			sprintf(option2,"B. %d",randmc4);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",ans1);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('e')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
	}
	else if (randchoice==2) {
		char store1[100],store2[100],store3[100],question[20],option2[10],option3[10],option4[10],option5[10];
		sprintf(question,"%d - %d = ?\n",random1,random2);
		outtextxy(10,10,question);
		int ans1=random1-random2;
		int randmc1=rand()%5 + (ans1-5);
		int randmc2=rand()%5 + (ans1+1);
		int randmc3=ans1+10;
		int randmc4=ans1-10;
		if (randchoice2==1) {
			sprintf(store1,"A. %d",ans1);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('a')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==2) {
			sprintf(store1,"A. %d",randmc2);
			sprintf(option2,"B. %d",ans1);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",randmc4);
			sprintf(option5,"E. %d",randmc3);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('b')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==3) {
			sprintf(store1,"A. %d",randmc4);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",ans1);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc2);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('c')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==4) {
			sprintf(store1,"A. %d",randmc3);
			sprintf(option2,"B. %d",randmc2);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",ans1);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('d')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else {
			sprintf(store1,"A. %d",randmc1);
			sprintf(option2,"B. %d",randmc4);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",ans1);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('e')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
	}
	else if (randchoice==3) {
		char store1[100],store2[100],store3[100],question[20],option2[10],option3[10],option4[10],option5[10];
		sprintf(question,"%d x %d = ?\n",random1,random2);
		outtextxy(10,10,question);
		int ans1=random1*random2;
		int randmc1=rand()%5 + (ans1-5);
		int randmc2=rand()%5 + (ans1+1);
		int randmc3=ans1+10;
		int randmc4=ans1-10;
		if (randchoice2==1) {
			sprintf(store1,"A. %d",ans1);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('a')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==2) {
			sprintf(store1,"A. %d",randmc2);
			sprintf(option2,"B. %d",ans1);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",randmc4);
			sprintf(option5,"E. %d",randmc3);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('b')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==3) {
			sprintf(store1,"A. %d",randmc4);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",ans1);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc2);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('c')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==4) {
			sprintf(store1,"A. %d",randmc3);
			sprintf(option2,"B. %d",randmc2);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",ans1);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('d')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else {
			sprintf(store1,"A. %d",randmc1);
			sprintf(option2,"B. %d",randmc4);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",ans1);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('e')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
	}
	else if (randchoice==4) {
		char store1[100],store2[100],store3[100],question[20],option2[10],option3[10],option4[10],option5[10];
		int i,j;
		i=rand()%70+11;
		j=rand()%9+1;
		while (i%j!=0) {
			i=rand()%70+11;
			j=rand()%9+1;
		}
		random1=i;
		random2=j;
		sprintf(question,"%d / %d = ?\n",random1,random2);
		outtextxy(10,10,question);
		int ans1=random1/random2;
		int randmc1=rand()%5 + (ans1-5);
		int randmc2=rand()%5 + (ans1+1);
		int randmc3=ans1+10;
		int randmc4=ans1-10;
		if (randchoice2==1) {
			sprintf(store1,"A. %d",ans1);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('a')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==2) {
			sprintf(store1,"A. %d",randmc2);
			sprintf(option2,"B. %d",ans1);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",randmc4);
			sprintf(option5,"E. %d",randmc3);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('b')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==3) {
			sprintf(store1,"A. %d",randmc4);
			sprintf(option2,"B. %d",randmc1);
			sprintf(option3,"C. %d",ans1);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",randmc2);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('c')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else if (randchoice2==4) {
			sprintf(store1,"A. %d",randmc3);
			sprintf(option2,"B. %d",randmc2);
			sprintf(option3,"C. %d",randmc1);
			sprintf(option4,"D. %d",ans1);
			sprintf(option5,"E. %d",randmc4);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('d')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
		else {
			sprintf(store1,"A. %d",randmc1);
			sprintf(option2,"B. %d",randmc4);
			sprintf(option3,"C. %d",randmc2);
			sprintf(option4,"D. %d",randmc3);
			sprintf(option5,"E. %d",ans1);
			outtextxy(10,60,store1);
			outtextxy(10,90,option2);
			outtextxy(10,120,option3);
			outtextxy(10,150,option4);
			outtextxy(10,180,option5);
			char ans;
			if (timeover('e')==1) {
				check=1;
				sprintf(store2,"Correct! Your mark has been placed.\n");
				outtextxy(10,230,store2);
			}
			else {
				check=0;
                sprintf(store3,"Wrong, you lose your turn.\n");
                outtextxy(10,230,store3);
            }
		}
	}
}
