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

int boom(State *character){ // ��ź�� ������ �Ͼ�� ȿ���Դϴ�.
	int bomb = LoadSoundMem("sound/bomb.mp3");
	int color = GetColor(255, 0, 0);

	character->student = LoadGraph("Image/effect/bomb.png");
	DrawRotaGraph(character->x, character->y, (float)1 / 1.5, 0, character->student, TRUE, FALSE);
	
	ScreenFlip();
	PlaySoundMem(bomb, DX_PLAYTYPE_BACK);
	Sleep(120);
	

	return 0;
}

int CalHP(State *character, double *hp){ //HP�� ����մϴ�.
	*hp -= sqrt(pow(character->vx,2)+pow(character->vy,2));
	return 0;
}


int resetCh(State *character){ // ĳ������ ��ġ���� �ʱ�ȭ�����ݴϴ�.
	*character = { LoadGraph("Image/character/bomb.png"), 50, 430, 0, 50, character->v * cos(character->rad - (double)1/4*PI), character->v*sin(character->rad - (double)1 / 4 * PI),20 };
	return 0;
}

int setV(State *character){ // v�� ���� ���� vx�� vy�� �����մϴ�.
	character->vx = character->v * cos(character->rad-(double)1/4*PI);
	character->vy = character->v * sin(character->rad - (double)1 / 4 * PI);
	return 0;
}

int Stage_Screen(obstacles *Obstacle, Game * info){ // ��ֹ��̳� ��� �� ���������� ǥ���մϴ�.
	int i;
	int col_Boss= GetColor(255,0,0);
	int col_SubBoss = GetColor(0, 0, 0); 
	int col_bullet = GetColor(255, 255, 255);

	DrawGraph(0, 0, info->background, TRUE); // ���ȭ���Դϴ�.

	//�߰������� ����ִٸ�, ������ ����ȭ�� �Ǿ��ֽ��ϴ�.
	if (Obstacle->Boss.attack == 0) { SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128); } //���� ������(����) ���
	DrawRotaGraph(Obstacle->Boss.x, Obstacle->Boss.y, 2, 0, Obstacle->Boss.image, TRUE,FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ���� ������ ����
	if (Obstacle->Boss.attack == 1) { DrawRotaGraph(Obstacle->Boss.x-34, Obstacle->Boss.y+53, 2, 0, info->Point, TRUE, FALSE); } //���� ���ؼ��Դϴ�. �߰������� �������� ��Ÿ���ϴ�.
	
	DrawRotaGraph(Obstacle->Sub_boss.x, Obstacle->Sub_boss.y, (float)1/4, 0, Obstacle->Sub_boss.image, TRUE, FALSE);
	DrawRotaGraph(Obstacle->Sub_boss.x, Obstacle->Sub_boss.y, (float)1.6, 0, Obstacle->Sub_boss.shield, TRUE, FALSE);
	DrawFormatString(100, 400, col_bullet, "���� �Ѿ� : %d", info->bullet-1);

	for (i = 0; i < 3; i++)
		DrawRotaGraph(Obstacle->Switch[i].x, Obstacle->Switch[i].y, 1, 0, Obstacle->Switch[i].image, TRUE, FALSE);
	if (Obstacle->Boss.hp > 0){
		DrawFormatString(50, 20, col_Boss, "HP : %.0lf", Obstacle->Boss.hp);
	}
	else{
		DrawFormatString(50, 20, col_Boss, "���");
	}
	if (Obstacle->Sub_boss.hp>0)
		DrawFormatString(50, 40, col_SubBoss, "HP : %.0lf", Obstacle->Sub_boss.hp);
	else{
		DrawFormatString(50, 40, col_SubBoss, "���");
	}
	return 0;
}

