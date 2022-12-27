#include "stdafx.h"

Bullet::Bullet()
{
	gaugespeed = 0.0f;

	missile.SetLocalPos(Vector2(2000.0f, 2000.0f));
	missile.scale.x = 30.0f;
	missile.rotation = 0.0f;
	missile.isVisible = true;

	missilePet.SetParentRT(missile);
	missilePet.SetLocalPos(Vector2(50.0f, 50.0f));
	missilePet.scale = Vector2(10.0f, 10.0f);
	missilePet.rotation = 0.0f;
	missilePet.isAxis = true;
	missilePet.isVisible = false;
}

void Bullet::Update(ObRect player)
{
	if (!missilePet.isVisible) return;
	missile.MoveWorldPos(missile.GetRight() * gaugespeed * 50.0f * DELTA);
	missilePet.revolution += 360.0f * ToRadian * DELTA;

	missile.Update();
	missilePet.Update();

	Vector2 velocity = missile.GetWorldPos() - player.GetWorldPos();
	float dis = velocity.Length();

	if (dis > 2000.0f)
	{
		missilePet.isVisible = false;
	}
}

void Bullet::Render()
{
	if (!missilePet.isVisible) return;
	missile.Render();
	missilePet.Render();
}

bool Bullet::Shoot(ObRect player, ObRect gaugebar)
{
	if (!missilePet.isVisible)
	{
		gaugespeed = gaugebar.scale.x / 10.0f;

		//missile.isVisible = true;
		missilePet.isVisible = true;
		missilePet.revolution = 0.0f;
		missile.rotation = Utility::DirToRadian(player.GetRight());
		missile.SetWorldPos(player.GetWorldPos());

		return true;
	}
	return false;
}
