#!/usr/bin/python
from random import randint

import lite
from lite import SFMLApp, SFMLDrawTarget, SFMLInputManager, SFMLTimer, SFMLTextureLib
from lite import Sprite

TILE_WIDTH = 16
TILE_HEIGHT = 16
TM_WIDTH = 200
TM_HEIGHT = 157
LAYER_COUNT = 2
SUBLAYER_COUNT = 2

class SFMLTestApp(SFMLApp):
    def __init__(self, *args):
        SFMLApp.__init__(self,*args)

    def init(self):
        SFMLApp.init(self)
        self.textures = SFMLTextureLib()
        self.textures.load("hell.png")
        self.sprite = Sprite(self.drawTarget(),self.textures.get("hell.png"))

        self.drawTarget().add_drawable(self.sprite)
        self.input().mapKey(lite.K_ESCAPE, "quit");
        self.input().mapKey(lite.K_q, "quit");
    
    def run(self):
        SFMLApp.run(self)

    def update(self, *args):
        SFMLApp.update(self,*args)
        if(self.input().button("quit").was_just_pressed()):
            self.quit()

def main():
    timer = SFMLTimer()
    target = SFMLDrawTarget(640,400, "Test lite Python bindings")
    input_man = SFMLInputManager(timer, target)
    app = SFMLTestApp(target, timer, input_man)
    app.init()
    app.run()
    del app

if __name__ == '__main__':
    main()
