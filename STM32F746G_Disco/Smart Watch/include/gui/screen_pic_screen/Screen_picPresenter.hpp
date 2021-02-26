#ifndef SCREEN_PICPRESENTER_HPP
#define SCREEN_PICPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_picView;

class Screen_picPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_picPresenter(Screen_picView& v);

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

    virtual ~Screen_picPresenter() {};

private:
    Screen_picPresenter();

    Screen_picView& view;
};

#endif // SCREEN_PICPRESENTER_HPP
