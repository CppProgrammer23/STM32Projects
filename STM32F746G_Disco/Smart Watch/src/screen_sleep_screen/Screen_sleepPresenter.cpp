#include <gui/screen_sleep_screen/Screen_sleepView.hpp>
#include <gui/screen_sleep_screen/Screen_sleepPresenter.hpp>

Screen_sleepPresenter::Screen_sleepPresenter(Screen_sleepView& v)
    : view(v)
{

}

void Screen_sleepPresenter::activate()
{

}

void Screen_sleepPresenter::deactivate()
{

}

void Screen_sleepPresenter::SendTimeToPres(int hours, int minutes, int seconds)
{
    view.SentTimeToSleepScreen(hours, minutes, seconds);
}

void Screen_sleepPresenter::SendAlphaToSleepScreen(int alpha)
{
    view.SendAlphaToSleepS(alpha);
}