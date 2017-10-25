#include <math.h>
#include "DxLib.h"

struct State{
	int student;
	int x;
	int y;
	double rad;
	double v;
	double vx;
	double vy;
	double vulk;
};

struct Game{
	int bullet;
	int clear;
	int background;
	int Point;
};

struct switchs{
	int x;
	int y;
	int image;
	double vulk;
	int off;
};

struct boss{
	int x;
	int y;
	int image;
	double hp;
	double vulk;
	int attack;
	int sound;
	int HitSound;
	int invisible;
	int showup;
};

struct SubBoss{
	int x;
	int y;
	int image;
	double hp;
	double vulk;
	int attack;
	int shield;
	int sound;
	int HitSound;
	int Smile;
}; 

struct obstacles{
	SubBoss Sub_boss;
	boss Boss;
	switchs Switch[3];
};

const double PI = 3.141592;
const double g = -2;

int boom(State *character){ // 폭탄이 터질떄 일어나는 효과입니다.
	int bomb = LoadSoundMem("sound/bomb.mp3");
	int color = GetColor(255, 0, 0);

	character->student = LoadGraph("Image/effect/bomb.png");
	DrawRotaGraph(character->x, character->y, (float)1 / 1.5, 0, character->student, TRUE, FALSE);
	
	ScreenFlip();
	PlaySoundMem(bomb, DX_PLAYTYPE_BACK);
	Sleep(120);
	

	return 0;
}

int CalHP(State *character, double *hp){ //HP를 계산합니다.
	*hp -= sqrt(pow(character->vx,2)+pow(character->vy,2));
	return 0;
}


int resetCh(State *character){ // 캐릭터의 위치값을 초기화시켜줍니다.
	*character = { LoadGraph("Image/character/bomb.png"), 50, 430, 0, 50, character->v * cos(character->rad - (double)1/4*PI), character->v*sin(character->rad - (double)1 / 4 * PI),20 };
	return 0;
}

int setV(State *character){ // v의 값에 따라 vx와 vy를 결정합니다.
	character->vx = character->v * cos(character->rad-(double)1/4*PI);
	character->vy = character->v * sin(character->rad - (double)1 / 4 * PI);
	return 0;
}

int Stage_Screen(obstacles *Obstacle, Game * info){ // 장애물이나 배경 등 스테이지를 표시합니다.
	int i;
	int col_Boss= GetColor(255,0,0);
	int col_SubBoss = GetColor(0, 0, 0); 
	int col_bullet = GetColor(255, 255, 255);

	DrawGraph(0, 0, info->background, TRUE); // 배경화면입니다.

	//중간보스가 살아있다면, 보스는 투명화가 되어있습니다.
	if (Obstacle->Boss.attack == 0) { SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); } //알파 블렌드모드(투명도) 사용
	DrawRotaGraph(Obstacle->Boss.x, Obstacle->Boss.y, 2, 0, Obstacle->Boss.image, TRUE,FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // 알파 블렌드모드 해제
	if (Obstacle->Boss.attack == 1) { DrawRotaGraph(Obstacle->Boss.x-34, Obstacle->Boss.y+53, 2, 0, info->Point, TRUE, FALSE); } //약점 조준선입니다. 중간보스가 쓰러지면 나타납니다.
	
	DrawRotaGraph(Obstacle->Sub_boss.x, Obstacle->Sub_boss.y, (float)1/4, 0, Obstacle->Sub_boss.image, TRUE, FALSE);
	DrawRotaGraph(Obstacle->Sub_boss.x, Obstacle->Sub_boss.y, (float)1.6, 0, Obstacle->Sub_boss.shield, TRUE, FALSE);
	DrawFormatString(100, 400, col_bullet, "남은 총알 : %d", info->bullet-1);

	for (i = 0; i < 3; i++)
		DrawRotaGraph(Obstacle->Switch[i].x, Obstacle->Switch[i].y, 1, 0, Obstacle->Switch[i].image, TRUE, FALSE);
	if (Obstacle->Boss.hp > 0){
		DrawFormatString(50, 20, col_Boss, "HP : %.0lf", Obstacle->Boss.hp);
	}
	else{
		DrawFormatString(50, 20, col_Boss, "사망");
	}
	if (Obstacle->Sub_boss.hp>0)
		DrawFormatString(50, 40, col_SubBoss, "HP : %.0lf", Obstacle->Sub_boss.hp);
	else{
		DrawFormatString(50, 40, col_SubBoss, "사망");
	}
	return 0;
}

