%module lite
%{
#include "../../math/Rect.h"

#include "../../core/base/IUpdateable.h"
#include "../../core/base/App.h"
#include "../../core/base/Button.h"
#include "../../core/base/IDrawable.h"
#include "../../core/base/IDrawTarget.h"
#include "../../core/base/IInputManager.h"
#include "../../core/base/ITexture.h"
#include "../../core/base/ITimer.h"
#include "../../core/base/Key.h"
#include "../../core/base/Sprite.h"
#include "../../core/base/TextureSheet.h"

#include "../../core/sfml/SFMLApp.h"
#include "../../core/sfml/SFMLDrawTarget.h"
#include "../../core/sfml/SFMLInputManager.h"
#include "../../core/sfml/SFMLTexture.h"
#include "../../core/sfml/SFMLTextureLib.h"
#include "../../core/sfml/SFMLTimer.h"
%}

%include "std_list.i"
%include "std_map.i"
%include "std_string.i"
%include "std_vector.i"

%include "../../math/Rect.h"

%include "../../core/base/IUpdateable.h"
%include "../../core/base/App.h"
%include "../../core/base/Button.h"
%include "../../core/base/IDrawable.h"
%include "../../core/base/IDrawTarget.h"
%include "../../core/base/IInputManager.h"
%include "../../core/base/ITexture.h"
%include "../../core/base/ITimer.h"
%include "../../core/base/Key.h"
%include "../../core/base/Sprite.h"
%include "../../core/base/TextureSheet.h"

%include "../../core/sfml/SFMLApp.h"
%feature("notabstract") SFMLDrawTarget;
%include "../../core/sfml/SFMLDrawTarget.h"
%include "../../core/sfml/SFMLInputManager.h"
%include "../../core/sfml/SFMLTexture.h"
%include "../../core/sfml/SFMLTextureLib.h"
%include "../../core/sfml/SFMLTimer.h"
