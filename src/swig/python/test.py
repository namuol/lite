#!/usr/bin/python
from random import randint

import lite
from lite import Color, Vector2, TextureGrid
from lite import Tile, TileMap, TileMapLayer, EdgeMap, Camera, TileTexArray
from lite import SFMLApp, SFMLDrawTarget, SFMLInputManager, SFMLTimer, SFMLTextureLib
from lite import NEAREST, LINEAR

TILE_WIDTH = 16
TILE_HEIGHT = 16
TM_WIDTH = 200
TM_HEIGHT = 157
LAYER_COUNT = 2
SUBLAYER_COUNT = 2
CAM_SPEED = -5

SCR_W = 640
SCR_H = 400 

class SFMLTestApp(SFMLApp):
    def __init__(self, *args):
        SFMLApp.__init__(self,*args)
        self.textures = SFMLTextureLib()
        self.textures.load("hell.png")
        self.textures.load("edges.png")
        self.texgrid = TextureGrid(self.textures.get("hell.png"), TILE_WIDTH, TILE_HEIGHT)
        self.edgegrid = TextureGrid(self.textures.get("edges.png"), TILE_WIDTH, TILE_HEIGHT)

        self.tileMap = TileMap(TM_WIDTH, TM_HEIGHT, 
                              TILE_WIDTH, TILE_HEIGHT,
                              LAYER_COUNT, SUBLAYER_COUNT)
        self.cam = Camera(Vector2(0,0),SCR_W,SCR_H)

    def init(self):
        SFMLApp.init(self)

        self.input().mapKey(lite.K_ESCAPE, "quit")
        self.input().mapKey(lite.K_q, "quit")

        self.input().mapKey(lite.K_LEFT, "left")
        self.input().mapKey(lite.K_a, "left")

        self.input().mapKey(lite.K_RIGHT, "right")
        self.input().mapKey(lite.K_d, "right")

        self.input().mapKey(lite.K_UP, "up")
        self.input().mapKey(lite.K_w, "up")

        self.input().mapKey(lite.K_DOWN, "down")
        self.input().mapKey(lite.K_s, "down")

        self.input().mapKey(lite.K_e, "toggle_edges")
        self.input().mapKey(lite.K_1, "toggle_front")
        self.input().mapKey(lite.K_2, "toggle_back")

        self.input().mapKey(lite.K_m, "toggle_filtermode")
        
        textures = TileTexArray([None for x in range(LAYER_COUNT*SUBLAYER_COUNT)])
        for x in range(TM_WIDTH):
            for y in range(TM_HEIGHT):
                if randint(0,3) % 3:
                    for i in range(LAYER_COUNT*SUBLAYER_COUNT):
                        textures[i] = self.texgrid[randint(0,self.texgrid.size()-1)]
                    self.tileMap.set(x,y, Tile(LAYER_COUNT,SUBLAYER_COUNT,textures))


        self.back = TileMapLayer(self.drawTarget(), self.tileMap, self.cam, 0, -0.5, .5,Color(.3,.3,.3))
        self.front = TileMapLayer(self.drawTarget(), self.tileMap, self.cam, 1, 1, 1)
        self.edges = EdgeMap(self.tileMap, self.edgegrid[0],self.edgegrid[1],self.edgegrid[2],self.edgegrid[3])
        self.edgesLayer = TileMapLayer(self.drawTarget(), self.edges, self.cam,0,2.,1.,
                                        Color(1.,1.,1.,.75))

        self.drawTarget().add_drawable(self.front)
        self.drawTarget().add_drawable(self.back)
        self.drawTarget().add_drawable(self.edgesLayer)

    
    def run(self):
        SFMLApp.run(self)

    def update(self, *args):
        SFMLApp.update(self,*args)

        if(self.input().button("quit").was_just_pressed()):
            self.quit()

        if( self.input().button("toggle_edges").was_just_pressed() ):
            self.edgesLayer.visible(not self.edgesLayer.visible())

        if( self.input().button("toggle_front").was_just_pressed() ):
            self.front.visible(not self.front.visible())

        if( self.input().button("toggle_back").was_just_pressed() ):
            self.back.visible(not self.back.visible())

        if( self.input().button("toggle_filtermode").was_just_pressed() ):
            current = self.drawTarget().filterMode()
            if(current is NEAREST):
                self.drawTarget().filterMode(LINEAR)
            else:
                self.drawTarget().filterMode(NEAREST)


        cam_velocity = Vector2()

        if( self.input().button("left").is_pressed() ):
            cam_velocity.x = CAM_SPEED
        elif( self.input().button("right").is_pressed() ):
            cam_velocity.x = -CAM_SPEED

        if( self.input().button("up").is_pressed() ):
            cam_velocity.y = CAM_SPEED
        elif( self.input().button("down").is_pressed() ):
            cam_velocity.y = -CAM_SPEED
             
        self.cam.position(self.cam.realPosition() + cam_velocity)


def main():
    timer = SFMLTimer()
    target = SFMLDrawTarget(SCR_W,SCR_H, Color(0.2,0.,0.1), "Test lite Python bindings")
    input_man = SFMLInputManager(timer, target)
    app = SFMLTestApp(target, timer, input_man)
    app.init()
    app.run()
    del app

if __name__ == '__main__':
    main()
