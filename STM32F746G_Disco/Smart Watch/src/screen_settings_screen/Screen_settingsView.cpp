#include <gui/screen_settings_screen/Screen_settingsView.hpp>
//#include <gui/containers/CustomContainer_time.hpp>

Screen_settingsView::Screen_settingsView()
{
    
}

void Screen_settingsView::setupScreen()
{
    Screen_settingsViewBase::setupScreen();
}

void Screen_settingsView::tearDownScreen()
{
    Screen_settingsViewBase::tearDownScreen();
}

void Screen_settingsView::Activ_Dactiv_Wifi()
{
    static bool wifi;
    static int activate_wifi;
    if (wifi == 0)
    {
        activate_wifi = 1;
        wifi = 1;
        customContainer_wifi_list1.setVisible(true);
        customContainer_wifi_list1.invalidate();
    }
    else
    {
        activate_wifi = 0;
        wifi = 0;
    }
    presenter->SendInfoWifiSettingsScreen(activate_wifi);
}
void Screen_settingsView::SetToggleButtonWifi(int wifi_activ)
{
    if (wifi_activ == 1)
    {
        toggleButton_wifi.forceState(true);
        button1.setVisible(true);
        button1.invalidate();
    }
    else
    {
        toggleButton_wifi.forceState(false);
        button1.setVisible(false);
        button1.invalidate();
    }
    Dactivate_background();
}

void Screen_settingsView::Show_List_Wifi()
{
    customContainer_wifi_list1.setVisible(true);
    customContainer_wifi_list1.invalidate();
    Dactivate_background();
}

void Screen_settingsView::SendTimeToViewSettings(int hours, int minutes)
{
    Unicode::snprintf(flexButton_change_timeBuffer1, FLEXBUTTON_CHANGE_TIMEBUFFER1_SIZE, "%d", hours);
    Unicode:: snprintf(flexButton_change_timeBuffer2, FLEXBUTTON_CHANGE_TIMEBUFFER2_SIZE, "%d", minutes);
    flexButton_change_time.invalidate();
    if(customContainer_time1.isVisible()==0)
        CCT.TimeToContainer(hours, minutes);
}

void Screen_settingsView::Set_Time() 
{
    customContainer_time1.setVisible(true);
    customContainer_time1.invalidate();
    Dactivate_background();

}
void Screen_settingsView::Set_Format()
{
    customContainer_set_time_format1.setVisible(true);
    customContainer_set_time_format1.invalidate();
    Dactivate_background();
}
void Screen_settingsView::Dactivate_background()
{
        toggleButton_wifi.setVisible(false);
        flexButton_change_format.setVisible(false);
        flexButton_change_time.setVisible(false);
}

void Screen_settingsView::handleTickEvent()
{
    if (customContainer_set_time_format1.isVisible() == 0 && customContainer_time1.isVisible() == 0 && customContainer_wifi_list1.isVisible()==0)
    {
        if (toggleButton_wifi.isVisible() == 0 && flexButton_change_format.isVisible() == 0 && flexButton_change_time.isVisible() == 0)
        {
            toggleButton_wifi.setVisible(true);
            toggleButton_wifi.invalidate();
            flexButton_change_format.setVisible(true);
            flexButton_change_format.invalidate();
            flexButton_change_time.setVisible(true);
            flexButton_change_time.invalidate();
        }
    }
}
