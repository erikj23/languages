
# parenthesis empty becuase we are creating the class from scratch
class dog():
    # docstring
    """simple dog class"""

    def __init__(self, name:str, age:int) -> None:
        """init name and age attributes"""
        self.name = name
        self.age = age
    
    def sit(self) -> None:
        """simulate sitting"""
        print("{} is now sitting. wowAF!".format(self.name.title()))
    
    def roll_over(self) -> None:
        """simulate rolling over"""
        print("{} rolled over. zoinks!".format(self.name.title()))

if __name__ == "__main__":
    rufus = dog("noob", 2)
    rufus.sit()
    rufus.roll_over()
