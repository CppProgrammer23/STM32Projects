#ifndef SCREEN_CONTROLVIEW_HPP
#define SCREEN_CONTROLVIEW_HPP

#include <gui_generated/screen_control_screen/Screen_ControlViewBase.hpp>
#include <gui/screen_control_screen/Screen_ControlPresenter.hpp>

class Screen_ControlView : public Screen_ControlViewBase
{
public:
    Screen_ControlView();
    virtual ~Screen_ControlView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_CONTROLVIEW_HPP
