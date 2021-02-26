#ifndef SCREEN_LIVING_ROOMPRESENTER_HPP
#define SCREEN_LIVING_ROOMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_living_roomView;

class Screen_living_roomPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_living_roomPresenter(Screen_living_roomView& v);

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

    virtual ~Screen_living_roomPresenter() {};

    void SendInfoAirConditioner(bool air_cond);

    void SendInfoLampe(bool lampe);

private:
    Screen_living_roomPresenter();

    Screen_living_roomView& view;
};

#endif // SCREEN_LIVING_ROOMPRESENTER_HPP