int UpdateKey() // 키가 여러번 입력되지 못하도록 해줍니다.
{
	char tmpKey[256]; //현재의 키 입력 상태를 저장합니다.
	GetHitKeyStateAll(tmpKey); // 모든 키의 입력 상태를 갱신합니다.

	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i] != 0){
			tmpKey[i]++;
		}
		else{
			tmpKey[i] = 0;
		}
	}

	return 0;
}


int selectPower(State *character, int arrow, obstacles *Obstacle, Game *info){ // 처음 속도를 결정하는 함수입니다.

	while (CheckHitKey(KEY_INPUT_SPACE) != 1){
		ProcessMessage();
		ClearDrawScreen();

		Stage_Screen(Obstacle,info);

		DrawRotaGraph(character->x, character->y, (float)1/3, 0, character->student, TRUE, FALSE); //이미지를 출력
		DrawRotaGraph(character->x, character->y, character->v / 100, character->rad, arrow, TRUE, FALSE);

		if (CheckHitKey(KEY_INPUT_D) == 1){
			if (character->v <= 120){
				character->v += 1;
			}
		}
		if (CheckHitKey(KEY_INPUT_W) == 1){
			if (character->rad>-(float)1 / 4 * PI)
				character->rad -= 0.01;
		}


		if (CheckHitKey(KEY_INPUT_A) == 1){
			if (character->v >= 50)
				character->v -= 1;
		}
		if (CheckHitKey(KEY_INPUT_S) == 1){
			if (character->rad<(float)1 / 4 * PI)
				character->rad += 0.01;
		}

		ScreenFlip();
		
		if (UpdateKey() != 0) // 오류시 종료
			return 0;
	
	}
	
	if (setV(character) != 0)
		return 0;

	return 0;
}

int distance(State *character, int a, int b){
	return (int)sqrt(pow((double)character->x - a,2) + pow((double)character->y - b,2));
}

