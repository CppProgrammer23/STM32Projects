#ifndef SCREEN_AGENDAPRESENTER_HPP
#define SCREEN_AGENDAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen_agendaView;

class Screen_agendaPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen_agendaPresenter(Screen_agendaView& v);

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

    virtual ~Screen_agendaPresenter() {};

private:
    Screen_agendaPresenter();

    Screen_agendaView& view;
};

#endif // SCREEN_AGENDAPRESENTER_HPP
