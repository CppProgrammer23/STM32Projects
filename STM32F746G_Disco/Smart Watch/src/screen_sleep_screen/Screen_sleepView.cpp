#include <gui/screen_sleep_screen/Screen_sleepView.hpp>

Screen_sleepView::Screen_sleepView()
{

}

void Screen_sleepView::setupScreen()
{
    Screen_sleepViewBase::setupScreen();
}

void Screen_sleepView::tearDownScreen()
{
    Screen_sleepViewBase::tearDownScreen();
}

void Screen_sleepView::SentTimeToSleepScreen(int hours,int minutes,int seconds)
{
    analogClock1.setTime24Hour(hours, minutes, seconds);
    analogClock1.invalidate();
}

void Screen_sleepView::SendAlphaToSleepS(int alpha)
{
    flexButton1.setAlpha(alpha);
    flexButton1.invalidate();
}
