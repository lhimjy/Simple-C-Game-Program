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
	
	printf("\n 1. ���� ����\n\n ���������� ������ ������ �� ������ �ո�� �޸� �� ��� ���� ��������   �����ϴ� �����̴�.\n\n �ո��� �����ϸ� 1��, �޸��� �����ϸ� 0�� �Է��ϸ� �ȴ�.\n");
	printf("\n �ʱ� �������� 3 �̸�, ������ ���� �ÿ��� ������ 1�� ������, Ʋ�� �ÿ�  �� �������� 1 �����Ѵ�. ������ �������� ��� ������ ������ ����ȴ�.\n\n �ְ� ������ ���� ���� �� ǥ�õȴ�.\n\n\n");
	printf("\n 2. ����\n\n ������ 1���� 9������ ���ڿ� 15������ ����� �̷���� �� ���� ������ �� ���Ͽ� �����ϴ� �����̴�. \n\n ������ ���� ���ǰ� ���� ���� ����� ������ ����.\n\n");
	printf("          YOU WIN!  :  * * * ** * ** ** ** ** **  :  999999��\n\n");
	printf("          JACKPOT!  :  7 7 7 �� ���� ���  :  77��\n\n");
	printf("          AWESOME!  :  �� ���� ���� ��� ���� ���  :  55��\n\n");
	printf("          GREAT!  :  �� ���ڰ� ��� ���� ���  :  33��\n\n");
	printf("          GOOD!  :  �� ���ڰ� ���� ���  :  7��\n\n\n");
	printf(" ���������� �ְ� ������ ���� ���� �� ǥ�õȴ�.");
}

int coingame(void){	
	system("cls");
	SetConsoleTitle("COIN GAME");
	system("mode con cols=45 lines=30");
	
	textcolor(14);
	printf("\n\n                 ���� ���� \n\n");
	textcolor(15);
	printf(" - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("       ���纸����. (1 : �ո�, 0 : �޸�) \n\n");
	
	int num, a, point = 0, key = 0, max = 0, life = 3;

	while (1){
	
		srand(time(NULL));
		
		num = rand()%2;
		
		printf("       ���� �Է��ϼ���");
		printf("  ���� ������ : ");
		textcolor(12);
		printf("%d\n\n",life);
		textcolor(15);
		scanf("%d", &a);
		
			if (num == a)
			{	
				textcolor(14);
				printf("       ������ϴ�!");
				printf("                 +1�� \n\n");
				textcolor(15);
				point++;
				continue;
			}
			else 
			{
				textcolor(12);
				printf("       Ʋ�Ƚ��ϴ�! \n\n");
				textcolor(15);
				life--;
			}
			if(life <= 0){
				printf("              ");
				textcolor(12);
				printf("�������� : %d��\n\n",point);
				textcolor(11);
				printf("    �ٽ��Ͻðڽ��ϱ�? (�� : 0  �ƴϿ� : 1)\n\n");
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
				printf("\n\n                 ���� ���� \n\n");
				textcolor(15);
				printf(" - - - - - - - - - - - - - - - - - - - - - -\n\n"); 
				printf("       ���纸����. (1 : �ո�, 0 : �޸�) \n\n");
				continue;
			}
			else if(key == 0){
				continue;
			}
			else{
				textcolor(12);
				printf("          �Է��� �߸��Ǿ����ϴ�!\n");
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
		SetConsoleTitle("JACKPOT"); // �̸�  
		system("mode con cols=42 lines=30");  // �ܼ�â ũ�� 
		
		srand((unsigned)time(NULL));
		
		textcolor(rand()%15+1);
		printf("\n\n                 jackpot\n\n\n");
		textcolor(15);
		
			printf("    �󸶸� �����Ͻðڽ��ϱ�?  ");
		printf("�ִ� : %d\n",money); 
		scanf("%d",&batting);
		
		if(batting > money){
			textcolor(12);
			printf("        �Է��� �߸��Ǿ����ϴ�!");
			Sleep(500);
			textcolor(15);
			continue;
		}
			
		now = money - batting;
		printf("\n");
		
		printf("����������������������\n");
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
	
		printf("����������������������\n");
		
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
			printf("\n\n    ������ �ݾ� : %d",money);
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
			printf("\n\n            ������ �ݾ� : %d",money);
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
			printf("\n\n            ������ �ݾ� : %d",money);
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
			printf("\n\n            ������ �ݾ� : %d",money);
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
			printf("\n\n            ������ �ݾ� : %d",money);
			Sleep(2000);
		}
		else{
			money = now;
			printf("\n\n            ������ �ݾ� : %d\n",money);
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
			printf("\n\n  �ٽ��Ͻðڽ��ϱ�? (�� : 0  �ƴϿ� : 1)\n\n");
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
			printf("        �Է��� �߸��Ǿ����ϴ�!\n");
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
			
			printf("\n\n\n\n                        ������ �����Ͻʽÿ�.\n\n\n\n\n");
			printf("       0.   ���� ����\n\n\n\n");
			printf("       1.   ���� ����\n\n\n\n");
			printf("       2.   ����\n\n\n");
			
			scanf("%d",&game_number);
			
			if(game_number == 0){
				explanation();
				Sleep(500);
			}
			else if(game_number == 1){
				printf("\n       �ֱ� �÷��� ���� : ���� ����\n       �ְ� ���� : %d\n",coingame());
				SetConsoleTitle("GAME OVER");
			}
			else if(game_number == 2){
				printf("\n\n        �ֱ� �÷��� ���� : ����\n        �ְ� �ݾ� : %d\n",jackpot());
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
					printf("\n\n   ���� �� : 21019 ���ؿ�\n\n   �̸Ű� ���α׷� ���� ��ȸ (2021�� 11�� 4��)\n\n   ��ǰ�� : GAME CENTER\n\n\n   �÷������ּż� �����մϴ�!");
					Sleep(5000);
					break;
				}
				else{
					break;
				} 
			}
			else{
				textcolor(12);
				printf("\n      �Է��� �߸��Ǿ����ϴ�!"); 
				textcolor(15);
			}
			
			printf("\n\n                                             ó������ : 0");
			textcolor(12);
			printf("   ���� : 1\n");
			textcolor(15);
			
			scanf("%d",&key);
		}
		else if(key == 1){
			return 0;
		}
		else{
			 textcolor(12);
			 printf("                    �Է��� �߸��Ǿ����ϴ�!\n");
			 textcolor(15);
			 key = 1;
		}
	}
	return 0;
}
