#ifndef SCREEN_WEATHERPRESENTER_HPP
#define SCREEN_WEATHERPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_weatherView;

class Screen_weatherPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_weatherPresenter(Screen_weatherView& v);

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

    virtual ~Screen_weatherPresenter() {};

private:
    Screen_weatherPresenter();

    Screen_weatherView& view;
};

#endif // SCREEN_WEATHERPRESENTER_HPP
