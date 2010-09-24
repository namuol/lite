// TODO: DOCUMENTATION
// A collection of SDL_Surface* textures.

#ifndef _ITEXTURELIB_H_
#define _ITEXTURELIB_H_

#include <map>
#include <string>
using std::map;
using std::string;

namespace fix
{
    class ITexture;

    class ITextureLib
    {
        public:
        ITextureLib();
        ITextureLib(const string& path);

        void load_texture(const string& filename);
        void unload_texture(const string& filename);
        void unload_all_textures();
        
        ITexture* operator[] ( const string& filename );

        private:
        string _path;
        map<string, ITexture*> _textures;
    };
} // namespace fix
#endif
