#ifndef SCREEN_GAMEPRESENTER_HPP
#define SCREEN_GAMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_gameView;

class Screen_gamePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_gamePresenter(Screen_gameView& v);

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

    virtual ~Screen_gamePresenter() {};

private:
    Screen_gamePresenter();

    Screen_gameView& view;
};

#endif // SCREEN_GAMEPRESENTER_HPP
