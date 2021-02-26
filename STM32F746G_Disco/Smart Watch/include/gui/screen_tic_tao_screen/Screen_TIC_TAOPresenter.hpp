#ifndef SCREEN_TIC_TAOPRESENTER_HPP
#define SCREEN_TIC_TAOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_TIC_TAOView;

class Screen_TIC_TAOPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_TIC_TAOPresenter(Screen_TIC_TAOView& v);

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

    virtual ~Screen_TIC_TAOPresenter() {};

private:
    Screen_TIC_TAOPresenter();

    Screen_TIC_TAOView& view;
};

#endif // SCREEN_TIC_TAOPRESENTER_HPP
