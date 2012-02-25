// TODO: DOCUMENTATION
// An interface for anything in the game that can be updated.

#ifndef _IUPDATEABLE_H_
#define _IUPDATEABLE_H_

namespace lite
{
    class App;

    class IUpdateable
    {
        public:
        IUpdateable();
        IUpdateable(App* app);

        ~IUpdateable();

        virtual void update(int dt) = 0;
        
		// TODO: Figure out why swig doesn't like this to be virtual.
		//  I can live with it being non-virtual for now.
        float updateOrder() const; 

        void updateOrder(float val);
        
        protected:
        App* app;
        
        private:
        float _updateOrder;
    };
} // namespace lite

#endif
