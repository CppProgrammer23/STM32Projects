#include <gui/screen_home_screen/Screen_homeView.hpp>

Screen_homeView::Screen_homeView()
{

}

void Screen_homeView::setupScreen()
{
    Screen_homeViewBase::setupScreen();
}

void Screen_homeView::tearDownScreen()
{
    Screen_homeViewBase::tearDownScreen();
}

void Screen_homeView::SendTimeToView_Home(int hours, int minutes, int seconds)
{
    digitalClock1.setTime12Hour(hours, minutes, seconds,false);
    digitalClock1.invalidate();
}

void Screen_homeView::SendWifiInfo(int wifi_activ)
{
    if (wifi_activ == 1)
    {
        scalableImage1.setVisible(false);
        scalableImage1.invalidate();
        wifi_pic.setVisible(true);
        wifi_pic.invalidate();
    }
    else
    {
        wifi_pic.setVisible(false);
        wifi_pic.invalidate();
        scalableImage1.setVisible(true);
        scalableImage1.invalidate();
    }
}
