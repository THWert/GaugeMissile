#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
    player.SetWorldPos(Vector2(0.0f, 0.0f));
    player.scale = Vector2(80.0f, 80.0f);
    player.rotation = 0.0f;
    player.isAxis = true;
    player.isFilled = true;
    player.isVisible = true;
    player.color = Color(4.0f / 255.0f, 176.0f / 255.0f, 153.0f / 255.0f, 1.0f);
    //player.pivot = OFFSET_L;

    pet.SetParentRT(player);
    pet.SetLocalPos(Vector2(100.0f, 100.0f));
    pet.scale = Vector2(30.0f, 30.0f);
    pet.rotation = 0.0f;
    pet.isAxis = true;

    gaugeBar.SetParentT(player);
    gaugeBar.pivot = OFFSET_L;
    gaugeBar.SetLocalPos(Vector2(-70.0f, 80.0f));
    gaugeBar.scale = Vector2(150.0f, 25.0f);
    gaugeBar.color = Color(113.0f / 255.0f, 79.0f / 255.0f, 209.0f / 255.0f, 1.0f);
}

void Main::Release()
{
}

void Main::Update()
{
    ImGui::ColorEdit3("Color", (float*)&gaugeBar.color, ImGuiColorEditFlags_PickerHueWheel);

    if (INPUT->KeyPress(VK_UP))
    {
        player.MoveWorldPos(player.GetRight() * 200.0f * DELTA);
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        player.MoveWorldPos(-player.GetRight() * 200.0f * DELTA);
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        player.rotation += 120.0f * ToRadian * DELTA;
    }
    if (INPUT->KeyPress(VK_RIGHT))
    {
        player.rotation -= 120.0f * ToRadian * DELTA;
    }

    /*if (INPUT->KeyDown('R'))
    {
        isFired = false;
        missile.SetWorldPos(Vector2(2000.0f, 2000.0f));
    }*/

    if (INPUT->KeyDown(VK_SPACE))
    {
        gaugeBar.scale.x = 0.0f;
    }

    if (INPUT->KeyPress(VK_SPACE))
    {
        gaugeBar.scale.x += 150.0f * DELTA;

        if (gaugeBar.scale.x > 150.0f)
        {
            gaugeBar.scale.x = 150.0f;
        }
    }

    //발사해라
    if (INPUT->KeyUp(VK_SPACE))
    {
        for (int i = 0; i < BMAX; i++)
        {
            if(bullet[i].Shoot(player, gaugeBar)) break;
        }       
    }

    pet.revolution += 30.0f * ToRadian * DELTA;

    player.Update();
    pet.Update();
    gaugeBar.Update();
    for (int i = 0; i < BMAX; i++)
    {
        bullet[i].Update(player);
    }
}

void Main::LateUpdate()
{
}

void Main::Render()
{
    player.Render();
    pet.Render();
    gaugeBar.Render();
    for (int i = 0; i < BMAX; i++)
    {
        bullet[i].Render();
    }
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1400, 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}