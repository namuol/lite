// TODO: DOCUMENTATION
// The base class of all games.
// The main task of the App class is to handle the drawing
//  and updating of all items in the game; framerate control
//  logic all occurs here.

#ifndef _APP_H_
#define _APP_H_

#include <list>
using std::list;

#include "ITextureLib.h"

namespace lite
{
    class IDrawTarget;
    class ITimer;
    class IInputManager;
    class IUpdateable;
    class IDrawable;

    class App {
        
        public:
        App(IDrawTarget* drawTarget,
            ITimer* timer,
            IInputManager* input, 
            bool fixedTimestep=true, int targetFPS=60);

        virtual ~App();

        virtual void init();

        void run();
        
        void add_updateable(IUpdateable* updateable);
        void rem_updateable(IUpdateable* updateable);
        void sort_updateables();
        
        IDrawTarget* drawTarget() const;
        const ITimer* timer() const;
        const IInputManager* input() const;

        virtual void update(int dt);
        void quit();

        protected:

        list<IUpdateable *> updateables;

        bool running; // Set to false when we want to exit. TODO: consider using an event system.

        virtual void deinit(); 

        IDrawTarget* _drawTarget;

        ITimer* _timer;

        IInputManager* _input;

        bool fixedTimestep;

        private:
         
        // Variables used for fixed-timestep running:
        int lastFrameTime;
        int cyclesLeftOver;
        int maxCyclesPerFrame;
        int updateInterval;

        // Update at a fixed rate, but maintain a variable framerate:
        void run_fixed_timestep();

        // Update once per frame:
        void run_variable_timestep();
    };

} // namespace lite
#endif
