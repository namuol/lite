#ifndef _IDATALIB_H_
#define _IDATALIB_H_

#include <map>
using std::map;

#include <string>
using std::string;

#define DIR_SLASH "/"

namespace lite
{
    template <class T>
    class IDataLib
    {
        public:
        IDataLib():
            _path(".")
        {
        }

        IDataLib(const string& path):
            _path(path)
        {
        }
        
        T* load(const string& filename)
        {
            T* item = _load(_path + DIR_SLASH + filename);
            if( item != NULL )
            {
                items[filename] = item;
            }
            return item;
        }

        void unload(const string& filename)
        {
            typename map<string, T*>::iterator i = items.find(filename);

            if( i != items.end() )
            {
                _unload((*i).second);
                items.erase(i);
            }
        }


        T* operator[](const string& filename)
        {
            if( items.find(filename) == items.end() )
            {
                return NULL;
            }
            else
            {
                return items[filename];
            }
        }

        const string& path() const
        {
            return _path;
        }

        void path(const string& val)
        {
            _path = val;
        }

        protected:
        // Pure-virtual load/unload routines must be defined
        //  by inherited class.
        virtual T* _load(const string& full_path) = 0;
        virtual void _unload(T* item) = 0;

        private:
        string _path;
        map<string, T*> items;
    };

} // namespace lite
#endif

