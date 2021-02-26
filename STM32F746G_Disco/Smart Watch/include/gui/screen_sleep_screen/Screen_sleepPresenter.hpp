#ifndef SCREEN_SLEEPPRESENTER_HPP
#define SCREEN_SLEEPPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_sleepView;

class Screen_sleepPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_sleepPresenter(Screen_sleepView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen_sleepPresenter() {};

    void SendTimeToPres(int hours, int minutes, int seconds)override;

    void SendAlphaToSleepScreen(int alpha)override;

private:
    Screen_sleepPresenter();

    Screen_sleepView& view;
};

#endif // SCREEN_SLEEPPRESENTER_HPP
