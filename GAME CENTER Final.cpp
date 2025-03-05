#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Player{
	char name[30];
	int coingame_score;
	int jackpot_score;
};

void textcolor(int color_number) 
	{
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
	}

void explanation(void){
	
	SetConsoleTitle("Explanation");
	system("mode con cols=71 lines=37");
	
	system("cls");
	
	printf("\n 1. 동전 게임\n\n 동전게임은 동전을 던졌을 때 동전의 앞면과 뒷면 중 어느 면이 나올지를   예상하는 게임이다.\n\n 앞면을 예상하면 1을, 뒷면을 예상하면 0을 입력하면 된다.\n");
	printf("\n 초기 라이프는 3 이며, 예상이 맞을 시에는 점수가 1점 오르고, 틀릴 시에  는 라이프가 1 감소한다. 보유한 라이프를 모두 소진시 게임이 종료된다.\n\n 최고 점수는 게임 종료 시 표시된다.\n\n\n");
	printf("\n 2. 잭팟\n\n 잭팟은 1부터 9까지의 숫자와 15가지의 색깔로 이루어진 세 수의 조합을 예 상하여 베팅하는 게임이다. \n\n 베팅의 성공 조건과 성공 시의 배당은 다음과 같다.\n\n");
	printf("          YOU WIN!  :  * * * ** * ** ** ** ** **  :  999999배\n\n");
	printf("          JACKPOT!  :  7 7 7 이 나온 경우  :  77배\n\n");
	printf("          AWESOME!  :  세 수의 색이 모두 같은 경우  :  55배\n\n");
	printf("          GREAT!  :  세 숫자가 모두 같은 경우  :  33배\n\n");
	printf("          GOOD!  :  두 숫자가 같은 경우  :  7배\n\n\n");
	printf(" 마찬가지로 최고 점수는 게임 종료 시 표시된다.");
}

