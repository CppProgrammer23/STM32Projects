#include <gui/screen_music_screen/Screen_musicView.hpp>
#include <fstream>
#include <iostream>

Screen_musicView::Screen_musicView()
{

}

void Screen_musicView::setupScreen()
{
    Screen_musicViewBase::setupScreen();
}

void Screen_musicView::tearDownScreen()
{
    Screen_musicViewBase::tearDownScreen();
}

void Screen_musicView::Play_Pause_Music()
{
    button_play.setVisible(false);
    button_play.invalidate();
    button_pause.setVisible(true);
    button_pause.invalidate();
    play = true;
}

void Screen_musicView::Button_Pause_Clicked()
{
    button_pause.setVisible(false);
    button_pause.invalidate();
    button_play.setVisible(true);
    button_play.invalidate();
    play = false;
}

void Screen_musicView::SetButton1(bool x)
{
    if (x == true)
    {
        button1.setVisible(true);
        button1.invalidate();
    }
}

void Screen_musicView::Open_COntainer_Music()
{
    customContainer_Music1.setVisible(true);
    customContainer_Music1.invalidate();
    button1.setVisible(false);
    button1.invalidate();
}

void Screen_musicView::handleTickEvent()
{
    if (customContainer_Music1.isVisible() == false)
    {
        if (button1.isVisible() == false)
        {
            button1.setVisible(true);
            button1.invalidate();
        }
    }
}

