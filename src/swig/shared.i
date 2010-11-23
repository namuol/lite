%module(directors="1") lite

%{
#include "../../math/Rect.h"

#include "../../core/base/IUpdateable.h"
#include "../../core/base/App.h"
#include "../../core/base/Button.h"
#include "../../core/base/IDrawable.h"
#include "../../core/base/IDrawTarget.h"
#include "../../core/base/IInputManager.h"
#include "../../core/base/IDataLib.h"
#include "../../core/base/ITexture.h"
#include "../../core/base/ITextureLib.h"
#include "../../core/base/ITimer.h"
#include "../../core/base/Key.h"
#include "../../core/base/Sprite.h"
#include "../../core/base/TextureSheet.h"
#include "../../core/base/TextureGrid.h"
#include "../../core/base/types.h"
#include "../../core/base/Color.h"

#include "../../core/sfml/SFMLApp.h"
#include "../../core/sfml/SFMLDrawTarget.h"
#include "../../core/sfml/SFMLInputManager.h"
#include "../../core/sfml/SFMLTexture.h"
#include "../../core/sfml/SFMLTextureLib.h"
#include "../../core/sfml/SFMLTimer.h"

#include "../../math/Vector2.h"

#include "../../tile/Camera.h"
#include "../../tile/Edge.h"
#include "../../tile/Tile.h"
#include "../../tile/ITileMap.h"
#include "../../tile/TileMap.h"
#include "../../tile/TileMapLayer.h"
#include "../../tile/EdgeMap.h"

#include "../../core/base/TextString.h"
%}


%include "std_list.i"
%include "std_map.i"
%include "std_string.i"
%include "std_vector.i"

%include "../../core/base/IDataLib.h"
%include "../../core/base/ITexture.h"
%template(IDataLibTexture) lite::IDataLib<lite::ITexture>;
%include "../../core/base/ITextureLib.h"

%include "../../math/Rect.h"
%include "../../core/base/Color.h"

%include "../../core/base/IUpdateable.h"
%include "../../core/base/App.h"
%include "../../core/base/Button.h"

%feature("director") IDrawable;
%include "../../core/base/IDrawable.h"

%include "../../core/base/IDrawTarget.h"
%include "../../core/base/IInputManager.h"


%include "../../core/base/ITimer.h"
%include "../../core/base/Key.h"

%feature("director") Sprite;
%include "../../core/base/Sprite.h"

%include "../../core/base/TextureSheet.h"
%include "../../core/base/TextureGrid.h"
%include "../../core/base/types.h"

%feature("director") SFMLApp;
%include "../../core/sfml/SFMLApp.h"

%feature("notabstract") SFMLDrawTarget;
%include "../../core/sfml/SFMLDrawTarget.h"
%include "../../core/sfml/SFMLInputManager.h"
%include "../../core/sfml/SFMLTexture.h"
%include "../../core/sfml/SFMLTextureLib.h"
%include "../../core/sfml/SFMLTimer.h"

%include "../../math/Vector2.h"

%include "../../tile/Camera.h"
%include "../../tile/Edge.h"
%include "../../tile/Tile.h"
%include "../../tile/ITileMap.h"
%include "../../tile/TileMap.h"
%include "../../tile/TileMapLayer.h"
%include "../../tile/EdgeMap.h"

%template(TileTexArray) std::vector<const lite::ITexture*>;

%feature("director") TextString;
%include "../../core/base/TextString.h"
