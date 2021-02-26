#include <gui/screen_game_screen/Screen_gameView.hpp>

Screen_gameView::Screen_gameView()
{

}

void Screen_gameView::setupScreen()
{
    Screen_gameViewBase::setupScreen();
}

void Screen_gameView::tearDownScreen()
{
    Screen_gameViewBase::tearDownScreen();
}
void Screen_gameView::Open_Option()
{
    customContainer_Option_game1.setVisible(true);
    customContainer_Option_game1.invalidate();
    flexButton_play.setTouchable(false);
    flexButton_option.setTouchable(false);
    flexButton_exit.setTouchable(false);
    state = false;
}
bool Screen_gameView::state;
void Screen_gameView::SendValuesToGameView(bool t)
{
    state = t;
}
void Screen_gameView::handleTickEvent()
{
    if (state == true)
    {
        flexButton_play.setTouchable(true);
        flexButton_play.invalidate();
        flexButton_option.setTouchable(true);
        flexButton_option.invalidate();
        flexButton_exit.setTouchable(true);
        flexButton_exit.invalidate();  
    }
}
