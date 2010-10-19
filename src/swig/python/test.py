from lite import K_ESCAPE
from lite import SFMLApp, SFMLDrawTarget, SFMLInputManager, SFMLTimer


class SFMLTestApp(SFMLApp):
    def __init__(self, *args):
        SFMLApp.__init__(self,*args)

    def init(self):
        SFMLApp.init(self)
        self.input().mapKey(K_ESCAPE, "quit")
        print("INITTING!")
    
    def run(self):
        print("RUNNING!")
        SFMLApp.run(self)

    # Sadly, this doesn't work:
    def update(self, *args):
        print("UPDATE!")
        SFMLApp.update(self,*args)
        if(self.input().button("quit").was_just_pressed()):
            print("QUIT")



timer = SFMLTimer()
target = SFMLDrawTarget(640,400, "Test lite Python bindings")
input_man = SFMLInputManager(timer, target)
app = SFMLTestApp(target, timer, input_man)
app.init()
app.run()
