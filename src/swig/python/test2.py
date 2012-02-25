#!/usr/bin/python2
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

class SineText(TextString):
    def text_yoffset_at(self, index):
        return min(-4, -6.0 - self.scalex()*6.0*cos(100*index + self.time/150.0)) + 4

class HypnoText(TextString):
    def text_xoffset_at(self, index):
        return self.scalex()*8.0*cos(100*index + self.time/150.0)

    def text_yoffset_at(self, index):
        return self.scaley()*16.0*sin(100*index + self.time/150.0)

    def text_scalex_at(self, index):
        return self.scalex()+0.3*cos(100*index + self.time/150.0)

    def text_scaley_at(self, index):
        return self.scaley()+0.3*cos(100*index + self.time/150.0)

    def text_rotation_at(self, index):
        return 30*cos(100*index + self.time/150.0)

    def text_color_at(self, index):
        r = 1.0 + 0.5*cos(100*index + self.time/150)
        g = 1.0 + 0.5*cos(100 + 100*index + self.time/150)
        b = 1.0 + 0.5*cos(200 + 100*index + self.time/150)
        return Color(r,g,b)

class ShadowText(TextString):
    def __init__(self, otherText, xoffset, yoffset, colorMul=None,
                    color=Color(0.,0.,0.), alpha=0.5):
        TextString.__init__(self, otherText)
        self.otherText = otherText
        self.xoffset = xoffset
        self.yoffset = yoffset
        self.color = color
        self.colorMul = colorMul
        self.alpha = alpha

    def text_xoffset_at(self, index):
        return self.otherText.text_xoffset_at(index) + self.xoffset

    def text_yoffset_at(self, index):
        return self.otherText.text_yoffset_at(index) + self.yoffset

    def text_scalex_at(self, index):
        return self.otherText.text_scalex_at(index)
    
    def text_scaley_at(self, index):
        return self.otherText.text_scaley_at(index)

    def text_rotation_at(self, index):
        return self.otherText.text_rotation_at(index)

    def text_color_at(self,index):
        if(self.colorMul is not None):
            c = self.otherText.text_color_at(index)
            return Color(1.0*c.r*self.colorMul,
                         1.0*c.g*self.colorMul,
                         1.0*c.b*self.colorMul, self.alpha)
        else:
            return Color(self.color.r,self.color.g,self.color.b,self.alpha)

class StaticShadowText(TextString):
    def __init__(self, otherText, xoffset, yoffset,
                 color=Color(0.,0.,0.),alpha=0.8):
        TextString.__init__(self, otherText)
        self.xoffset = xoffset
        self.yoffset = yoffset
        self.otherText = otherText
        self.color = color
        self.alpha = alpha

    def text_color_at(self, index):
        yoff = self.otherText.text_yoffset_at(index)
        alpha = self.alpha - (-yoff*0.08)
        return Color(self.color.r,
                     self.color.g,
                     self.color.b,
                     alpha)


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

        self.text_string = SineText(self.drawTarget(), self.font,
                        "This is a simple test.", 0,1, Vector2(80,64))

        self.text_string2 = HypnoText(self.drawTarget(), self.font,
                        "This is a HYPNOTIC test!", 0,1, Vector2(64,228))

        self.text_string_shadow = StaticShadowText(self.text_string,1,1)
        self.text_string2_shadow = ShadowText(self.text_string2,1,1)

        self.text_string.time = 0
        self.text_string_shadow.time = 0

        self.text_string2.time = 0
        self.text_string2_shadow.time = 0

        self.drawTarget().add_drawable(self.text_string_shadow)
        self.drawTarget().add_drawable(self.text_string)

        self.drawTarget().add_drawable(self.text_string2_shadow)
        self.drawTarget().add_drawable(self.text_string2)
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
        self.text_string2.time += 1.0*args[0]
        self.text_string2_shadow.time += 1.0*args[0]

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
