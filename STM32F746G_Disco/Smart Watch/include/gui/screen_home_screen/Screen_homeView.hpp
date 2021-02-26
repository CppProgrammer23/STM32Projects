#ifndef SCREEN_HOMEVIEW_HPP
#define SCREEN_HOMEVIEW_HPP

#include <gui_generated/screen_home_screen/Screen_homeViewBase.hpp>
#include <gui/screen_home_screen/Screen_homePresenter.hpp>

class Screen_homeView : public Screen_homeViewBase
{
public:
    Screen_homeView();
    virtual ~Screen_homeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SendTimeToView_Home(int hours, int minutes, int seconds);
    void SendWifiInfo(int wifi_activ);
protected:
};

#endif // SCREEN_HOMEVIEW_HPP