int UpdateKey() // Ű�� ������ �Էµ��� ���ϵ��� ���ݴϴ�.
{
	char tmpKey[256]; //������ Ű �Է� ���¸� �����մϴ�.
	GetHitKeyStateAll(tmpKey); // ��� Ű�� �Է� ���¸� �����մϴ�.

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


int selectPower(State *character, int arrow, obstacles *Obstacle, Game *info){ // ó�� �ӵ��� �����ϴ� �Լ��Դϴ�.

	while (CheckHitKey(KEY_INPUT_SPACE) != 1){
		ProcessMessage();
		ClearDrawScreen();

		Stage_Screen(Obstacle,info);

		DrawRotaGraph(character->x, character->y, (float)1/3, 0, character->student, TRUE, FALSE); //�̹����� ���
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
		
		if (UpdateKey() != 0) // ������ ����
			return 0;
	
	}
	
	if (setV(character) != 0)
		return 0;

	return 0;
}

int distance(State *character, int a, int b){
	return (int)sqrt(pow((double)character->x - a,2) + pow((double)character->y - b,2));
}

int collision(State *character, obstacles *Obstacle){ //�浹 �Լ��Դϴ�. �浹�� �ȴٸ� 1�� ��ȯ�մϴ�.
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

			if (Obstacle->Sub_boss.hp <= 0){// �߰������� ������ ���� �� ������ �׷��� �ʴٸ� �����Դϴ�.
				Obstacle->Boss.attack = 1;
				Obstacle->Sub_boss.image = 0;
				PlaySoundMem(Obstacle->Sub_boss.sound, DX_PLAYTYPE_BACK); // �߰� ������ ���� �� ����� �����ϴ�.
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
	for (i = 0; i < 3; i++) // ����ġ�� ���� �� ���̾����� ������, ���������� ������ �ٲ�ϴ�.
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

			if (Obstacle->Switch[0].off == 1 && Obstacle->Switch[1].off == 1 && Obstacle->Switch[2].off == 1){ // ����ġ�� ��� ���������� �������� ���� �� ������, ��� �������� ������ ������ �˴ϴ�.
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

int flying(State *character, obstacles *Obstacle, Game *info){ // ���������� ���ư� �� �ֵ��� ���ݴϴ�.
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
			if (Obstacle->Boss.hp <= 0){ // ������ ����� ���� �� �ֵ��� �մϴ�.
				PlaySoundMem(Obstacle->Boss.sound, DX_PLAYTYPE_NORMAL);
			}
		}

		ScreenFlip();

	}

	if (Obstacle->Boss.hp<=0) // ������ ����� �� ������ Ŭ���� �� �� �ֵ��� �մϴ�.
		info->clear = 1;

	return 0;
}



int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	// â ���� ����
	if (ChangeWindowMode(TRUE) != 0)
		return 0;

	if (DxLib_Init() != 0)
		return 0;// DX���̺귯�� �ʱ�ȭ

	SetDrawScreen(DX_SCREEN_BACK); // ��ȭó���� ����ǥ������ ����

 // �й������� �ٽ� �������� �ɴϴ�.
replay: //���� ����(�й�) �� Y�� ������ ���ʺ��� �ٽ� �����մϴ�.

	State character;
	obstacles Obstacle;
	Game info = { 31, 0, LoadGraph("Image/etc/background.png"), LoadGraph("image/etc/point.png") };

	int arrow;
	// �̹������� �ҷ��ɴϴ�.
	int clear = LoadGraph("Image/etc/clear.png");
	int gameover = LoadGraph("Image/etc/gameover.png");

	//�Ҹ����� �ҷ��ɴϴ�.
	int clear_sound = LoadSoundMem("sound/clear.MP3");
	int BackgroundSound = LoadSoundMem("sound/background.WAV"); // ��������Դϴ�.
	int jump = LoadSoundMem("sound/jump.WAV");
	int gameover_sound = LoadSoundMem("sound/gameover.WAV");

	arrow = LoadGraph("Image/etc/arrow.png"); // ȭ��ǥ �ε�

	Obstacle.Boss = { 600, 250, LoadGraph("Image/character/boss.png", TRUE), 700, 20, 0, LoadSoundMem("sound/scream_boss.MP3"),LoadSoundMem("sound/HitBoss.MP3"),LoadSoundMem("sound/invisible.MP3"),LoadSoundMem("sound/showup.MP3")}; // ��ֹ����� �ʱⰪ ����
	
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

		ScreenFlip(); // ����ǥ��� ���� ǥ���� �ڹٲ�.

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
		while (1){ //Y�� ������ ó������ �ٽ� �����ϰ�, N�� ������ �����մϴ�.
			ProcessMessage();
			if (CheckHitKey(KEY_INPUT_Y) == 1)
				goto replay;  // 
			if (CheckHitKey(KEY_INPUT_N) == 1)
				break;
		}
	}
	WaitKey();
    DxLib_End();    // DX���̺�� ����
    return 0;
}