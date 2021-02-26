#ifndef SCREEN_GAMEVIEW_HPP
#define SCREEN_GAMEVIEW_HPP

#include <gui_generated/screen_game_screen/Screen_gameViewBase.hpp>
#include <gui/screen_game_screen/Screen_gamePresenter.hpp>

class Screen_gameView : public Screen_gameViewBase
{
public:
    Screen_gameView();
    virtual ~Screen_gameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent()override;
    void Open_Option()override;
    void SendValuesToGameView(bool);

protected:
    static bool state ;
};

#endif // SCREEN_GAMEVIEW_HPP
