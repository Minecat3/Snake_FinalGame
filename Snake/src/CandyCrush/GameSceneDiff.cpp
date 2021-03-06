/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "GameScene.hh"
using namespace Logger;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80



GameSceneDiff::GameSceneDiff(void){

	//Image loads
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_00 };
	m_Image = { { W.GetWidth() / 2 - 180, W.GetHeight() / 2 - 45,90,90 }, ObjectID::ARROW };
}

GameSceneDiff::~GameSceneDiff(void) {
}

void GameSceneDiff::OnEntry(void) {
}

void GameSceneDiff::OnExit(void) {
}

void GameSceneDiff::Update(void) {
	
	//If's for the arrow position
	if (m_Image.transform.y == W.GetHeight() / 2 - 45) {
		m_Image.transform.x = W.GetWidth() / 2 - 250;

	}
	else { m_Image.transform.x = W.GetWidth() / 2 - 180; }

	//Arrow position depending on the player's key feedback
	if (IM.IsKeyDown<KEY_BUTTON_UP>() && m_Image.transform.y != W.GetHeight() / 2 - 120) { m_Image.transform.y -= 75; }
	else if (IM.IsKeyDown<KEY_BUTTON_DOWN>() && m_Image.transform.y != W.GetHeight() / 2 + 30) { m_Image.transform.y += 75; }
	else if (IM.IsKeyDown<KEY_BUTTON_ENTER>()) {
		if (m_Image.transform.y == W.GetHeight() / 2 + 30) {
			SM.SetCurScene<GameSceneHard>(); // Enter hard game
		}
		else if (m_Image.transform.y == W.GetHeight() / 2 - 45) {
			SM.SetCurScene<GameSceneMedium>();	//Enter medium game
		}
		else if (m_Image.transform.y == W.GetHeight() / 2 - 120) {
			SM.SetCurScene<GameSceneEasy>();//Enter easy game
		}
	}

}

void GameSceneDiff::Draw(void) {

	//Images and background draw
	m_background.Draw();
	m_Image.Draw();
	
	//Draw of the difficulty selection scene text's
	GUI::DrawTextSolid<FontID::FACTORY>("-SNAKE-", { W.GetWidth() >> 1, int(W.GetHeight()*.1f),1, 1 }, { 0, 0, 0 });
	GUI::DrawTextSolid<FontID::FACTORY>("EASY", { W.GetWidth() >> 1, int(W.GetHeight()*.4f), 1, 1 }, { 0, 0, 0 });
	GUI::DrawTextSolid<FontID::FACTORY>("MEDIUM", { W.GetWidth() >> 1, int(W.GetHeight()*.5f), 1, 1 }, { 0, 0, 0 });
	GUI::DrawTextSolid<FontID::FACTORY>("HARD", { W.GetWidth() >> 1, int(W.GetHeight()*.6f), 1, 1 }, { 0, 0, 0 });

}