int coingame(void){	
	system("cls");
	SetConsoleTitle("COIN GAME");
	system("mode con cols=45 lines=30");
	
	textcolor(14);
	printf("\n\n                 동전 게임 \n\n");
	textcolor(15);
	printf(" - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("       맞춰보세요. (1 : 앞면, 0 : 뒷면) \n\n");
	
	int num, a, point = 0, key = 0, max = 0, life = 3;

	while (1){
	
		srand(time(NULL));
		
		num = rand()%2;
		
		printf("       값을 입력하세요");
		printf("  남은 라이프 : ");
		textcolor(12);
		printf("%d\n\n",life);
		textcolor(15);
		scanf("%d", &a);
		
			if (num == a)
			{	
				textcolor(14);
				printf("       맞췄습니다!");
				printf("                 +1점 \n\n");
				textcolor(15);
				point++;
				continue;
			}
			else 
			{
				textcolor(12);
				printf("       틀렸습니다! \n\n");
				textcolor(15);
				life--;
			}
			if(life <= 0){
				printf("              ");
				textcolor(12);
				printf("최종점수 : %d점\n\n",point);
				textcolor(11);
				printf("    다시하시겠습니까? (예 : 0  아니요 : 1)\n\n");
				textcolor(15);
				scanf("%d",&key);
			}
			if(point > max){
				max = point;
			}
			if(key == 1){
				system("cls");
				break;
						 }
			else if(key == 0 && life <= 0){
				point = 0;
				life = 3;
				system("cls");
				textcolor(14);
				printf("\n\n                 동전 게임 \n\n");
				textcolor(15);
				printf(" - - - - - - - - - - - - - - - - - - - - - -\n\n"); 
				printf("       맞춰보세요. (1 : 앞면, 0 : 뒷면) \n\n");
				continue;
			}
			else if(key == 0){
				continue;
			}
			else{
				textcolor(12);
				printf("          입력이 잘못되었습니다!\n");
				textcolor(15);
				system("cls");
				break;
			}
		}
	return(max);
}

int jackpot(void){
    int key = 0, max = 0;
	int batting=0, money=3, earning = 0, now, num1,num2,num3,i,color1,color2,color3;
	
    while(1){
	  	if(key == 0){
			
		system("cls");
		SetConsoleTitle("JACKPOT"); // 이름  
		system("mode con cols=42 lines=30");  // 콘솔창 크기 
		
		srand((unsigned)time(NULL));
		
		textcolor(rand()%15+1);
		printf("\n\n                 jackpot\n\n\n");
		textcolor(15);
		
			printf("    얼마를 베팅하시겠습니까?  ");
		printf("최대 : %d\n",money); 
		scanf("%d",&batting);
		
		if(batting > money){
			textcolor(12);
			printf("        입력이 잘못되었습니다!");
			Sleep(500);
			textcolor(15);
			continue;
		}
			
		now = money - batting;
		printf("\n");
		
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		printf("==========================================\n");
		printf("==           ==           ==            ==\n");
		printf("==           ==           ==            ==\n");
		printf("==           ==           ==            ==\n");
		printf("==           ==           ==            ==\n");
		printf("==     ");
				textcolor(color1 = rand()%15+1);
		printf("%d",num1 = rand()%9+1);
				textcolor(15);
		printf("     ==     ");
				textcolor(color2 = rand()%15+1);
		printf("%d",num2 = rand()%9+1);
				textcolor(15);
		printf("     ==     ");
				textcolor(color3 = rand()%15+1);
		printf("%d",num3 = rand()%9+1);
				textcolor(15);
		printf("      ==");
		printf("==           ==           ==            ==\n");
		printf("==           ==           ==            ==\n");
		printf("==           ==           ==            ==\n");
		printf("==           ==           ==            ==\n");
		printf("==========================================\n");
	
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		
		Sleep(220);
		printf("\n");
		
		if(num1 == 7 && num1 == num2 && num2 == num3 && color1 == color2 && color2 == color3){
			for(i=0;i<102;i++){
				textcolor(i%16);
				printf("YOU WIN! ") ;
			}
			earning = batting * 999999;
			money = now + earning;
			textcolor(15);		
			printf("\n\n    보유한 금액 : %d",money);
			Sleep(5000);
			break;
		}
		else if(num1 == 7 && num1 == num2 && num2 == num3){
			for(i=0;i<51;i++){
				textcolor(i%16);
				printf("JACKPOT! ") ;
			}
			earning = batting * 77;
			money = now + earning;
				
			textcolor(15);		
			printf("\n\n            보유한 금액 : %d",money);
			Sleep(3000);
		}
		else if(color1 == color2 && color2 == color3){
			for(i=0;i<14;i++){
				textcolor(i + 2 % 6);
				printf("AWESOME! ");
			}
			earning = batting * 55;
			money = now + earning;
			textcolor(15);
			printf("\n\n            보유한 금액 : %d",money);
			Sleep(3000);
		}
		else if(num1 == num2 && num2 == num3){
			for(i=0;i<12;i++){
				textcolor(i + 2 % 6);
				printf("GREAT! ");
			}
			earning = batting * 33;
			money = now + earning;
			textcolor(15);
			printf("\n\n            보유한 금액 : %d",money);
			Sleep(2500);
		}
		else if(num1 == num2 || num2 == num3 || num3 == num1){
			for(i=0;i<7;i++){
				textcolor(i + 2 % 6);
				printf("GOOD! ");
			}
			earning = batting * 7;
			money = now + earning;
			textcolor(15);
			printf("\n\n            보유한 금액 : %d",money);
			Sleep(2000);
		}
		else{
			money = now;
			printf("\n\n            보유한 금액 : %d\n",money);
			Sleep(1200);
		}
		
		if(money > max){
			max = money;
		}
		
		if(money <= 0){
			textcolor(12);
			printf("\n                GAMEOVER");
			textcolor(15);
			money = 3;
			textcolor(12); 
			printf("\n\n  다시하시겠습니까? (예 : 0  아니요 : 1)\n\n");
			textcolor(15);
			scanf("%d",&key);
		}
		}
		
		else if(key == 1){
			system("cls");
			break;
			textcolor(12);
		}
		else{
			textcolor(12);
			printf("        입력이 잘못되었습니다!\n");
			textcolor(15);
		}
}
return(max);
}

int main(){
	int game_number,key = 0;
	
	while(1){
		if(key == 0){
			SetConsoleTitle("Game Center");
			system("mode con cols=50 lines=35");
			
			printf("\n\n\n\n                        게임을 선택하십시오.\n\n\n\n\n");
			printf("       0.   게임 설명서\n\n\n\n");
			printf("       1.   동전 게임\n\n\n\n");
			printf("       2.   잭팟\n\n\n");
			
			scanf("%d",&game_number);
			
			if(game_number == 0){
				explanation();
				Sleep(500);
			}
			else if(game_number == 1){
				printf("\n       최근 플레이 게임 : 동전 게임\n       최고 점수 : %d\n",coingame());
				SetConsoleTitle("GAME OVER");
			}
			else if(game_number == 2){
				printf("\n\n        최근 플레이 게임 : 잭팟\n        최고 금액 : %d\n",jackpot());
				SetConsoleTitle("GAME OVER");
			} 
			else if(game_number == 3){
				SetConsoleTitle("EASTER EGG");
				float easter_egg = 0;
				
				system("cls");
				
				printf("2101920211104");
				Sleep(300);
				
				system("cls");
				scanf("%f",&easter_egg);
				
				if(easter_egg == 2101920211104){
					SetConsoleTitle("CREDIT");
					system("mode con cols=50 lines=20");
					system("cls");
					printf("\n\n   만든 이 : 21019 임준용\n\n   이매고 프로그램 제작 대회 (2021년 11월 4일)\n\n   작품명 : GAME CENTER\n\n\n   플레이해주셔서 감사합니다!");
					Sleep(5000);
					break;
				}
				else{
					break;
				} 
			}
			else{
				textcolor(12);
				printf("\n      입력이 잘못되었습니다!"); 
				textcolor(15);
			}
			
			printf("\n\n                                             처음으로 : 0");
			textcolor(12);
			printf("   종료 : 1\n");
			textcolor(15);
			
			scanf("%d",&key);
		}
		else if(key == 1){
			return 0;
		}
		else{
			 textcolor(12);
			 printf("                    입력이 잘못되었습니다!\n");
			 textcolor(15);
			 key = 1;
		}
	}
	return 0;
}
