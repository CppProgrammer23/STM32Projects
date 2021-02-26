#ifndef SCREEN_SETTINGSPRESENTER_HPP
#define SCREEN_SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_settingsView;

class Screen_settingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_settingsPresenter(Screen_settingsView& v);

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

    virtual ~Screen_settingsPresenter() {};

    void SendInfoWifiSettingsScreen(int activate_wifi);

    void SendInfoWifiToPresenter(int wifi_activ)override;

    void SendTimeToPres(int hours, int minutes, int seconds)override;

private:
    Screen_settingsPresenter();

    Screen_settingsView& view;
};

#endif // SCREEN_SETTINGSPRESENTER_HPP