int collision(State *character, obstacles *Obstacle){ //충돌 함수입니다. 충돌이 된다면 1을 반환합니다.
	int i;
	int ShieldOn = LoadSoundMem("sound/ShieldOn.MP3");
	int ShieldOff = LoadSoundMem("sound/ShieldOff.MP3");

	if (Obstacle->Boss.attack == 1){
		if (character->vulk + Obstacle->Boss.vulk >= distance(character, Obstacle->Boss.x-34, Obstacle->Boss.y+53)){
			if (Obstacle->Boss.attack == 1){
				CalHP(character, &(Obstacle->Boss.hp));
				if (Obstacle->Boss.hp>0){
				PlaySoundMem(Obstacle->Boss.HitSound, DX_PLAYTYPE_BACK);
				}
			}
			return 1;
		}
	}

	if ((character->vulk + Obstacle->Sub_boss.vulk >= distance(character, Obstacle->Sub_boss.x, Obstacle->Sub_boss.y)) && (Obstacle->Sub_boss.hp > 0)){
		if (Obstacle->Sub_boss.attack == 1){
			CalHP(character, &(Obstacle->Sub_boss.hp));

			if (Obstacle->Sub_boss.hp <= 0){// 중간보스가 죽으면 떄릴 수 있지만 그렇지 않다면 무적입니다.
				Obstacle->Boss.attack = 1;
				Obstacle->Sub_boss.image = 0;
				PlaySoundMem(Obstacle->Sub_boss.sound, DX_PLAYTYPE_BACK); // 중간 보스가 죽을 시 비명을 지릅니다.
				PlaySoundMem(Obstacle->Boss.showup, DX_PLAYTYPE_BACK);
				Sleep(120);
				return 1;
			}
			else{
				Obstacle->Boss.attack = 0;
				PlaySoundMem(Obstacle->Sub_boss.HitSound, DX_PLAYTYPE_BACK);
			}
		}
		else { PlaySoundMem(Obstacle->Sub_boss.Smile, DX_PLAYTYPE_BACK); }
		return 1;
	}
	for (i = 0; i < 3; i++) // 스위치가 맞을 때 온이었으면 오프로, 오프였으면 온으로 바뀝니다.
		if (character->vulk + Obstacle->Switch[i].vulk >= distance(character, Obstacle->Switch[i].x, Obstacle->Switch[i].y)){
			if (Obstacle->Switch[i].off == 0){
				Obstacle->Switch[i].image = LoadGraph("Image/obstacle/switch_off.png", TRUE);
				Obstacle->Switch[i].off = 1;
			}

			else{
				Obstacle->Switch[i].image = LoadGraph("Image/obstacle/switch_on.png", TRUE);
				if ((Obstacle->Sub_boss.hp > 0) && (Obstacle->Switch[0].off == 1 && Obstacle->Switch[1].off == 1 && Obstacle->Switch[2].off == 1)) { PlaySoundMem(ShieldOn, DX_PLAYTYPE_BACK); }
				Obstacle->Switch[i].off = 0;				
			}

			if (Obstacle->Switch[0].off == 1 && Obstacle->Switch[1].off == 1 && Obstacle->Switch[2].off == 1){ // 스위치가 모두 꺼져있으면 보스들을 떄릴 수 있지만, 모두 켜져있지 않으면 무적이 됩니다.
				Obstacle->Sub_boss.attack = 1;
				Obstacle->Sub_boss.shield = 0;
				if (Obstacle->Sub_boss.hp > 0) { PlaySoundMem(ShieldOff, DX_PLAYTYPE_BACK); }
				if (Obstacle->Sub_boss.hp < 0) { 
					if (Obstacle->Boss.attack == 0){ PlaySoundMem(Obstacle->Boss.showup, DX_PLAYTYPE_BACK); }
					Obstacle->Boss.attack = 1;
					
				}
			}
			else {
				Obstacle->Sub_boss.attack = 0;
				if (Obstacle->Boss.attack == 1){ PlaySoundMem(Obstacle->Boss.invisible, DX_PLAYTYPE_BACK); }
				Obstacle->Boss.attack = 0;
				if (Obstacle->Sub_boss.hp > 0)
					Obstacle->Sub_boss.shield = LoadGraph("Image/effect/shield.png");
			}

		return 1;
		}

	


	if (character->y >= 430){
		return 1;
	}

	return 0;
}

int flying(State *character, obstacles *Obstacle, Game *info){ // 포물선으로 날아갈 수 있도록 해줍니다.
	int collision_switch=0;

	while (collision_switch != 1 ){
		ProcessMessage();
		ClearDrawScreen();
		Stage_Screen(Obstacle,info);
		DrawRotaGraph(character->x, character->y, (float)1/3, 0, character->student, TRUE, FALSE);
		character->x += (int)character->vx/7;
		character->vy -= g;
		character->y += (int)character->vy/7;

		collision_switch = collision(character, Obstacle);

		if (collision_switch == 1){
			boom(character);
			if (Obstacle->Boss.hp <= 0){ // 보스가 비명을 지를 수 있도록 합니다.
				PlaySoundMem(Obstacle->Boss.sound, DX_PLAYTYPE_NORMAL);
			}
		}

		ScreenFlip();

	}

	if (Obstacle->Boss.hp<=0) // 보스가 사망할 시 게임이 클리어 될 수 있도록 합니다.
		info->clear = 1;

	return 0;
}



int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	// 창 모드로 설정
	if (ChangeWindowMode(TRUE) != 0)
		return 0;

	if (DxLib_Init() != 0)
		return 0;// DX라이브러리 초기화

	SetDrawScreen(DX_SCREEN_BACK); // 묘화처리를 후위표면으로 설정

 // 패배했을시 다시 이쪽으로 옵니다.
