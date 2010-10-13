#include "App.h"
#include "ITimer.h"
#include "IDrawTarget.h"
#include "IInputManager.h"

#include "IUpdateable.h"
#include "IDrawable.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//#define _DEBUG

namespace lite
{
    static bool compare_updateorder(IUpdateable* first, IUpdateable* second)
    {
        return first->get_updateorder() < second->get_updateorder();
    }

    // Public methods:
    App::App(IDrawTarget* drawTarget,
             ITimer* timer,
             IInputManager* input,
             bool fixedTimestep, int targetFPS):
        _drawTarget(drawTarget),
        _timer(timer),
        _input(input),
        fixedTimestep(fixedTimestep)
    {
        updateInterval = 1000/targetFPS;
        maxCyclesPerFrame = 8; // TODO: define this properly...
        lastFrameTime = 0;
        cyclesLeftOver = 0;
    }

    App::~App()
    {
    }

    void App::init()
    {
        _drawTarget->init();
        _timer->init();
        _timer->calc_precision(100);
        _input->init();
    }

    void App::run()
    {
        running = true;

        if(fixedTimestep)
            run_fixed_timestep();
        else
            run_variable_timestep();

        deinit(); // TODO: should this be here?
    }

    void App::add_updateable(IUpdateable* updateable)
    {
        updateables.push_back(updateable); 
        updateables.sort(compare_updateorder);
    }

    void App::rem_updateable(IUpdateable* updateable)
    {
        updateables.remove(updateable);
    }

    void App::sort_updateables()
    {
        updateables.sort(compare_updateorder);
    }

    IDrawTarget* App::drawTarget() const
    {
        return _drawTarget;
    }

    const ITimer* App::timer() const
    {
        return _timer;
    }

    const IInputManager* App::input() const
    {
        return _input;
    }

    // Protected methods:
    void App::update(int dt)
    {
        _timer->tick();
        _input->update(dt);
        for( list<IUpdateable *>::iterator u = updateables.begin(); u != updateables.end(); ++u ) {
            (*u)->update(dt);
        }
    }

    void App::deinit()
    {
        _input->deinit();
        _timer->deinit();
        _drawTarget->deinit();
    }

    // Private methods:
    
    void App::run_fixed_timestep()
    {
        while( running )
        {
            int currentTime;
            int updateIterations;
            int dt;

            currentTime = _timer->get_time();
            dt = (currentTime - lastFrameTime);
            updateIterations = (dt + cyclesLeftOver);

            if (updateIterations > (maxCyclesPerFrame * updateInterval)) {
                updateIterations = (maxCyclesPerFrame * updateInterval);
            }

            while (updateIterations > updateInterval) {
                updateIterations -= updateInterval;

                update(dt);
            }

            cyclesLeftOver = updateIterations;
            lastFrameTime = currentTime;

            _drawTarget->draw(dt);

            int leftoverTime = updateInterval - (_timer->get_time() - lastFrameTime);
            // If we have more than 1 update interval worth of time left still,
            //  wait it out to save CPU cycles.
            if( leftoverTime > _timer->precision() )
            {
                _timer->wait(leftoverTime - (leftoverTime % _timer->precision()));
            }

            while( leftoverTime > 0 )
            {
                leftoverTime = updateInterval - (_timer->get_time() - lastFrameTime);
            }
        }
    }

    void App::run_variable_timestep()
    {
        // TODO!
        cerr << "Variable timestep not implemented yet!" << endl;
        exit(-1);
    }
} // namespace lite
