#ifndef SCREEN_LIVING_ROOMVIEW_HPP
#define SCREEN_LIVING_ROOMVIEW_HPP

#include <gui_generated/screen_living_room_screen/Screen_living_roomViewBase.hpp>
#include <gui/screen_living_room_screen/Screen_living_roomPresenter.hpp>

class Screen_living_roomView : public Screen_living_roomViewBase
{
public:
    Screen_living_roomView();
    virtual ~Screen_living_roomView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void Air_Conditioner()override;
    void Lampe()override;
protected:
    bool air_cond, lampe;
};

#endif // SCREEN_LIVING_ROOMVIEW_HPP
