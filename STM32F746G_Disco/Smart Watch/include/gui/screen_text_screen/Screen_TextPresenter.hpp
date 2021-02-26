#ifndef SCREEN_TEXTPRESENTER_HPP
#define SCREEN_TEXTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_TextView;

class Screen_TextPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_TextPresenter(Screen_TextView& v);

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

    virtual ~Screen_TextPresenter() {};

private:
    Screen_TextPresenter();

    Screen_TextView& view;
};

#endif // SCREEN_TEXTPRESENTER_HPP
