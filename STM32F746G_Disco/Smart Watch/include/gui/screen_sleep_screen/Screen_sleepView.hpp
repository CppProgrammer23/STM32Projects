#ifndef SCREEN_SLEEPVIEW_HPP
#define SCREEN_SLEEPVIEW_HPP

#include <gui_generated/screen_sleep_screen/Screen_sleepViewBase.hpp>
#include <gui/screen_sleep_screen/Screen_sleepPresenter.hpp>

class Screen_sleepView : public Screen_sleepViewBase
{
public:
    Screen_sleepView();
    virtual ~Screen_sleepView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SentTimeToSleepScreen(int hours, int minutes, int seconds);
    void SendAlphaToSleepS(int alpha);
protected:
};

#endif // SCREEN_SLEEPVIEW_HPP
