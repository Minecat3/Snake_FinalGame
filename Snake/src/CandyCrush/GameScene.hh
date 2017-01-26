/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#pragma once
#include "Grid.hh"
#include "Scene.hh"

// GameScene class with the main gameplay mode
class GameSceneMenu : public Scene {
public:
	explicit GameSceneMenu();
	~GameSceneMenu() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Grid m_grid;
	Sprite m_background;
	Sprite m_Image;
	int m_score{ 0 };
};

class GameSceneDiff : public Scene {
public:
	explicit GameSceneDiff();
	~GameSceneDiff() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Grid m_grid;
	Sprite m_background;
	Sprite m_Image;
	int m_score{ 0 };
};

class GameSceneEasy : public Scene {
public:
	explicit GameSceneEasy();
	~GameSceneEasy() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Grid m_grid;
	Sprite m_background;
	Sprite m_Image;
	int m_score{ 0 };
};