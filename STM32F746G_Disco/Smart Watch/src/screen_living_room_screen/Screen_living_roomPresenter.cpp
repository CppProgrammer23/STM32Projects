#include <gui/screen_living_room_screen/Screen_living_roomView.hpp>
#include <gui/screen_living_room_screen/Screen_living_roomPresenter.hpp>

Screen_living_roomPresenter::Screen_living_roomPresenter(Screen_living_roomView& v)
    : view(v)
{

}

void Screen_living_roomPresenter::activate()
{

}

void Screen_living_roomPresenter::deactivate()
{

}
void Screen_living_roomPresenter::SendInfoAirConditioner(bool air_cond)
{
    model->SendAirConditionerValueToModel(air_cond);
}
void Screen_living_roomPresenter::SendInfoLampe(bool lampe)
{
    model->SendLampeValueToModel(lampe);
}
