#ifndef SCREEN_SETTINGSVIEW_HPP
#define SCREEN_SETTINGSVIEW_HPP

#include <gui_generated/screen_settings_screen/Screen_settingsViewBase.hpp>
#include <gui/screen_settings_screen/Screen_settingsPresenter.hpp>

class Screen_settingsView : public Screen_settingsViewBase
{
public:
    Screen_settingsView();
    virtual ~Screen_settingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void Activ_Dactiv_Wifi()override;
    void SetToggleButtonWifi(int wifi_activ);
    void Show_List_Wifi()override;
    void SendTimeToViewSettings(int hours, int minutes);
    void Set_Time()override;
    void Set_Format()override;
    void Dactivate_background(void);
    void handleTickEvent()override;
protected:
    CustomContainer_time& CCT =customContainer_time1 ;
};

#endif // SCREEN_SETTINGSVIEW_HPP
