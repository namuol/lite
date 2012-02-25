%module(directors=1) lite

%{
#include "../../math/Rect.h"

#include "../../base/IUpdateable.h"
#include "../../base/App.h"
#include "../../base/Button.h"
#include "../../base/IDrawable.h"
#include "../../base/IDrawTarget.h"
#include "../../base/IInputManager.h"
#include "../../base/IDataLib.h"
#include "../../base/ITexture.h"
#include "../../base/ITextureLib.h"
#include "../../base/ITimer.h"
#include "../../base/Key.h"
#include "../../base/Sprite.h"
#include "../../base/TextureSheet.h"
#include "../../base/TextureGrid.h"
#include "../../base/types.h"
#include "../../base/Color.h"

#include "../../impl/sfml/SFMLApp.h"
#include "../../impl/sfml/SFMLDrawTarget.h"
#include "../../impl/sfml/SFMLInputManager.h"
#include "../../impl/sfml/SFMLTexture.h"
#include "../../impl/sfml/SFMLTextureLib.h"
#include "../../impl/sfml/SFMLTimer.h"

#include "../../math/Vector2.h"

#include "../../tile/Camera.h"
#include "../../tile/Edge.h"
#include "../../tile/Tile.h"
#include "../../tile/ITileMap.h"
#include "../../tile/TileMap.h"
#include "../../tile/TileMapLayer.h"
#include "../../tile/EdgeMap.h"
#include "../../tile/World.h"
#include "../../tile/WorldObject.h"
//#include "../../tile/IPhysical.h"
//#include "../../tile/Hotspot.h"

#include "../../base/TextString.h"
%}


%include "std_list.i"
%include "std_map.i"
%include "std_string.i"
%include "std_vector.i"

%include "../../base/IDataLib.h"
%include "../../base/ITexture.h"
%template(IDataLibTexture) lite::IDataLib<lite::ITexture>;
%include "../../base/ITextureLib.h"

%include "../../math/Rect.h"
%include "../../base/Color.h"

%include "../../base/IUpdateable.h"
%include "../../base/App.h"
%include "../../base/Button.h"

%feature("director") IDrawable;
%include "../../base/IDrawable.h"

%include "../../base/IDrawTarget.h"
%include "../../base/IInputManager.h"


%include "../../base/ITimer.h"
%include "../../base/Key.h"

%feature("director") Sprite;
%include "../../base/Sprite.h"

%include "../../base/TextureSheet.h"
%include "../../base/TextureGrid.h"
%include "../../base/types.h"

%feature("director") SFMLApp;
%include "../../impl/sfml/SFMLApp.h"

%feature("notabstract") SFMLDrawTarget;
%include "../../impl/sfml/SFMLDrawTarget.h"
%include "../../impl/sfml/SFMLInputManager.h"
%include "../../impl/sfml/SFMLTexture.h"
%include "../../impl/sfml/SFMLTextureLib.h"
%include "../../impl/sfml/SFMLTimer.h"

%include "../../math/Vector2.h"

%include "../../tile/Camera.h"
%include "../../tile/Edge.h"
%include "../../tile/Tile.h"
%include "../../tile/ITileMap.h"
%include "../../tile/TileMap.h"
%include "../../tile/TileMapLayer.h"
%include "../../tile/EdgeMap.h"
%include "../../tile/World.h"
%include "../../tile/WorldObject.h"
//%include "../../tile/IPhysical.h"
//%include "../../tile/Hotspot.h"

%template(TileTexArray) std::vector<const lite::ITexture*>;

%feature("director") TextString;
%include "../../base/TextString.h"
