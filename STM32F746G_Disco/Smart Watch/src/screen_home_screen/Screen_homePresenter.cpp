#include <gui/screen_home_screen/Screen_homeView.hpp>
#include <gui/screen_home_screen/Screen_homePresenter.hpp>

Screen_homePresenter::Screen_homePresenter(Screen_homeView& v)
    : view(v)
{

}

void Screen_homePresenter::activate()
{

}

void Screen_homePresenter::deactivate()
{

}

void Screen_homePresenter::SendTimeToPres(int hours, int minutes, int seconds)
{
    view.SendTimeToView_Home(hours, minutes, seconds);
}

void Screen_homePresenter::SendInfoWifiToPresenter(int wifi_activ)
{
    view.SendWifiInfo(wifi_activ);
}
