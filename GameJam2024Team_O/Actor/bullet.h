#pragma once

struct Location
{
	float x, y;//�e�̒��S���W
};

struct HitBox
{
	float x1, y1;//�����蔻�荶��̍��W
	float x2, y2;//�����蔻��E���̍��W
};

class bullet
{
public:
	Location l;
	HitBox h;
	float velocity; //�e�e�̈ړ����x

	bullet();
	~bullet();

	void Update();
	void Draw();
};

