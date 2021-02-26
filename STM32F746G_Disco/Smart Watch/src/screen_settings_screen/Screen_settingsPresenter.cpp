#include <gui/screen_settings_screen/Screen_settingsView.hpp>
#include <gui/screen_settings_screen/Screen_settingsPresenter.hpp>

Screen_settingsPresenter::Screen_settingsPresenter(Screen_settingsView& v)
    : view(v)
{

}

void Screen_settingsPresenter::activate()
{

}

void Screen_settingsPresenter::deactivate()
{

}
void Screen_settingsPresenter::SendInfoWifiSettingsScreen(int activate_wifi)
{
    model->SendInfoWifiModelScreenSettings(activate_wifi);
}
void Screen_settingsPresenter::SendInfoWifiToPresenter(int wifi_activ)
{
    view.SetToggleButtonWifi(wifi_activ);
}

void Screen_settingsPresenter::SendTimeToPres(int hours, int minutes, int seconds)
{
    view.SendTimeToViewSettings(hours, minutes);
}
