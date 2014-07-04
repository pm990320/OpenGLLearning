from direct.showbase.ShowBase import ShowBase


class MyApp(ShowBase):
    def __init__(self):
        ShowBase.__init__(self)
        
        self.cup = self.loader.loadModel("/c/Users/Patrick/Documents/monkey.egg")
        self.cup.reparentTo(self.render)
        self.cup.setScale(2, 2, 2)
        self.cup.setPos(0, -40, 2)
        self.cup.setColor(1, 0, 0)

app = MyApp()
app.run()