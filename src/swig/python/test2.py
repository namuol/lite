#!/usr/bin/python
from random import randint
from math import sin, cos

import lite
from lite import SFMLApp, SFMLDrawTarget, SFMLInputManager, SFMLTimer, SFMLTextureLib
from lite import Sprite, Vector2, Color
from lite import TextureGrid, TextString

TILE_WIDTH = 16
TILE_HEIGHT = 16
FONT_WIDTH = 16
FONT_HEIGHT = 16
TM_WIDTH = 200
TM_HEIGHT = 157
LAYER_COUNT = 2
SUBLAYER_COUNT = 2

class ShakyText(TextString):
    #def text_xoffset_at(self, index):
    #    return self.scalex()*8.0*cos(100*index + self.time/150.0)

    def text_yoffset_at(self, index):
        return self.scaley()*3.0*sin(100*index + self.time/150.0)

    #def text_scalex_at(self, index):
    #    return self.scalex()+0.3*cos(100*index + self.time/150.0)

    #def text_scaley_at(self, index):
    #    return self.scaley()+0.3*cos(100*index + self.time/150.0)

    #def text_rotation_at(self, index):
    #    return 30*cos(100*index + self.time/150.0)

    def text_color_at(self, index):
        r = 1.0 + 0.5*cos(100*index + self.time/150)
        g = 1.0 + 0.5*cos(100 + 100*index + self.time/150)
        b = 1.0 + 0.5*cos(200 + 100*index + self.time/150)
        return Color(r,g,b)

class ShakyTextShadow(ShakyText):
    #def text_xoffset_at(self,index):
    #    return 1.0*self.scalex()

    #def text_xoffset_at(self,index):
    #    return 1.0*self.scaley()

    def text_yoffset_at(self,index):
        return self.scaley()*3

    def text_color_at(self,index):
        alpha = 0.75 + 0.3*sin(100*index + self.time/150)
        return Color(0.,0.,0.,alpha)

class SFMLTestApp(SFMLApp):
    def __init__(self, *args):
        SFMLApp.__init__(self,*args)

    def init(self):
        SFMLApp.init(self)
        self.textures = SFMLTextureLib()
        self.textures.load("hell.png")
        self.sprite = Sprite(self.drawTarget(),self.textures.get("hell.png"))
        self.textures.load("font.png")
        self.font = TextureGrid(self.textures.get("font.png"),
            FONT_WIDTH,FONT_HEIGHT)
        
        self.text_string = ShakyText(self.drawTarget(), self.font,
                        "This is a TEST!", 0,1, Vector2(32,32))

        self.text_string_shadow = ShakyTextShadow(self.drawTarget(), self.font,
                        "This is a TEST!", 0,0, Vector2(33,33))
        self.text_string.time = 0
        self.text_string_shadow.time = 0
        #self.drawTarget().add_drawable(self.sprite)
        self.drawTarget().add_drawable(self.text_string_shadow)
        self.drawTarget().add_drawable(self.text_string)
        self.input().mapKey(lite.K_ESCAPE, "quit");
        self.input().mapKey(lite.K_q, "quit");
    
    def run(self):
        SFMLApp.run(self)

    def update(self, *args):
        SFMLApp.update(self,*args)
        if(self.input().button("quit").was_just_pressed()):
            self.quit()
        self.text_string.time += 1.0*args[0]
        self.text_string_shadow.time += 1.0*args[0]

def main():
    timer = SFMLTimer()
    target = SFMLDrawTarget(640,400, Color(0.7,0.7,0.7),"Test lite Python bindings")
    input_man = SFMLInputManager(timer, target)
    app = SFMLTestApp(target, timer, input_man)
    app.init()
    app.run()
    del app

if __name__ == '__main__':
    main()
