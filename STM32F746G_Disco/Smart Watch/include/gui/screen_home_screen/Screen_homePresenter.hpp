#ifndef SCREEN_HOMEPRESENTER_HPP
#define SCREEN_HOMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_homeView;

class Screen_homePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_homePresenter(Screen_homeView& v);

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

    virtual ~Screen_homePresenter() {};

    void SendTimeToPres(int hours, int minutes, int seconds)override;

    void SendInfoWifiToPresenter(int wifi_activ)override;

private:
    Screen_homePresenter();

    Screen_homeView& view;
};

#endif // SCREEN_HOMEPRESENTER_HPP
