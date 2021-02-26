#ifndef SCREEN_WEATHERVIEW_HPP
#define SCREEN_WEATHERVIEW_HPP

#include <gui_generated/screen_weather_screen/Screen_weatherViewBase.hpp>
#include <gui/screen_weather_screen/Screen_weatherPresenter.hpp>

class Screen_weatherView : public Screen_weatherViewBase
{
public:
    Screen_weatherView();
    virtual ~Screen_weatherView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_WEATHERVIEW_HPP
