#pragma once

#include <handle/HandleDef.h>
#include "View.h"

namespace UI
{
    class Console;
    class ConsoleBox : public View
    {
    public:
        ConsoleBox(Engine::BaseEngine& e, Console& console);
        ~ConsoleBox();

        /**
         * Updates/draws the UI-Views
         * @param dt time since last frame
         * @param mstate mouse-state
         */
        void update(double dt, Engine::Input::MouseState &mstate, Render::RenderConfig &config) override;

        /**
         * Increases the selection index by the given amount.
         * performs periodic wrap around
         * @param amount may be positive or negative
         */
        void increaseSelectionIndex(int amount);

        /**
         * sets the current selection index
         */
        void setSelectionIndex(int newIndex);

        int getSelectionIndex() const { return m_CurrentlySelected;}

    protected:

        struct
        {
            /**
             * Lines of history + current line
             */
            int height;
        } m_Config;

        Console& m_Console;

        /**
         * Console background image
         */
        Handle::TextureHandle m_BackgroundTexture;

        /**
         * Suggestions background image
         */
        Handle::TextureHandle m_SuggestionsBackgroundTexture;

        /**
         * Index of selected entry
         */
        int m_CurrentlySelected;
    };
}
