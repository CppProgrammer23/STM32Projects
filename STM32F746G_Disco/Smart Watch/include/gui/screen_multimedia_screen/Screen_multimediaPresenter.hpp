#ifndef SCREEN_MULTIMEDIAPRESENTER_HPP
#define SCREEN_MULTIMEDIAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_multimediaView;

class Screen_multimediaPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_multimediaPresenter(Screen_multimediaView& v);

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

    virtual ~Screen_multimediaPresenter() {};

private:
    Screen_multimediaPresenter();

    Screen_multimediaView& view;
};

#endif // SCREEN_MULTIMEDIAPRESENTER_HPP
