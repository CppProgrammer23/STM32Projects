#ifndef SCREEN_CONTROLPRESENTER_HPP
#define SCREEN_CONTROLPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_ControlView;

class Screen_ControlPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_ControlPresenter(Screen_ControlView& v);

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

    virtual ~Screen_ControlPresenter() {};

private:
    Screen_ControlPresenter();

    Screen_ControlView& view;
};

#endif // SCREEN_CONTROLPRESENTER_HPP
