#ifndef SCREEN_MUSICPRESENTER_HPP
#define SCREEN_MUSICPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_musicView;

class Screen_musicPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_musicPresenter(Screen_musicView& v);

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

    virtual ~Screen_musicPresenter() {};

private:
    Screen_musicPresenter();

    Screen_musicView& view;
};

#endif // SCREEN_MUSICPRESENTER_HPP