replay: //게임 오버(패배) 시 Y를 누르면 이쪽부터 다시 실행합니다.

	State character;
	obstacles Obstacle;
	Game info = { 31, 0, LoadGraph("Image/etc/background.png"), LoadGraph("image/etc/point.png") };

	int arrow;
	// 이미지들을 불러옵니다.
	int clear = LoadGraph("Image/etc/clear.png");
	int gameover = LoadGraph("Image/etc/gameover.png");

	//소리들을 불러옵니다.
	int clear_sound = LoadSoundMem("sound/clear.MP3");
	int BackgroundSound = LoadSoundMem("sound/background.WAV"); // 배경음악입니다.
	int jump = LoadSoundMem("sound/jump.WAV");
	int gameover_sound = LoadSoundMem("sound/gameover.WAV");

	arrow = LoadGraph("Image/etc/arrow.png"); // 화살표 로드

	Obstacle.Boss = { 600, 250, LoadGraph("Image/character/boss.png", TRUE), 700, 20, 0, LoadSoundMem("sound/scream_boss.MP3"),LoadSoundMem("sound/HitBoss.MP3"),LoadSoundMem("sound/invisible.MP3"),LoadSoundMem("sound/showup.MP3")}; // 장애물들의 초기값 지정
	
	Obstacle.Sub_boss = { 240, 120, LoadGraph("Image/character/sub_boss.png"), 300, 30, 0, LoadGraph("Image/effect/shield.png"), LoadSoundMem("sound/scream_sub_boss.MP3"),LoadSoundMem("sound/HitSub.MP3"),LoadSoundMem("sound/smile.MP3") };
	Obstacle.Switch[0] = { 150, 200, LoadGraph("Image/obstacle/switch_on.png", TRUE),20,0 };
	Obstacle.Switch[1] = { 400, 100, LoadGraph("Image/obstacle/switch_on.png", TRUE),20,0 };
	Obstacle.Switch[2] = { 400, 320, LoadGraph("Image/obstacle/switch_on.png", TRUE),20,0 };

	PlaySoundMem(BackgroundSound, DX_PLAYTYPE_BACK);

	if (resetCh(&character) != 0)
		return 0;


	while (info.bullet != 0)
	{
		if (ProcessMessage() != 0)
			return 0;

		if (ClearDrawScreen() != 0)
			return 0;

		if (selectPower(&character, arrow, &Obstacle, &info) != 0)
			return 0;

		PlaySoundMem(jump, DX_PLAYTYPE_BACK);

		if (flying(&character, &Obstacle,&info) != 0)
			return 0;

		if (resetCh(&character) != 0)
			return 0;
	
		DrawRotaGraph(character.x, character.y, (float)1 / 3, 0, character.student, TRUE, FALSE);

		ScreenFlip(); // 후위표면과 전위 표면을 뒤바꿈.

		info.bullet--;

		if (info.clear == 1)
			break;
	}
	
	if (info.clear == 1){
		ClearDrawScreen();
		DrawRotaGraph(320, 240, 1, 0, clear, TRUE, FALSE);
		ScreenFlip();
		PlaySoundMem(clear_sound, DX_PLAYTYPE_NORMAL);
	}
	else
	{
		ClearDrawScreen();
		DrawRotaGraph(320, 240, 1, 0, gameover, TRUE, FALSE);
		ScreenFlip();
		PlaySoundMem(gameover_sound, DX_PLAYTYPE_NORMAL);
		while (1){ //Y를 누르면 처음부터 다시 시작하고, N을 누르면 종료합니다.
			ProcessMessage();
			if (CheckHitKey(KEY_INPUT_Y) == 1)
				goto replay;  // 
			if (CheckHitKey(KEY_INPUT_N) == 1)
				break;
		}
	}
	WaitKey();
    DxLib_End();    // DX라이브라리 해제
    return 0;
}