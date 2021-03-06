#pragma once
#include "Game.h"
#include "BrickBreaker.h"
#include "BrickBreakerCoop.h"
#include "BrickBreakerVs.h"
#include "Pong.h"
#include "PongMP.h"
#include "Button.h"
#include "InfoWindow.h"
#include "Statistics.h"
#include <vector>
#include <SDL_ttf.h>

namespace BallFramework
{

	class Menu : public Game
	{
	public:
		Menu(int16_t width, uint16_t height, uint32_t flags = 0, uint16_t maxFPS = 0);

		void Start() override;
		void OnClose() override;
		void CheckCollision() override;
		void Update() override;

		void KeyPressed(const SDL_Keycode& key) override;
		void KeyReleased(const SDL_Keycode& key) override;

		void MousePressed(const SDL_MouseButtonEvent& mouse) override;
		void MouseReleased(const SDL_MouseButtonEvent& mouse) override;

		void Render(SDL_Renderer* renderer) override;

		bool IsInBounds(Sint32 x, Sint32 y);
		void PerformAction();

		std::unique_ptr<InfoWindow> MakeWindow(const uint8_t& type);

		void DestroyButtons();

	private:
		void InitButtons();

	private:
		std::vector<Button> m_buttons;
		Button* m_lastButton;
	};

}